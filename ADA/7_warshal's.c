#include <stdio.h>

#define MAX 10

void findTransitiveClosure(int p[MAX][MAX], int n)
{
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                p[i][j] |= (p[i][k] && p[k][j]); // Using bitwise OR for clarity
}

int main()
{
    int n, p[MAX][MAX];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &p[i][j]);

    findTransitiveClosure(p, n);

    printf("\nThe Path Matrix (Transitive Closure) is:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", p[i][j]);
        printf("\n");
    }

    return 0;
}

/*
Input: Enter the non negative integer valued matrix
Output: transitive closure of teh diagraph

A = w
for k <-- 1 to n do
 for i <-1 1 to n do
     for j <-- 1 to n do
     A[i][j] = A[i][j] OR (A[i][k] AND A[k][j])
return A
*/