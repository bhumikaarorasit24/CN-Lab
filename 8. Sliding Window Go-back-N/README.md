# Experiment 8 – Sliding Window Protocol (Go-Back-N)

## Aim
Simulation of the Sliding Window Protocol (Go-Back-N variant) using a C program.

## Objective
- Understand how the Sliding Window Protocol controls flow of frames between sender and receiver.
- Simulate the Go-Back-N ARQ variant using arrays and simple logic in C.
- Observe how the sender window slides forward when acknowledgments are received.

## Tools Required
- Linux (Ubuntu), GCC compiler, nano/vim

## Algorithm (Go-Back-N ARQ)
**Input:** total number of frames `N`, window size `W`.

**Sender**
1. Initialize `base = 0`, `next_seq_num = 0`.
2. While `base < N`:
   - While `next_seq_num < base + W` and `next_seq_num < N`: send frame `next_seq_num`, increment it.
   - Wait for ACK. If ACK for frame `base` arrives, increment `base`.
   - On timeout/error, retransmit all frames from `base` to `next_seq_num - 1`.
3. Repeat until `base >= N`.

**Receiver**
1. Initialize `expected_seq_num = 0`.
2. When a frame `seq_num` arrives:
   - If `seq_num == expected_seq_num`: accept it, send ACK, increment `expected_seq_num`.
   - Else: discard the frame and resend ACK for `expected_seq_num - 1`.



## Compile and Run
```bash
gcc sliding_window219.c -o sliding_window219
./sliding_window219
```
Enter the number of frames (max 50) and the window size. Enter `y` if all frames were received correctly (window slides forward) or `n` to simulate an error (sender resends from base).

## Output
```
$ gcc sliding_window219.c -o sliding_window219
$ ./sliding_window219
Sliding Window Protocol Simulation (Go-Back-N)
Enter number of frames to send (max 50): 5
Enter window size: 3

Sender window: [0] [1] [2]
Sending frames...
Sent frame: 0
Sent frame: 1
Sent frame: 2

Simulating receiver...
Received frame: 0, sending ACK: 1
Received frame: 1, sending ACK: 2
Received frame: 2, sending ACK: 3

Did all frames receive correctly? (y/n): y

Sender window: [3] [4]
Sending frames...
Sent frame: 3
Sent frame: 4

Simulating receiver...
Received frame: 3, sending ACK: 4
Received frame: 4, sending ACK: 5

Did all frames receive correctly? (y/n): y

All frames sent successfully!
```

## Observation Table
| Step | Command / Action | Observation |
|---|---|---|
| 1 | `gcc sliding_window219.c -o sliding_window219` | Program compiled successfully |
| 2 | `./sliding_window219` with 5 frames, window 3 | Window [0][1][2]; frames 0, 1, 2 sent |
| 3 | Receiver simulation | ACKs 1, 2, 3 sent for frames 0, 1, 2 |
| 4 | Input `y` | Window slid to [3][4]; frames 3, 4 sent and ACKed |
| 5 | Input `y` again | All frames sent successfully |

## Result
- Successfully simulated the Sliding Window Protocol (Go-Back-N) in C.
- Observed the sender window sliding forward as acknowledgments were received.

## Conclusion
- Go-Back-N lets the sender transmit multiple frames before waiting for ACKs.
- On an error, retransmission restarts from the frame where the error occurred.
- It is efficient for networks with few errors and long delays.
