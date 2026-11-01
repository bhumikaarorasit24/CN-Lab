# Experiment 10 – Distance Vector Routing Algorithm

## Aim
Simulation of the Distance Vector Routing algorithm to compute shortest paths using C.

## Objective
- Understand how routers share distance vectors to compute shortest paths.
- Implement the Distance Vector Routing algorithm in C.
- Generate the routing table (next hop and distance) for every node.

## Tools Required
- Linux (Ubuntu), GCC compiler, vim/nano

## Algorithm
**Input:** number of nodes `N` and cost matrix `C[N][N]` where `C[i][j]` is the cost from node `i` to node `j`.

1. For each node `i`, initialize `DV[i][j] = C[i][j]` for all `j`. Set next hop to `j` if directly connected, otherwise `-1`.
2. Repeat until no distance vector changes:
   - For each node `i`, destination `j` and neighbour `k` of `i`:
   - If `DV[i][j] > C[i][k] + DV[k][j]`, set `DV[i][j] = C[i][k] + DV[k][j]` and next hop = `k`.
3. After convergence, print the final distance vectors (routing tables) of all nodes.

## Code
See [`exp10_219.c`](exp10_219.c)

## Compile and Run
```bash
vim exp10_219.c
gcc exp10_219.c -o exp10_219
./exp10_219
```
Enter the number of nodes (3) and the cost matrix row by row (use `999` for no connection).

## Output
```
$ ./exp10_219
Enter number of nodes: 3
Enter cost matrix row by row (use 999 for INF/no connection):
0 2 7
2 0 1
7 1 0

Routing table for Node 0:
Destination     Next Hop        Distance
0               -1              0
1               1               2
2               1               3

Routing table for Node 1:
Destination     Next Hop        Distance
0               0               2
1               -1              0
2               2               1

Routing table for Node 2:
Destination     Next Hop        Distance
0               1               3
1               1               1
2               -1              0
```

## Observation Table
| Step | Command / Action | Observation |
|---|---|---|
| 1 | Input: 3 nodes; matrix `0 2 7 / 2 0 1 / 7 1 0` | Program accepted the cost matrix |
| 2 | Routing table for Node 0 | To 1: next hop 1, distance 2; to 2: next hop 1, distance 3 |
| 3 | Routing table for Node 1 | To 0: next hop 0, distance 2; to 2: next hop 2, distance 1 |
| 4 | Routing table for Node 2 | To 0: next hop 1, distance 3; to 1: next hop 1, distance 1 |

## Result
- Successfully implemented the Distance Vector Routing algorithm in C.
- The shortest path from Node 0 to Node 2 is 3 (via Node 1), better than the direct cost of 7.

## Conclusion
- Each node maintains a table with the distance to every other node and the next hop to reach it.
- The algorithm loops until no updates are made, which ensures shortest paths are computed.
