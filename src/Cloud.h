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

#ifndef CLOUD_H_
#define CLOUD_H_

#include <omnetpp.h>
#include "peerRegister_m.h"
#include "flowRegReq_m.h"
#include <exception>
#include <map>
#include "kinds.h"


using namespace std;

class Cloud : public cSimpleModule {
public:
	Cloud();
	virtual ~Cloud();
        virtual void initialize(int stage);
        virtual int numInitStages() const;
	virtual void handleMessage(cMessage *message);
      	int superPeerResolver(int id);
        int peerResolver(int id);
        map<int, int> superPeers; // dns por superPeers
        map<int, int> peers;
};

#endif /* CLOUD_H_ */
