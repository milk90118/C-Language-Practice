/* Quick Sort */

#include <stdio.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];

    int idx = low - 1;

    for(int j = low; j < high; ++j)
    {
        if(arr[j] < pivot)
        {
            idx++;
            swap(&arr[idx], &arr[j]);
        }
    }
    
    swap(&arr[idx + 1], &arr[high]);
    return (idx + 1);
}

void quickSort(int arr[], int low, int high)
{
    // Base Case: If low is >= high, return
    if(low < high)
    {
        int pi = partition(arr, low, high);
        //printf("Current pivot: %d\n", arr[pi]);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};

    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);

    printf("Sorted Array:\n");

    for(int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

