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
    if ( type == SUPER_PEER ){ // 1 que es un superPeer
      superPeers[id] = ip;
      EV << "\n\n\n\n Register superpeer con id "<< id <<"  \n\n\n\n";
    }else if ( type == PEER){
      peers[id] = ip ;
      EV << "\n\n\n\n Register peer con id "<< id <<"  \n\n\n\n";
    }
  }else if(messageType == FLOW_REGISTER || messageType == FLOW_REQUEST ){
    FlowRegReq *msgRegReq = check_and_cast<FlowRegReq *>(msg);
    int dest = msgRegReq -> getDest();
    int ip = superPeerResolver(dest);
    EV << "\n\n\n\n RegReq "<< ip <<"  \n\n\n\n";
    send(msgRegReq,"gate$o",ip);
  }
}
    // map<int, int>::const_iterator iter;
    // for (iter=superPeers.begin(); iter != superPeers.end(); ++iter) {
    //   EV << "\n\n\n SuperPeer info:  id "<< iter->first<< " direccion "<< iter->second  <<"\n\n\n\n";
    // }
    // map<int, int>::const_iterator iter2;
    // for (iter2=peers.begin(); iter2 != peers.end(); ++iter2) {
    //   EV << "\n\n\n Peer info:  id "<< iter2->first<< " direccion "<< iter2->second  <<"\n\n\n\n";
    // }

    // short initConfigType = 2;
    // int numberOfSp = superPeers.size();
    // EV << "\n\n\n\n Rquest SPS! " << numberOfSp << " \n\n\n\n";
    // InitConfig *config = new InitConfig("initConfig ",initConfigType);
    // config -> setSpIdsArraySize(numberOfSp );

    // map<int, int>::const_iterator iter;
    // int k = 0;
    // for (iter=superPeers.begin(); iter != superPeers.end(); ++iter) {
    //   EV << "\n\n\n SuperPeer i  nfo:  id "<< iter->first<< " direccion "<< iter->second  <<"\n\n\n\n";
    //   config->setSpIds(k,iter->first);
    //   k++;
    // }
    // int ip = (msg -> getArrivalGate()) -> getIndex();
