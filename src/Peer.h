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

#ifndef PEER_H_
#define PEER_H_


#include <omnetpp.h>
#include "peerRegister_m.h"
#include "streamRegReq_m.h"
#include "streamResponse_m.h"
#include <vector>
#include <cstringtokenizer.h>
#include "kinds.h"

using namespace std;

const int TYPE=2;

class Peer : public cSimpleModule {
public:
  map <int, vector <int>  > retransmissionList;

  Peer();
  virtual ~Peer();
  virtual void initialize(int stage);
  virtual int numInitStages() const;
  virtual void handleMessage(cMessage *message);
  void streamVideo(cMessage *msg);
  void receiveVideo(cMessage *message);
  void handleStreamResponse(cMessage *message);
  void requestStream(int peerId, int stream);
  void setSuperPeers();
  int count;
  vector <int> superPeers;


 private:
  int getNearestSuperPeer(int id);
  void kickProvider(int stream);
  void reduceLoad(int stream, int childs);
};

#endif /* PEER_H_ */
