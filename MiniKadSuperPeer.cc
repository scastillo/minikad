#include "MiniKadSuperPeer.h"

#include <GlobalStatistics.h>
#include <GlobalNodeListAccess.h>

using namespace std;

Define_Module(MiniKadSuperPeer);

void MiniKadSuperPeer::initializeOverlay(int stage)
{
      // because of IPAddressResolver, we need to wait until interfaces are registered,
    // address auto-assignment takes place etc.
    if(stage != MIN_STAGE_OVERLAY) return;

    thisNode.setKey( OverlayKey::random() );
    WATCH( "Initializing SuperPeer" );
}

void MiniKadSuperPeer::handleTimerEvent(cMessage* msg)
{
  WATCH( "Timer" );
}

void MiniKadSuperPeer::handleUDPMessage(BaseOverlayMessage* msg)
{
  WATCH( "UPDMessage" );
}
bool MiniKadSuperPeer::handleRpcCall(BaseCallMessage* msg)
{
  WATCH( "RPCCall" );
  return true;
}

void MiniKadSuperPeer::handleRpcResponse(BaseResponseMessage *msg,
                                    cPolymorphic* context,
                                    int rpcId, simtime_t rtt)
{
  WATCH( "RPCResponse" );
}

void MiniKadSuperPeer::handleRpcTimeout (BaseCallMessage *msg,
                                    const TransportAddress &dest,
                                    cPolymorphic* context, int rpcId,
                                    const OverlayKey &destKey)
{
  WATCH( "RPCTimeOut" );
}

void MiniKadSuperPeer::finishOverlay()
{
   WATCH( "FinishOverlay" );
}
MiniKadSuperPeer::~MiniKadSuperPeer()
{
}
