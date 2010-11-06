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
        sp1: SuperPeer{
                id = 1;

        };
        sp2: SuperPeer{
              id = 2;
        };
        sp3: SuperPeer{
          id = 3;
        };
       peer1: Peer{
          id = 1;
          superPeers = "1 2 3";
          flujo_brindado = 1;
          flujo_requerido = 2;
        };
       peer2: Peer{
          id = 2;
          superPeers = "1 2 3";
          flujo_brindado = 2;
          flujo_requerido = 1;
        };
        peer3: Peer{
                id = 3;
                superPeers = "1 2 3";
                flujo_requerido = 2;
        };
        peer4: Peer{
          id = 4;
          superPeers = "1 2 3";
          flujo_requerido = 1;
        };

    connections:
        sp1.gate <--> Channel <--> cloud.gate++;
        sp2.gate <--> Channel <--> cloud.gate++;
        sp3.gate <--> Channel <--> cloud.gate++;
        peer1.gate <--> Channel <--> cloud.gate++;
        peer2.gate <--> Channel <--> cloud.gate++;
        peer3.gate <--> Channel <--> cloud.gate++;
        peer4.gate <--> Channel <--> cloud.gate++;
}