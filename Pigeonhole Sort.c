/* PigeonholeSort: creating an array of "holes" each of which represents a known range of values
and then partitioning the elements of the input array into these buckets
Finally, the elements are collected back from the buckets. 

Note: suitable for situations where the range of potential items in the input is known
and not significantly larger than the number of items.*/

#include <stdio.h>
#include <stdlib.h>

void pigeonholeSort(int arr[], int n)
{
    int min = arr[0];
    int max = arr[0];

    int range, index;

    // Find the minimum and maximum values in the array
    for(int a = 0; a < n; ++a)
    {
        if(arr[a] > max) max = arr[a];

        if(arr[a] < min) min = arr[a];
    }

    range = max - min + 1;

    // Create an array "holes" with size equal to "range"
    int *holes = (int*)calloc(range, sizeof(int));

    for(int i = 0; i < n; ++i)
    {
        holes[arr[i] - min]++;
    }
    // Each index represents a value from a range, and its value represents the count
    // of that element in the input array

    index = 0;
    for(int j = 0; j < range; ++j)
    {
        while(holes[j]-- > 0)
        {
            arr[index++] = j + min;
        }
    }

    free(holes);
}

int main()
{
    int arr[] = {8, 3, 2, 7, 4, 6, 8};

    int n = sizeof(arr) / sizeof(arr[0]);
    pigeonholeSort(arr, n);

    printf("Sorted Array:\n");

    for(int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

