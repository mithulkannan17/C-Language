#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Merge(int a[], int low, int mid, int high)
{
    int i, j, k, b[20];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while (i <= mid)
        b[k++] = a[i++];
    while (j <= high)
        b[k++] = a[j++];
    for (k = low; k <= high; k++)
        a[k] = b[k];
}
void MergeSort(int a[], int low, int high)
{
    int mid;
    if (low >= high)
        return;
    mid = (low + high) / 2;
    MergeSort(a, low, mid);
    MergeSort(a, mid + 1, high);
    Merge(a, low, mid, high);
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    srand(time(NULL));
    printf("Random Numbers:\n");
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
        printf("%d\t", arr[i]);
    }

    clock_t start = clock();
    MergeSort(arr, 0, n - 1);
    clock_t end = clock();

    printf("\n\nSorted Numbers:\n");
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);

    printf("\n\nTime taken: %e seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}