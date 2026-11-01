# Experiment 4 – Socket Programming: UDP Server

## Aim
Socket programming for transport layer packets (UDP Server).

## Theory
At the Transport Layer, **UDP (User Datagram Protocol)** is a connectionless, unreliable and lightweight protocol. Unlike TCP, it does not establish a virtual circuit or perform a three-way handshake. Each data unit is handled as an independent **datagram**.

A UDP server listens for incoming datagrams from any client without maintaining state or active connections.

### UDP server execution steps
1. **socket()** – Create a socket with `AF_INET` and `SOCK_DGRAM`.
2. **bind()** – Bind the socket to a local IP and port; this is the entry point for client datagrams.
3. **recvfrom()** – Block and wait for datagrams; captures the payload and the client's IP and port.
4. **sendto()** – Send a response to the client using the address captured during reception.
5. **close()** – Release the socket descriptor.

## Tools Required
- Linux (Ubuntu), GCC compiler, vim/nano



## Compile and Run
```bash
vim server_udp219.c
gcc server_udp219.c -o server
./server
```
Then run the UDP client (Experiment 5) in another terminal.

## Output
```
$ ./server
UDP Server is running on port 8080...
Message from Client: hello

$ ./server
UDP Server is running on port 8080...
Message from Client: Arya Khandekar 219
```

## Conclusion
The UDP Server socket was successfully implemented at the Transport Layer. Using `SOCK_DGRAM` with `recvfrom()` and `sendto()`, the server bound to its port and processed incoming connectionless datagrams without establishing a prior network handshake.
