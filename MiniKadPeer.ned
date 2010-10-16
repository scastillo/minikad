package oversim.overlay.minikad;

import oversim.common.BaseOverlay;
import oversim.common.IOverlay;

simple MiniKadPeer extends BaseOverlay
{
    parameters:
        @class(MiniKadPeer);
//        string identifier;
}

module OverlayMiniKadPeer like IOverlay
{
    gates:
        input udpIn; // gate from the UDP layer
        output udpOut; // gate to the UDP layer
        input appIn; // gate from the application
        output appOut; // gate to the application

    submodules:
        miniKadPeer: MiniKadPeer;

    connections allowunconnected:
        udpIn --> miniKadPeer.udpIn;
        udpOut <-- miniKadPeer.udpOut;
        appIn --> miniKadPeer.appIn;
        appOut <-- miniKadPeer.appOut;
}

