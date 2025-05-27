#include <stdio.h>
int min(int, int);
void floyds(int p[10][10], int n)
{
    int i, j, k;
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (i == j)
                    p[i][j] = 0;
                else
                    p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
}
int min(int a, int b)
{
    if (a < b)
        return (a);
    else
        return (b);
}
int main()
{
    int p[10][10];
    int n, e;    // number of vertices and edges
    int u, v, w; // edge endpoints and weight
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    // Initialize the matrix with large value (999 for infinity)
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i == j)
                p[i][j] = 0; // distance to self is 0
            else
                p[i][j] = 999; // initialize as "infinity"
        }
    }

    // Input edges and weights
    for (i = 1; i <= e; i++)
    {
        printf("Enter edge %d (start end weight): ", i);
        scanf("%d %d %d", &u, &v, &w);
        p[u][v] = w;
    }

    // Show input matrix
    printf("\nInitial matrix (input graph):\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%d\t", p[i][j]);
        printf("\n");
    }

    // Run Floyd's algorithm
    floyds(p, n);

    // Show shortest path matrix
    printf("\nShortest path matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%d\t", p[i][j]);
        printf("\n");
    }

    // Print all shortest paths
    // printf("\nShortest paths between all pairs:\n");
    // for (i = 1; i <= n; i++)
    // {
    //     for (j = 1; j <= n; j++)
    //     {
    //         if (i != j)
    //             printf("From %d to %d = %d\n", i, j, p[i][j]);
    //     }
    // }

    return 0;
}

/*
Input: The weight matrix W of a graph with non negative length
Output: The distance matrix of the shortest path length
A <-- W
   for k <-- 1 to n do
      for i <-- 1 to n do
          for j <-- 1 to n do
             A[i][j] = min{ A[i][j], A[i][k] + A[k][j] }
return A*/
