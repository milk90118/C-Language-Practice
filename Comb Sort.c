/* Comb sort: an improvement on the Bubble Sort -> eliminates turtles or small values
near the end of the list by using a gap of size more than 1.*/

#include <stdio.h>

int getNextGap(int gap)
{
    // Shrink gap by a factor of 1.3
    gap = (gap * 10) / 13;

    if(gap < 1) return 1;

    return gap;
}
// Initially, the gap is large to help sort elements that are far apart.
// As the sort progresses, the gap is reduced.

void combSort(int arr[], int n)
{
    int gap = n;
    int swapped = 1;

    // Keep running while the gap is more than 1 and last iteration caused a swap
    while(gap != 1 || swapped == 1)
    {
        gap = getNextGap(gap);
        swapped = 0;

        // Compare all elements with current gap

        for(int i = 0; i < n - gap; ++i)
        {
            if(arr[i] > arr[i + gap])
            {
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swapped = 1;
            }
        }
        // Over a wider range of elements
    }
}

int main()
{
    int arr[] = {8, 4, 1, 56, 3, -44, 23, -6, 28, 0};

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");

    for(int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    combSort(arr, n);

    printf("Sorted Array:\n");

    for(int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

