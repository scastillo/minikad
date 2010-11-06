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

#include "SuperPeer.h"
Define_Module(SuperPeer);

SuperPeer::SuperPeer() {
	// TODO Auto-generated constructor stub

}

SuperPeer::~SuperPeer() {
	// TODO Auto-generated destructor stub
}

int SuperPeer::numInitStages() const {
  return 4;
}

void SuperPeer::registerStream(cMessage *message){
  StreamRegReq *msg = check_and_cast<StreamRegReq *>(message);
  int source = msg -> getSource();
  int stream = msg -> getStream();
  streamProviders[stream].push_back(source);
  PeersLoadMap::iterator val = peerLoad.find(source);
  if ( val == peerLoad.end() ){
    peerLoad[source] = 0;
  }
  for( StreamProvidersMap::iterator it = streamProviders.begin(); it != streamProviders.end(); it++ ){
    EV << " \n\n\n\n Stream Registrado  " <<  it->first << " con peers:  \n ";
    for( vector<int>::iterator it2 = (it->second).begin(); it2 != (it->second).end(); it2++ ){
      int pp = *it2;
      EV << "  " <<  pp << "  ";
    }
  }
}
int SuperPeer::selectBestProvider(int stream){

  vector<int> providers = streamProviders[stream];

  int best_provider = providers[0];
  int minor_load = peerLoad[best_provider];
  for( vector<int>::iterator it = providers.begin(); it != providers.end(); it++ ){
    int load = peerLoad[*it];
    if ( load < minor_load ){
      best_provider = *it;
      minor_load = load;
    }
  }
}
void SuperPeer::streamRequestHandler(cMessage *message){
  StreamRegReq *msg = check_and_cast<StreamRegReq *>(message);
  int source = msg -> getSource();
  int stream = msg -> getStream();
  int provider = selectBestProvider(stream);
  if (provider >0 ){
    StreamResponse* msg = new StreamResponse("streamResponse",STREAM_RESPONSE);
    msg -> setProvider(provider);
    msg -> setDest(source);
    msg -> setStream(source);
    send(msg, "gate$o");
  }
}
void SuperPeer::kickProvider(cMessage *message){}
void SuperPeer::reduceLoad(cMessage *message){}

void SuperPeer::initialize(int stage){
  if (stage == 0){
    PeerRegister *peerInfo = new PeerRegister("peerInfo", PEER_REGISTER);
    int id = par("id");
    peerInfo -> setId(id);
    peerInfo -> setType(SUPER_PEER);
    send(peerInfo, "gate$o");
  }else if (stage == 1){
  }else if (stage == 2){
  }
}


void SuperPeer::handleMessage(cMessage *msg){
  short messageType = msg -> getKind();
  if( messageType == STREAM_REGISTER ){
    bubble("Registro de nuevo flujo :D!");
    registerStream(msg);
  }else if( messageType == STREAM_REQUEST ){
    bubble("Alguien requirio flujo");
    streamRequestHandler(msg);
  }
}

