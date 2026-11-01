# Experiment 3 – Socket Programming: TCP Client

## Aim
Socket programming for transport layer packets (TCP Client).

## Theory
In a client-server architecture, the **client** is the active process that initiates communication with a passive server running on a known IP address and port.

At the Transport Layer, the TCP client performs an **Active Open**. TCP guarantees delivery using sequence numbers, acknowledgments and checksums over a virtual connection stream.

### Client-side execution steps
1. **socket()** – Create a socket with `AF_INET` and `SOCK_STREAM`.
2. **Server addressing** – Fill a `sockaddr_in` structure with the server's IP and port.
3. **connect()** – Triggers the **TCP three-way handshake**:
   - **SYN:** client sends a synchronization packet
   - **SYN-ACK:** server responds with synchronization + acknowledgment
   - **ACK:** client acknowledges, connection established
4. **send()/recv()** – Exchange data over the full-duplex stream.
5. **close()** – Gracefully close the connection and release kernel resources.

## Tools Required
- Linux (Ubuntu), GCC compiler, vim/nano

---

## Part A: TCP Client – Addition of Two Numbers
The client reads two integers, sends them to the server, and prints the sum returned by the server.

**Before running:** edit `inet_addr("10.17.60.51")` in the code and put the IP address of the server PC (from `hostname -I` on the server).



First verify connectivity with the server PC:
```bash
ping 10.17.60.51
```
Start the server (Experiment 2), then on the client PC:
```bash
vim client1219.c
gcc client1219.c -o client
./client
```

## Output
```
$ ping 10.17.60.51
PING 10.17.60.51 (10.17.60.51) 56(84) bytes of data.
64 bytes from 10.17.60.51: icmp_seq=1 ttl=64 time=0.380 ms
64 bytes from 10.17.60.51: icmp_seq=2 ttl=64 time=0.212 ms
64 bytes from 10.17.60.51: icmp_seq=3 ttl=64 time=0.214 ms
64 bytes from 10.17.60.51: icmp_seq=4 ttl=64 time=0.545 ms
64 bytes from 10.17.60.51: icmp_seq=5 ttl=64 time=0.087 ms
^C
--- 10.17.60.51 ping statistics ---
5 packets transmitted, 5 received, 0% packet loss, time 4101ms
rtt min/avg/max/mdev = 0.087/0.287/0.545/0.158 ms

$ vim client1219.c
$ gcc client1219.c -o client
$ ./client
Enter two numbers: 5 2
Server Response: Sum = 7
Enter two numbers: 3
4
Server Response: Sum = 7
Enter two numbers:
```


## Result
The client connected to the server using the server's IP address and port, sent two numbers, and received their sum computed by the server.

## Conclusion
The TCP Client socket was successfully constructed at the Transport Layer. Using the active open mechanism (socket, set server parameters, connect), the client established a connection with the server via the TCP three-way handshake and enabled reliable stream-based data transmission.
