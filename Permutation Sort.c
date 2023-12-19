/* Permutation Sort */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int* x, int* y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

bool isSorted(int arr[], int n)
{
    for(int i = 0; i < n - 1; ++i)
    {
        if(arr[i] > arr[i + 1]) return false;
    }
    return true;
}

// Generates permutation using Heap's algorithm
void permute(int arr[], int n, int l)
{
    if(l == n)
    {
        if(isSorted(arr, n))
        {
            printf("Sorted Array:\n");

            for(int i = 0; i < n; ++i)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");
            exit(0);
        }
        return;
    }

    for(int i = l; i < n; ++i)
    {
        swap(&arr[l], &arr[i]);

        permute(arr, n, l + 1);

        swap(&arr[l], &arr[i]); //backtrack
    }

}

int main()
{
    int arr[] = {3, 2, 1, 4};

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");

    for(int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    permute(arr, n, 0);

    return 0;
}

