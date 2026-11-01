# Experiment 2 – Socket Programming: TCP Server

## Aim
Socket programming for transport layer packets (TCP Server).

## Theory
A **socket** is a software abstraction representing an endpoint of a two-way communication link between two programs on a network. It is uniquely identified by an **IP address** and a **port number**.

At the Transport Layer, **TCP (Transmission Control Protocol)** provides connection-oriented, reliable, ordered and error-checked data delivery. On the server side, TCP socket programming is a **Passive Open** process that waits for incoming connection requests.

### Server-side execution steps
1. **socket()** – Create an endpoint using `AF_INET` (IPv4) and `SOCK_STREAM` (TCP).
2. **bind()** – Bind the socket to a local IP address and port number.
3. **listen()** – Put the socket in passive listening state with a backlog queue.
4. **accept()** – Block until a client connects (TCP three-way handshake: SYN, SYN-ACK, ACK). Returns a *new dedicated socket descriptor* for that client.
5. **recv()/send()** – Exchange data reliably over the stream socket.
6. **close()** – Terminate the connection (TCP four-way termination) and release resources.

## Tools Required
- Linux (Ubuntu), GCC compiler, vim/nano

## Code
See [`server1219.c`](server1219.c)

## Compile and Run
```bash
hostname -I                      # note the server IP
vim server1219.c
gcc server1219.c -o server
./server
```
Run `./client` (Experiment 3) in a second terminal.

## Output
```
$ hostname -I
10.17.60.37 10.17.108.110
$ gcc server1219.c -o server
$ ./server
TCP Echo Server listening on port 10279...
Received: hello
Received: hiii
Received: Arya
```

## Conclusion
The TCP Server socket was successfully implemented at the Transport Layer. The passive open sequence (socket, bind, listen, accept) was executed, establishing a reliable, connection-oriented channel capable of processing incoming client data streams.
