#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 30

int board[MAX]; // board[i] stores the column of queen in row i
int solutionCount = 0;

// Check if it's safe to place a queen at (row, board[row])
int isSafe(int row)
{
    for (int i = 1; i < row; i++)
    {
        // Same column or diagonal clash
        if (board[i] == board[row] || abs(board[i] - board[row]) == abs(i - row))
            return 0;
    }
    return 1;
}

// Print the board
void printSolution(int n)
{
    solutionCount++;
    printf("\nSolution #%d:\n", solutionCount);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (board[i] == j)
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }
}

// Main logic to solve the N-Queens using backtracking
void solveNQueens(int n)
{
    int row = 1;
    board[row] = 0;

    while (row > 0)
    {
        board[row]++; // Try next column

        // Keep trying until it's safe or out of bounds
        while (board[row] <= n && !isSafe(row))
            board[row]++;

        if (board[row] <= n)
        {
            if (row == n)
                printSolution(n); // One solution found
            else
            {
                row++;          // Go to next row
                board[row] = 0; // Reset column for next row
            }
        }
        else
        {
            row--; // Backtrack to previous row
        }
    }
}

int main()
{
    int n;
    printf("Enter number of Queens: ");
    scanf("%d", &n);

    solveNQueens(n);

    printf("\nTotal solutions found: %d\n", solutionCount);
    return 0;
}
