#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int a[MAX][MAX], n, indegree[MAX];

void FindIndegree()
{
    for (int j = 0; j < n; j++)
    {
        indegree[j] = 0;
        for (int i = 0; i < n; i++)
            indegree[j] += a[i][j];
    }
}

void topologySort()
{
    int stack[MAX], order[MAX], top = -1, k = 0;
    FindIndegree();

    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            stack[++top] = i;

    while (top != -1)
    {
        int u = stack[top--];
        order[k++] = u;
        for (int v = 0; v < n; v++)
        {
            if (a[u][v] == 1 && --indegree[v] == 0)
                stack[++top] = v;
        }
    }
    printf("Topological Order:\n");
    for (int i = 0; i < n; i++)
        printf("%d", order[i]);
    printf("\n");
}

int main()
{
    printf("Enter the number of nodes:");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    topologySort();
    return 0;
}