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


void SuperPeer::initialize(int stage){
  if (stage == 0){
    PeerRegister *peerInfo = new PeerRegister("peerInfo", PEER_REGISTER);
    int id = par("id");
    peerInfo -> setId(id);
    peerInfo -> setType(SUPER_PEER);
    send(peerInfo, "gate$o");
  }
}


void SuperPeer::handleMessage(cMessage *msg){
}
