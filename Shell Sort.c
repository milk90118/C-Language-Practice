/* Shell Sort: generalizes the insertion sort to allow exchanges of far apart elements.
This algorithm avoids large shifts if the smaller value is to the far right and has
to be moved to the far left. */

#include <stdio.h>

void shellSort(int arr[], int n)
{
    // Starts with a large gap and reduces it in each gap
    for(int gap = n / 2; gap > 0; gap /= 2)
    {
        for(int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            int j;

            for(j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main()
{
    int arr[] = {12, 34, 54, 2, 3};

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");

    for(int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    shellSort(arr, n);

    printf("Sorted Array:\n");

    for(int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

