#include "MiniKadPeer.h"

#include <GlobalStatistics.h>
#include <GlobalNodeListAccess.h>

using namespace std;

Define_Module(MiniKadPeer);

void MiniKadPeer::initializeOverlay(int stage)
{
      // because of IPAddressResolver, we need to wait until interfaces are registered,
    // address auto-assignment takes place etc.
    if(stage != MIN_STAGE_OVERLAY) return;

    thisNode.setKey( OverlayKey::random() );
    WATCH( "Initializing Peer" );
}

void MiniKadPeer::handleTimerEvent(cMessage* msg)
{
  WATCH( "Timer" );
}

void MiniKadPeer::handleUDPMessage(BaseOverlayMessage* msg)
{
  WATCH( "UPDMessage" );
}
bool MiniKadPeer::handleRpcCall(BaseCallMessage* msg)
{
  WATCH( "RPCCall" );
  return true;
}

void MiniKadPeer::handleRpcResponse(BaseResponseMessage *msg,
                                    cPolymorphic* context,
                                    int rpcId, simtime_t rtt)
{
  WATCH( "RPCResponse" );
}

void MiniKadPeer::handleRpcTimeout (BaseCallMessage *msg,
                                    const TransportAddress &dest,
                                    cPolymorphic* context, int rpcId,
                                    const OverlayKey &destKey)
{
  WATCH( "RPCTimeOut" );
}

void MiniKadPeer::finishOverlay()
{
   WATCH( "FinishOverlay" );
}
MiniKadPeer::~MiniKadPeer()
{
}
