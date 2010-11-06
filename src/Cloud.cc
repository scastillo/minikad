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

#include "Cloud.h"

Define_Module(Cloud);
Cloud::Cloud() {
	// TODO Auto-generated constructor stub

}

Cloud::~Cloud() {
	// TODO Auto-generated destructor stub
}

int Cloud::numInitStages() const {
  return 4;
}

void Cloud::initialize(int stage){
}

int Cloud::superPeerResolver(int id){
  return superPeers[id];
};
int Cloud::peerResolver(int id){
  return peers[id];
};

void Cloud::handleMessage(cMessage *msg){
  short messageType = msg -> getKind();

  if (messageType == PEER_REGISTER ){

    PeerRegister *peerInfo = check_and_cast<PeerRegister *>(msg);
    int ip = (peerInfo -> getArrivalGate()) -> getIndex();
    int id = peerInfo -> getId();
    int type = peerInfo -> getType();
    if ( type == SUPER_PEER ){
      superPeers[id] = ip;
    }else if ( type == PEER){
      peers[id] = ip ;
    }

  }else if(messageType == STREAM_REGISTER || messageType == STREAM_REQUEST ){

    StreamRegReq *msgRegReq = check_and_cast<StreamRegReq *>(msg);
    int dest = msgRegReq -> getDest();
    EV << "\n\n\n\n destino cloud: "<< dest <<"  \n\n\n\n";
    int ip = superPeerResolver(dest);
    send(msgRegReq,"gate$o",ip);

  }else if(messageType == VIDEO ){
    bubble("Video Arrived!!!");
  }else if(messageType == END_VIDEO ){
    bubble("End VIDEO!!!");
  }else if(messageType == STREAM_RESPONSE ){
    bubble("StreamResponse!!!!!");
    StreamResponse *response = check_and_cast<StreamResponse *>(msg);
    int dest = response -> getDest();
    int stream = response -> getStream();
    int ip = peerResolver(dest);
    EV << "\n\n\n\n\n STREAM_RESPONSE con destion " << dest << " Y flujo " << stream <<" \n\n\n\n\n" ;
    send(response,"gate$o",ip);
  }else if(messageType == TEST ){
    bubble("No deberia haber llegado video arrived todavia!!!");
  }
}
