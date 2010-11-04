import Peer;
import SuperPeer;
import Cloud;

network Minikad
{
    types:
        channel Channel extends ned.DelayChannel
        {
            delay = 100ms;
        }

    submodules:
        cloud: Cloud;
        sp1: SuperPeer;
        sp2: SuperPeer;
        sp3: SuperPeer;
        peer1: Peer ;
        peer2: Peer ;
        peer3: Peer ;
        peer4: Peer ;

    connections:
        sp1.gate <--> Channel <--> cloud.gate++;
        sp2.gate <--> Channel <--> cloud.gate++;
        sp3.gate <--> Channel <--> cloud.gate++;
        peer1.gate <--> Channel <--> cloud.gate++;
        peer2.gate <--> Channel <--> cloud.gate++;
        peer3.gate <--> Channel <--> cloud.gate++;
        peer4.gate <--> Channel <--> cloud.gate++;
}