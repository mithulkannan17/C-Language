#include <stdio.h>

#define INF 999
#define MAX 10

int cost[MAX][MAX], visited[MAX] = {0}, n;

void prims()
{
    int mincost = 0, edges = 0;

    visited[0] = 1; // Start from node 0
    while (edges < n - 1)
    {
        int min = INF, u = -1, v = -1;

        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u != -1 && v != -1)
        {
            printf("\nEdge %d: (%d %d) Cost: %d", ++edges, u, v, min);
            mincost += min;
            visited[v] = 1;
        }
    }

    printf("\nMinimum Cost = %d\n", mincost);
}

int main()
{
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (use %d for no edge):\n", INF);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }

    prims();
    return 0;
}