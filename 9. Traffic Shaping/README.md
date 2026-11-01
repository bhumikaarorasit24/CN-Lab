# Experiment 9 – Traffic Shaping Algorithms (Leaky Bucket & Token Bucket)

## Aim
Simulation of the Leaky Bucket and Token Bucket traffic shaping algorithms using C.

## Objective
- Understand traffic shaping in congestion control.
- Implement the **Leaky Bucket**, which smooths bursty traffic to a fixed output rate.
- Implement the **Token Bucket**, which allows controlled bursts using tokens.

## Tools Required
- Linux (Ubuntu), GCC compiler, vim/nano

---

## Part A: Leaky Bucket Algorithm
**Input:** bucket capacity `B`, outgoing rate `R`, number of time units `N`, incoming packets `P[i]` per time unit.

**Algorithm**
1. Initialize `stored = 0`.
2. For each time unit `i = 1..N`:
   - Read incoming packets `P[i]`.
   - If `stored + P[i] > B`: drop the overflow `(stored + P[i] − B)` and set `stored = B`; else `stored += P[i]`.
   - If `stored <= R`: send all and set `stored = 0`; else send `R` and `stored -= R`.
   - Print packets sent and packets left in the bucket.
3. After all time units, keep sending `R` packets per step until `stored = 0`.


```bash
vim exp9_219.c
gcc exp9_219.c -o exp9_219
./exp9_219
```

**Output**
```
$ ./exp9_279
Leaky Bucket Algorithm Simulation
Enter bucket size (capacity): 10
Enter outgoing rate: 3
Enter number of packets (time units): 3

Time unit 1:
Enter number of incoming packets: 4
Packets sent: 3
Packets remaining in bucket: 1

Time unit 2:
Enter number of incoming packets: 3
Packets sent: 3
Packets remaining in bucket: 1

Time unit 3:
Enter number of incoming packets: 1
Packets sent: 2
Packets remaining in bucket: 0

Simulation complete.
```

---

## Part B: Token Bucket Algorithm
**Input:** bucket capacity `B` (max tokens), token rate `R`, number of time units `N`, packets to send `P[i]`.

**Algorithm**
1. Initialize `tokens = 0`.
2. For each time unit `i = 1..N`:
   - `tokens += R`; if `tokens > B`, set `tokens = B`.
   - Read packets to send `P[i]`.
   - If `tokens >= P[i]`: send `P[i]`, `tokens -= P[i]`.
   - Else: send only `tokens` packets, drop `P[i] − tokens`, set `tokens = 0`.
   - Print packets sent, packets dropped and tokens left.



```bash
vim exp9_2_219.c
gcc exp9_2_219.c -o exp9_2_219
./exp9_2_219
```

**Output**
```
$ ./exp9_2_219
Token Bucket Algorithm Simulation
Enter bucket size (capacity): 10
Enter token generation rate: 4
Enter number of packets (time units): 3

Time unit 1:
Enter number of packets to send: 3
Packets sent: 3
Tokens left: 1

Time unit 2:
Enter number of packets to send: 3
Packets sent: 3
Tokens left: 2

Time unit 3:
Enter number of packets to send: 9
Only 6 tokens available, packets sent: 6, packets dropped: 3
Tokens left: 0

Simulation complete.
```

---

## Observation Table
| Step | Command / Action | Observation |
|---|---|---|
| 1 | Leaky Bucket: size 10, rate 3, 3 time units; incoming 4, 3, 1 | Packets sent 3, 3, 2; remaining in bucket 1, 1, 0 |
| 2 | Token Bucket: size 10, token rate 4, 3 time units; packets 3, 3, 9 | Packets sent 3, 3, 6; tokens left 1, 2, 0 |
| 3 | Token Bucket, time unit 3 (9 packets, only 6 tokens) | 6 packets sent, 3 packets dropped |

## Result
- Successfully simulated the Leaky Bucket algorithm and observed a fixed output rate.
- Successfully simulated the Token Bucket algorithm and observed bursts handled using tokens.

## Conclusion
- Leaky Bucket keeps a fixed outflow rate and drops excess packets beyond the bucket capacity.
- Token Bucket allows bursty traffic as long as tokens are available; excess packets are dropped.
