#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low], i = low + 1, j = high;
    while (i <= j)
    {
        while (i <= high && arr[i] <= pivot)
            i++;
        while (j > low && arr[j] > pivot)
            j--;
        if (i < j)
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 1000)
    {
        printf("Invalid input. n should be between 1 and 1000.\n");
        return 1;
    }

    int arr[n];
    srand(time(NULL));
    printf("Random Numbers:\n");
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
        printf("%d\t", arr[i]);
    }

    clock_t start = clock();
    quickSort(arr, 0, n - 1);
    clock_t end = clock();

    printf("\n\nSorted Numbers:\n");
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);

    printf("\n\nTime taken: %e seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}