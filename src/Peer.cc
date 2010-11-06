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
      msg -> setDest(1);
      msg -> setSource(id);
      msg -> setStream(stream_req);
      send(msg,"gate$o");
    }
  }else if(stage == 3){
    cMessage *msg = new cMessage("testPacketx",TEST);
    send(msg,"gate$o");
  }
}

void Peer::handleMessage(cMessage *msg){

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
  return nearest_distance;
}

  // if (msgType == 2 ){ // InitConfigType

  //   // InitConfig *config = check_and_cast<InitConfig *>(msg);
  //   // int size = config -> getSpIdsArraySize();
  //   // EV << "\n\n\n\n InitConfig Arrived!  " << size <<" \n\n\n\n";
  //   // for(int k=0; k < size ; k++ ){
  //   //   int id = config -> getSpIds(k);
  //   //   superPeers.push_back(id);
  //   //   bubble("pushed");
  //   // }

  //   // for( vector<int>::iterator it = superPeers.begin(); it != superPeers.end(); it++ ){
  //   //   EV << " \n\n\n\n\nID en peer " <<  *it << "  \n\n\n\n\n ";
  //   // }
  // }


//sendStream
// message for stream handling
void Peer::streamVideo(cMessage *message){
  int id = par("id");
  int stream  = 2;
  int dest = 1;
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
}
void Peer::receiveVideo(cMessage *message){}
void Peer::kickProvider(int stream){}
void Peer::reduceLoad(int stream){}
