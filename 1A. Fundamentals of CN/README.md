# Experiment 1A – Fundamentals of Computer Networking

## Aim
To study the fundamental elements of Computer Networking, including Network Topologies, Transmission Media, Networking Devices, and the RJ-45 connector along with its color coding schemes.

## Theory

### A. Network Topologies
A network topology defines how computers, cables, and other components are arranged and connected in a network.

| Topology | Description | Advantages | Disadvantages |
|---|---|---|---|
| Bus | All nodes connected to a single central cable (backbone) | Easy to set up, minimal cabling | If the backbone fails, the entire network goes down |
| Star | All devices connect individually to a central Hub/Switch | Easy to troubleshoot; one cable failure doesn't affect others | If the central device fails, the whole network is unreachable |
| Ring | Each device connects to two neighbours, forming a circular path | Equal access; no collisions as data moves in one direction | A single broken connection disables the network |
| Mesh | Every device has a point-to-point link to every other device | Highly reliable and secure; dedicated links | High cabling cost, complex installation |
| Tree | Hierarchical combination of Star and Bus topologies | Highly scalable, easy to manage in large organizations | Heavy reliance on the main backbone cable |
| Hybrid | Combination of two or more topologies (e.g., Star-Ring) | Flexible and scalable | Complex structure, higher maintenance cost |


### B. Transmission Media
Transmission media carry information from a transmitter to a receiver using physical (guided) paths.

1. **Coaxial Cable** – Solid copper conductor wrapped in insulation, a braided metal shield and an outer jacket. Moderate bandwidth, resistant to electrical interference. Used in cable TV networks and older LAN setups.
2. **Twisted Pair Cable** – Pairs of insulated copper wires twisted together to reduce electromagnetic interference. Available as Shielded (STP) and Unshielded (UTP); low cost. Used in standard Ethernet LANs.
3. **Optical Fiber** – Glass or plastic core that transmits data as light pulses. High bandwidth, extremely fast, immune to EMI. Used in Internet backbones and long-distance telecom.



### C. Networking Devices
- **Router** – Network Layer (Layer 3) device that routes packets between networks using IP addresses.
- **Hub** – Physical Layer (Layer 1) device that broadcasts incoming data to every port, causing collisions.
- **Switch** – Data Link Layer (Layer 2) device that forwards frames to the intended device using MAC addresses.
- **Gateway** – Device that acts as a translation bridge between two networks running different protocols.
- **Modem** – Converts digital signals to analog for transmission over phone/cable lines, and vice versa.
- **NIC (Network Interface Card)** – Hardware that provides a physical (MAC address) interface to connect a computer to a network.



### D. RJ-45 Connector & Color Coding
An **RJ-45 (Registered Jack 45)** is an 8-pin connector used to terminate Ethernet cables (Cat5e, Cat6).

| Pin | T568A | T568B |
|---|---|---|
| 1 | White/Green | White/Orange |
| 2 | Green | Orange |
| 3 | White/Orange | White/Green |
| 4 | Blue | Blue |
| 5 | White/Blue | White/Blue |
| 6 | Orange | Green |
| 7 | White/Brown | White/Brown |
| 8 | Brown | Brown |



## Conclusion
Through this study, the fundamental components of computer networking, including topologies, transmission media, layer-specific hardware devices, and RJ-45 cabling specifications, were analysed and documented.
