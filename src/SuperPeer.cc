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
    EV << " \nProvider " << *it << "  Load: " << load << " \n ";
    if ( load < minor_load ){
      best_provider = *it;
      minor_load = load;
    }

  }
  EV << "\n\n\n\n Best provider " << best_provider << " \n\n\n\n";
  return best_provider;
}
void SuperPeer::streamRequestHandler(cMessage *message){
  StreamRegReq *msg = check_and_cast<StreamRegReq *>(message);
  int source = msg -> getSource();
  int stream = msg -> getStream();
  int provider = selectBestProvider(stream);
  if (provider >0 ){
    StreamResponse *response = new StreamResponse("streamResponse",STREAM_RESPONSE);
   response -> setProvider(provider);
   response -> setDest(source);
   response -> setStream(stream);

   peerLoad[provider] ++;
   //Notifica a los otros sp sobre la nueva carga del Peer - provider.
   for(vector<int>::iterator it = superPeers.begin(); it != superPeers.end(); it++){
    int id = *it;
    int my_id = par("id");
    if (my_id != id ){
      StreamRegReq *msg = new StreamRegReq("increasingLoad",INCREASE_LOAD);
      msg -> setDest(id);
      msg -> setSource(provider);
      msg -> setStream(stream);
      msg -> setExtra(1);
      send(msg,"gate$o");
    }
   }
   streamProviders[stream].push_back(source);
   stringstream ss ;
   ss << "carga en el provedor " << provider << " es " << peerLoad[provider];
   EV << "\n\n\n carga en el provedor " << provider << " es " << peerLoad[provider] << "\n\n\n\n";
   bubble(ss.str().c_str());
   send(response, "gate$o");
  }
}
void SuperPeer::kickProvider(cMessage *message){
  StreamRegReq *msg = check_and_cast<StreamRegReq *>(message);
  int peer_to_kick = msg -> getSource();
  int stream = msg -> getStream();

  EV << "Kicking peer: " << peer_to_kick << "\n\n";
  EV << "streamProviders[" << stream << "] = [";
  for( vector<int>::iterator it = streamProviders[stream].begin(); it != streamProviders[stream].end(); it++ ){
    EV << "" << *it << ",";
  }
  EV << "]\n\n\n";

  for( vector<int>::iterator it = streamProviders[stream].begin(); it != streamProviders[stream].end(); it++ ){
    int provider = *it;
    vector<int>::iterator provider_index = it;
    if(provider == peer_to_kick){
      EV << "\n\n ** Ready to kick!... provider: " << provider << ", in index " << *(provider_index) << "\n\n\n\n";
      streamProviders[stream].erase(provider_index);
      EV << "\n\n ** Oh yeah!... provider: " << provider << ", kicked from provider of stream " << stream << "\n\n\n\n";
      break;
    }else{
      EV << "provider =" << provider << ". oh you luck boy...Not kicking you." << "\n\n\n";
    }
  }

  EV << "streamProviders[" << stream << "] = [";
  for( vector<int>::iterator it = streamProviders[stream].begin(); it != streamProviders[stream].end(); it++ ){
    EV << "" << *it << ",";
  }
  EV << "]\n\n\n";
}
void SuperPeer::reduceLoad(cMessage *message){
  StreamRegReq *msg = check_and_cast<StreamRegReq *>(message);
  int peer = msg -> getSource();
  int by   = msg -> getExtra();
  EV << "\n\nLoad for peer: " << peer  << " : " << peerLoad[peer] << "  reducing by: " << by;
  peerLoad[peer] -= by;
  EV << "\n\nNew Load for peer: " << peer  << " : " << peerLoad[peer] << " \n" ;
  if (peerLoad[peer] < 0 ){
    peerLoad[peer] = 0;
  }
  bool fromSP = msg -> getFromSP();
  if (!fromSP){
    for(vector<int>::iterator it = superPeers.begin(); it != superPeers.end(); it++){
      int id = *it;
      int my_id = par("id");
      if (my_id != id ){
        StreamRegReq *copy = msg->dup();
        copy -> setDest(id);
        copy -> setFromSP(true);
        send(copy,"gate$o");
      }
    }
  }
}

void SuperPeer::increaseLoad(cMessage *message){
  StreamRegReq *msg = check_and_cast<StreamRegReq *>(message);
  int peer = msg -> getSource();
  int by = msg -> getExtra();
  stringstream ss ;
  ss << "Incrementando el proveedor " << peer << " en " << by;
  bubble(ss.str().c_str());
  EV << "\n\nLoad for peer: " << peer  << " : " << peerLoad[peer] << "  increasing by: " << by;
  PeersLoadMap::iterator val = peerLoad.find(peer);
  if ( val == peerLoad.end() ){
    peerLoad[peer] = 0;
  }
  peerLoad[peer] += by ;
  EV << "\n\nNew Load for peer: " << peer  << " : " << peerLoad[peer] << " \n" ;
}

void SuperPeer::initialize(int stage){
  if (stage == 0){
    setSuperPeers();
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
  }else if( messageType == KICK_PEER){
    bubble("kickPeer !!!");
    kickProvider(msg);
  }else if( messageType == REDUCE_LOAD){
    bubble("reduce load  !!!!");
    reduceLoad(msg);
  }else if(messageType == INCREASE_LOAD){
    increaseLoad(msg);
  }
}

void SuperPeer::setSuperPeers (){
  const char *spList = par("superPeers").stringValue();
  superPeers = cStringTokenizer(spList).asIntVector();
}
