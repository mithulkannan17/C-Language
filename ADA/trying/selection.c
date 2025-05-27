#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void SelectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        if (i != minIdx)
        {
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
}

int main()
{
    int i, n, arr[20];

    printf("Enter the size of the array:");
    scanf("%d", &n);
    printf("Random Numbers:\n");
    srand(time(NULL));
    for (i = 0; i < n; i++)
    {
        arr[i] = rand();
        printf("%d\t", arr[i]);
    }

    clock_t start = clock();
    SelectionSort(arr, n);
    clock_t end = clock();

    printf("\n\nSorted Numbers:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", arr[i]);

    printf("\n\nTime taken: %e\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}