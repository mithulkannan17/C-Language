#include <stdio.h>

#define INF 999
#define MAX 10

void dijkstra(int n, int v, int cost[MAX][MAX], int d[MAX])
{
    int flag[MAX] = {0}, min, u;

    for (int i = 0; i < n; i++)
        d[i] = cost[v][i];

    for (int count = 1; count < n; count++)
    {
        min = INF;
        u = -1;

        for (int w = 0; w < n; w++)
            if (!flag[w] && d[w] < min)
            {
                min = d[w];
                u = w;
            }

        flag[u] = 1;

        for (int w = 0; w < n; w++)
            if (!flag[w] && d[u] + cost[u][w] < d[w])
                d[w] = d[u] + cost[u][w];
    }
}

int main()
{
    int n, v, cost[MAX][MAX], d[MAX];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter cost matrix (use %d for no edge):\n", INF);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }

    printf("Enter source node: ");
    scanf("%d", &v);
    v--; // Convert to zero-based indexing

    dijkstra(n, v, cost, d);

    printf("\nShortest paths from node %d:\n", v + 1);
    for (int i = 0; i < n; i++)
        if (i != v)
            printf("To %d = %d\n", i + 1, d[i]);

    return 0;
}