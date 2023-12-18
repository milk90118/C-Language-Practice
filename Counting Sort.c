/* Counting Sort 
1. Find the largest elelment in the array.
2. Initialize the count array with length "MAX + 1" and all elements set to 0.
3. Store elements of the given array with the corresponding index in the count array.
4. Change the count array by adding the previous counts to produce the cumulative
    sum of an array.
5. Create another empty array with one places to store the sorted data, place the 
    elements in their correct positions and reduce the count by one.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countingSort(int arr[], int n)
{

    int max = arr[0];

    // Find the maximum element

    for(int i = 1; i < n; ++i)
    {
        if(arr[i] > max) max = arr[i];
    }

    int* count = malloc((max+1) * sizeof(int));

    memset(count, 0, (max + 1) * sizeof(int));

    // Count the occurrences of each element
    for(int i = 0; i < n; ++i)
    {
        count[arr[i]]++;
    }

    // 反向填充
    int idx = 0;
    for(int i = 0; i <= max; ++i)
    {
        while(count[i] > 0)
        {
            arr[idx++] = i;
            count[i]--;
        }
    }
    free(count);
}

int main()
{
    int arr[] = {4, 2, 2, 8, 3, 3, 1};

    int n = sizeof(arr) / sizeof(arr[0]);
    countingSort(arr, n);

    printf("Sorted array: \n");

    for(int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}