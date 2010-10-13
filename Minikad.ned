package oversim.overlay.minikad;

// import BaseOverlay
import oversim.common.BaseOverlay;

simple Minikad extends BaseOverlay
{
    parameters:
        @class(Minikad);
        bool enableDrops;       // do we enable random packet drops for testing?
        double dropChance;      // chance that we drop a packet
}
