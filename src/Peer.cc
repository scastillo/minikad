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
    int flow = par("flujo_brindado");
    if (flow != 0){
      FlowRegReq *msg = new FlowRegReq("flowReg",FLOW_REGISTER);
      msg -> setDest(1);
      msg -> setSource(id);
      msg -> setFlow(flow);
      send(msg,"gate$o");
    }
  }else if (stage == 2){
    int flow_req = par("flujo_requerido");
    if (flow_req != 0){
      FlowRegReq *msg = new FlowRegReq("flowReq",FLOW_REQUEST);
      int id = par("id");
      msg -> setDest(1);
      msg -> setSource(id);
      msg -> setFlow(flow_req);
      send(msg,"gate$o");
    }
  }
}

void Peer::handleMessage(cMessage *msg){

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
