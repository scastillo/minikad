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

#ifndef SUPERPEER_H_
#define SUPERPEER_H_

#include <omnetpp.h>
#include "peerRegister_m.h"
#include "streamRegReq_m.h"
#include "streamResponse_m.h"
#include "kinds.h"
#include <map>
#include <vector>

using namespace std;


const int TYPE=1;

class SuperPeer : public cSimpleModule {
public:
  typedef map<int, vector <int> > StreamProvidersMap;
  typedef map<int, int > PeersLoadMap;

  SuperPeer();
  virtual ~SuperPeer();
  virtual void initialize(int stage);
  virtual int numInitStages() const;
  virtual void handleMessage(cMessage *message);
  void registerStream(cMessage *message);
  int selectBestProvider(int stream);
  void streamRequestHandler(cMessage *message);
  void kickProvider(cMessage *message);
  void reduceLoad(cMessage *message);
  StreamProvidersMap streamProviders;
  PeersLoadMap peerLoad;
};

#endif /* SUPERPEER_H_ */


// El que recibe end es pateado
// El que envia un end se le reduce la carga
