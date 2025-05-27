#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n;

    printf("Enter the size of the array:");
    scanf("%d", &n);

    int arr[n];
    srand(time(NULL));
    printf("Random NUmbers are:\n");
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
        printf("%d", arr[i]);
    }

    clock_t start = clock();
    MergeSort(arr, 0, n - 1);
    clock_t end = clock();

    printf("\n\n Sorted Array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
    printf("The time taken is %e\t", (double)(end - start) / CLOCKS_PRE_SEC);
}

