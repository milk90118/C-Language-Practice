/* Merge Sort using C program */

#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int i, j, k;

    // Create temporary arrays LEFT and RIGHT
    int* LEFT = malloc(n1 * sizeof(int));
    int* RIGHT = malloc(n2 * sizeof(int));

    // Copy data to temporary arrays

    for(i = 0; i < n1; ++i)
    {
        LEFT[i] = arr[l + i];
    }

    for(j = 0; j < n2; ++j)
    {
        RIGHT[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    // Merge the two halves back into a[l ... r]
    while(i < n1 && j < n2)
    {
        if(LEFT[i] <= RIGHT[j])
        {
            arr[k] = LEFT[i];
            i++;
        }
        else
        {
            arr[k] = RIGHT[j];
            j++;
        }
        k++;
    }

    // Copy the remaining element of LEFT subarray, if there are any
    while(i < n1)
    {
        arr[k] = LEFT[i];
        i++;
        k++;
    }

    // Copy the remaining element of RIGHT subarray, if there are any
    while(j < n2)
    {
        arr[k] = RIGHT[j];
        j++;
        k++;
    }

    free(LEFT);
    free(RIGHT);

}

void mergeSort(int arr[], int l, int r)
{
    if(l < r)
    {
        int m = l + (r - l) / 2; // Calculate the middle index to divide the array
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void printArr(int a[], int size)
{
    for(int i = 0; i < size; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {0, 5, 2, 4, 2, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    printArr(arr, size);

    mergeSort(arr, 0, size - 1);
    printArr(arr, size);
    return 0;
}