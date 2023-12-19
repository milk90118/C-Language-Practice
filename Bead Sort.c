/* Bead Sort, aka Gravity Sort */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beadSort(int arr[], int len)
{
    // Find the maximum element
    int max = arr[0];

    for(int i = 1; i < len; ++i)
    {
        if(arr[i] > max) max = arr[i];
    }

    // Allocate memory for beads
    unsigned char *beads;
    size_t size = max * len;

    beads = calloc(1, size);

    // Mark the beads
    for(int i = 0; i < len; ++i)
    {
        for(int j = 0; j < arr[i]; ++j)
        {
            beads[i * max + j] = 1;
        }
    }

    // Drop the beads
    for(int j = 0; j < max; ++j)
    {
        int sum = 0;

        for(int i = 0; i < len; ++i)
        {
            sum += beads[i * max + j];
            beads[i * max + j] = 0;
        }

        for(int i = len - sum; i < len; ++i)
        {
            beads[i * max + j] = 1;
        }
    }

    // Put sorted values back into array
    for(int i = 0; i < len; ++i)
    {
        int j;
        for(j = 0; j < max && beads[i * max + j]; ++j);
        
        arr[i] = j;
    }

    free(beads);

}

int main()
{
    int arr[] = {5, 3, 1, 7, 4, 1};

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");

    for(int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    beadSort(arr, n);

    printf("Sorted Array:\n");

    for(int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

