//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

#include "Peer.h"

Define_Module(Peer);

Peer::Peer() {
	// TODO Auto-generated constructor stub

}

Peer::~Peer() {
	// TODO Auto-generated destructor stub
}

int Peer::numInitStages() const {
  return 4;
}

void Peer::setSuperPeers (){
  const char *spList = par("superPeers").stringValue();
  superPeers = cStringTokenizer(spList).asIntVector();

}

void Peer::initialize(int stage){
  int id = par("id");
  if (stage == 0){
    setSuperPeers();
    PeerRegister *peerInfo = new PeerRegister("peerInfo",PEER_REGISTER);
    peerInfo -> setId(id);
    peerInfo -> setType(PEER);
    send(peerInfo, "gate$o");
  }else if (stage == 1){
    int stream = par("flujo_brindado");
    if (stream != 0){
      StreamRegReq *msg = new StreamRegReq("streamReg",STREAM_REGISTER);
      int dest = getNearestSuperPeer(stream);
      EV << "\n\n\n\n requiere a destino en registro: "<< dest <<"  \n\n\n\n";
      msg -> setDest(dest);
      msg -> setSource(id);
      msg -> setStream(stream);
      send(msg,"gate$o");
    }
  }else if (stage == 2){
    int stream_req = par("flujo_requerido");
    if (stream_req != 0){
      StreamRegReq *msg = new StreamRegReq("streamReq",STREAM_REQUEST);
      int dest = getNearestSuperPeer(stream_req);
      EV << "\n\n\n\n requiere a destino: "<< dest <<"  \n\n\n\n";
      msg -> setDest(dest);
      msg -> setSource(id);
      msg -> setStream(stream_req);
      sendDelayed(msg,par("retardo_flujo"),"gate$o");
    }
  }else if(stage == 3){
    // cMessage *msg = new cMessage("testPacketx",TEST);
    // send(msg,"gate$o");
  }
}

void Peer::handleStreamResponse(cMessage *msg){
  EV << "\n\n\n\n\n llego al stream response \n\n\n\n\n\n\n";
  bubble("handle stream response !!!");
  StreamResponse *response = check_and_cast<StreamResponse *>(msg);
  int stream = response -> getStream();
  int provider = response -> getProvider();
  requestStream(provider, stream);
}
void Peer::handleMessage(cMessage *msg){
  short messageType = msg -> getKind();
  switch(messageType){
    case STREAM_RESPONSE:
      handleStreamResponse(msg);
      break;
    case STREAM_TRANSFER_REQUEST:
      streamVideo(msg);
      break;
    case VIDEO:
      receiveVideo(msg);
      break;
    case END_VIDEO:
      receiveVideo(msg);
      break;
    default: bubble("No se reconocio un mensaje");
      break;
  }
}

int Peer::getNearestSuperPeer(int id){
  EV << "\n\n\ngetting nearest SuperPeer to id=" << id;
  int nearest_sp = -1;
  int nearest_distance = 10000; // infinity :P more or less

  for(vector<int>::iterator it = superPeers.begin(); it != superPeers.end(); it++){
    int sp_id = *it;
    int distance;
    EV << "\n\n\nSP: " << sp_id << "\n\n\n";
    distance = id ^ sp_id;
    if(distance < nearest_distance){
      nearest_sp = sp_id;
      nearest_distance = distance;
    }
  }
  EV << "\n\n the nearest sp from the peer (" << id << ") is: " << nearest_sp << "\n\n\n";
  return nearest_sp;
}

//sendStream
// message for stream handling
void Peer::streamVideo(cMessage *message){
  int id = par("id");
  int my_stream = par("flujo_brindado");
  StreamRegReq *msgRegReq = check_and_cast<StreamRegReq *>(message);
  int dest = msgRegReq -> getSource();
  int stream = msgRegReq -> getStream();
  if (stream == my_stream){
    for (int i = 0; i < 8 ; i++ ){
      StreamRegReq *msg = new StreamRegReq("streamReq",VIDEO);
      msg -> setDest(dest);
      msg -> setSource(id);
      msg -> setStream(stream);
      sendDelayed(msg,500 * (i+1),"gate$o");
    }
    StreamRegReq *msg = new StreamRegReq("streamFinish",END_VIDEO);
    msg -> setDest(dest);
    msg -> setSource(id);
    msg -> setStream(stream);
    sendDelayed(msg,5000,"gate$o");
    reduceLoad(stream, 1);
  }else{
  //   //sino quiere decir que tengo que retransmitir un video.
    bubble("retransmitiendo");
    retransmissionList[stream].push_back(dest);
  }
}
void Peer::receiveVideo(cMessage *message){
  bubble("Recibio video Buum!!!");
  int id = par("id");
  StreamRegReq *msgRegReq = check_and_cast<StreamRegReq *>(message);
  int stream = msgRegReq -> getStream();
  int childs = retransmissionList[stream].size();
  if ( childs  > 0){
    int k = 1;
    for( vector<int>::iterator it = retransmissionList[stream].begin(); it != retransmissionList[stream].end(); it++ ){
      StreamRegReq *copy = msgRegReq->dup();
      copy -> setDest(*it);
      copy -> setSource(id);
      sendDelayed(copy,1000,"gate$o");
      k++;
    }
  }
  if ((message -> getKind()) == END_VIDEO ){
    kickProvider(stream);
    if (childs > 0 ){
      reduceLoad(stream, childs);
    }
  }
}
void Peer::kickProvider(int stream){
  int id = par("id");
  retransmissionList.erase(stream);
  StreamRegReq *msg = new StreamRegReq("kickingPeer",KICK_PEER);
  int dest = getNearestSuperPeer(stream);
  msg -> setDest(dest);
  msg -> setSource(id);
  msg -> setStream(stream);
  sendDelayed(msg,5010,"gate$o");
}

void Peer::reduceLoad(int stream, int childs){
  int id = par("id");
  StreamRegReq *msg = new StreamRegReq("reducingLoad",REDUCE_LOAD);
  int dest = getNearestSuperPeer(stream);
  msg -> setDest(dest);
  msg -> setSource(id);
  msg -> setStream(stream);
  msg -> setExtra(childs);
  sendDelayed(msg,5010,"gate$o");
}
void Peer::requestStream(int provider, int stream){
  int id = par("id");
  StreamRegReq *msg = new StreamRegReq("streamRequest",STREAM_TRANSFER_REQUEST);
  msg -> setDest(provider);
  msg -> setSource(id);
  msg -> setStream(stream);
  send(msg,"gate$o");
}
