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

simple Peer
{
   parameters:
      int id;
      string superPeers; //List with ids of superpeers
      // id del flujo, 0 es no hace accion
      int flujo_brindado= default(0);
      // requiere flujo con id.
      int flujo_requerido = default(0);
      int retardo_flujo = default(0);
      @display("i=device/pc");
    gates:
        inout gate;
}


