#ifndef _MINIKADPEER_
#define _MINIKADPEER__

#include <omnetpp.h>
#include <NodeHandle.h>
#include "BaseOverlay.h"

class MiniKadPeer : public BaseOverlay
{
      public:
        // OMNeT++
        virtual ~MiniKadPeer();
        virtual void initializeOverlay(int stage);
        virtual void finishOverlay();
        virtual void handleUDPMessage(BaseOverlayMessage* msg);
        virtual void handleTimerEvent(cMessage* msg);

        virtual bool handleRpcCall(BaseCallMessage* msg);
        virtual void handleRpcResponse(BaseResponseMessage *msg,
                                       cPolymorphic* context,
                                       int rpcId, simtime_t rtt);
        virtual void handleRpcTimeout(BaseCallMessage *msg,
                                      const TransportAddress &dest,
                                      cPolymorphic* context, int rpcId,
                                      const OverlayKey &destKey);


};
#endif
