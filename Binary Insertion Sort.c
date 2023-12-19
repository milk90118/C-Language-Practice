/* Binary Insertion sort */

#include <stdio.h>

int binarySearch(int arr[], int item, int low, int high)
{
    // perform binary search on the sorted part of the array

    if(high <= low)
    {
        return (item > arr[low]) ? (low + 1) : low;
    }

    int mid = (low + high) / 2;

    if(item == arr[mid]) return (mid + 1);

    if(item > arr[mid]) return binarySearch(arr, item, mid + 1, high);

    return binarySearch(arr, item, low, mid - 1);

}

void binaryInsertionSort(int arr[], int n)
{
    int loc, selected;
    int j;

    for(int i = 1; i < n; ++i)
    {
        j = i - 1;
        selected = arr[i];

        // Find location to insert using binary search

        loc = binarySearch(arr, selected, 0, j);

        // Move all elements after location to create space
        while(j >= loc)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = selected;
    }
}

int main()
{
    int arr[] = {37, 23, 0, 17, 12, 72, 31, 46, 100, 88, 54};

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");

    for(int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    binaryInsertionSort(arr, n);

    printf("Sorted Array:\n");

    for(int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

