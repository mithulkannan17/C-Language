#include <stdio.h>
#include <stdlib.h>

#define INF 999
#define MAX 9

int cost[MAX][MAX], parent[MAX], n;

int find(int i)
{
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j)
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}

void kruskal()
{
    int mincost = 0, edges = 0;

    printf("\nEdges in Minimum Cost Spanning Tree:\n");
    while (edges < n - 1)
    {
        int min = INF, a = -1, b = -1;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }

        int u = find(a), v = find(b);
        if (uni(u, v))
        {
            printf("%d edge (%d,%d) = %d\n", ++edges, a, b, min);
            mincost += min;
        }

        cost[a][b] = cost[b][a] = INF;
    }
    printf("\nMinimum Cost = %d\n", mincost);
}

int main()
{
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix (use %d for no edge):\n", INF);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }

    kruskal();
    return 0;
}

/*
Input:
Output:
*/