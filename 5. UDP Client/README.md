# Experiment 5 – Socket Programming: UDP Client

## Aim
Socket programming for transport layer packets (UDP Client).

## Theory
The **UDP client** is an active sender in a connectionless architecture. Because UDP keeps no persistent connection, the client can transmit datagrams immediately once the destination IP and port are known.

### UDP client execution steps
1. **socket()** – Create a datagram socket using `AF_INET` and `SOCK_DGRAM`.
2. **Addressing setup** – Fill a `sockaddr_in` with the server's IP and port.
3. **sendto()** – Send data directly; no `connect()` is needed.
4. **recvfrom()** – Optionally wait for the server's reply.
5. **close()** – Close the client socket.

## Tools Required
- Linux (Ubuntu), GCC compiler, vim/nano



## Compile and Run
Start the UDP server (Experiment 4) first, then:
```bash
vim client_udp_219.c
gcc client_udp_219.c -o client
./client
```

## Output
```
$ ./client
Enter message: hello
Server Response: Hello from UDP Server
$ ./client
Enter message: Arya Khandekar 219
Server Response: Hello from UDP Server
```

## Conclusion
The UDP client socket was successfully constructed at the Transport Layer. Using `SOCK_DGRAM` and `sendto()`, the client demonstrated connectionless communication by sending datagrams directly to the server without a TCP-style handshake.
