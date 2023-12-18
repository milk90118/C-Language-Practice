/* Radix Sort */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int getMax(int arr[], int n)
{
    int mx = arr[0];

    for(int i = 0; i < n; ++i)
    {
        if(arr[0] > mx) mx = arr[i];
    }

    return mx;
}

void countSort(int arr[], int n, int exp)
{
    int* output = malloc(n * sizeof(int));
    // output array for storing sorting elements

    int count[10] = {0}; // counting digits (0~9)
    
    // Count occurence of each digit in the exp position

    for(int i = 0; i < n; ++i)
    {
        count[(arr[i] / exp) % 10]++;
    }

    // Modify the array such that each element at each index stores the sum
    // of previous counts
    // determine the position in the sorted array
    for(int i = 1; i < 10; ++i)
    {
        count[i] += count[i - 1];
    }

    // Place elements in their correct positions and decrease the count by one

    for(int i = n - 1; i >= 0; --i)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for(int i = 0; i < n; ++i)
    {
        arr[i] = output[i];
    }

    free(output);
}

void radixSort(int arr[], int n)
{
    int m = getMax(arr, n);

    // Iterate through each digit place(units, tens, hundreds)

    for(int exp = 1; m / exp > 0; exp *= 10)
    {
        countSort(arr, n, exp);
    }
}

int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};

    int n = sizeof(arr) / sizeof(arr[0]);
    radixSort(arr, n);

    printf("Sorted Array:\n");

    for(int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

