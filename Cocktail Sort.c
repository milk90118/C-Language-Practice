#include <stdio.h>
#include <stdbool.h>
#define LEN 7

void printArr(int arr[], int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void cocktailSort(int arr[], int size) 
{
    bool swapped;
    int start = 0;
    int end = size - 1;

    do {
        swapped = false;
        printf("Forward Pass:\n");

        // Forward pass
        for (int i = start; i < end; ++i) 
        {
            if (arr[i] > arr[i + 1]) 
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true;
                printArr(arr, size);
            }
        }

        swapped = false;
        
        end--; // The last element is now in place

        printf("Backward Pass:\n");

        // Backward pass
        for (int i = end - 1; i >= start; --i) 
        {
            if (arr[i] > arr[i + 1]) 
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true;
                printArr(arr, size);
            }
        }

        start++; // The first element is now in place

        if (!swapped) 
        {
            break; // Array is sorted
        }

    } while (swapped);
}

int main() {
    int arr[LEN];

    printf("Enter %d integers: ", LEN);
    for (int i = 0; i < LEN; ++i) {
        scanf("%d", &arr[i]);
    }

    printf("Original Unsorted Array: ");
    printArr(arr, LEN);

    cocktailSort(arr, LEN);

    printf("Sorted Array: ");
    printArr(arr, LEN);

    return 0;
}
