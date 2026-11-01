#include <stdio.h>

#define MAX_NODES 10
#define INF 999

struct Node {
    int dist[MAX_NODES];
    int from[MAX_NODES];
} rt[MAX_NODES];

int main()
{
    int cost[MAX_NODES][MAX_NODES], nodes, i, j, k;
    int updated, iteration;

    printf("Enter number of nodes: ");
    scanf("%d", &nodes);

    printf("Enter cost matrix row by row (use 999 for INF/no connection):\n");
    for (i = 0; i < nodes; i++)
    {
        for (j = 0; j < nodes; j++)
        {
            int v;
            scanf("%d", &v);
            if (v == 999)
                cost[i][j] = INF;
            else
                cost[i][j] = v;
        }
    }

    // Initialize routing tables
    for (i = 0; i < nodes; i++)
    {
        cost[i][i] = 0;
        for (j = 0; j < nodes; j++)
        {
            rt[i].dist[j] = cost[i][j];
            if (cost[i][j] != INF && i != j)
                rt[i].from[j] = j;   // next hop is the neighbour j
            else
                rt[i].from[j] = -1;  // unknown/unreachable
        }
    }

    /* Repeat relaxations at most nodes-1 times (Bellman-Ford style). */
    for (iteration = 0; iteration < nodes - 1; iteration++)
    {
        updated = 0;
        for (i = 0; i < nodes; i++)
        {
            for (j = 0; j < nodes; j++)
            {
                for (k = 0; k < nodes; k++)
                {
                    if (cost[i][k] >= INF) continue;        // no direct link i->k
                    if (rt[k].dist[j] >= INF) continue;     // k->j not known
                    int newDist = cost[i][k] + rt[k].dist[j];
                    if (newDist < rt[i].dist[j])
                    {
                        rt[i].dist[j] = newDist;
                        rt[i].from[j] = k;
                        updated = 1;
                    }
                }
            }
        }
        if (!updated) break;
    }

    // Display routing tables
    for (i = 0; i < nodes; i++)
    {
        printf("\nRouting table for Node %d:\n", i);
        printf("Destination\tNext Hop\tDistance\n");
        for (j = 0; j < nodes; j++)
        {
            if (rt[i].dist[j] >= INF)
                printf("%d\t\t-\t\tINF\n", j);
            else
                printf("%d\t\t%d\t\t%d\n", j, rt[i].from[j], rt[i].dist[j]);
        }
    }

    return 0;
}
