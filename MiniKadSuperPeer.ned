package oversim.overlay.minikad;

import oversim.common.BaseOverlay;
import oversim.common.IOverlay;

simple MiniKadSuperPeer extends BaseOverlay
{
    parameters:
        @class(MiniKadSuperPeer);
        string identifier;
}

module OverlayMiniKadSuperPeer like IOverlay
{
    gates:
        input udpIn; // gate from the UDP layer
        output udpOut; // gate to the UDP layer
        input appIn; // gate from the application
        output appOut; // gate to the application

    submodules:
        miniKadSuperPeer: MiniKadSuperPeer;

    connections allowunconnected:
        udpIn --> miniKadSuperPeer.udpIn;
        udpOut <-- miniKadSuperPeer.udpOut;
        appIn --> miniKadSuperPeer.appIn;
        appOut <-- miniKadSuperPeer.appOut;
}

