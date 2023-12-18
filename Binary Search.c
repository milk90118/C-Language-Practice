#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);

    int* arr = malloc(n * sizeof(int));

    if(arr == NULL)
    {
        printf("Failed to allocate memory.\n");
        return 1;
    }

    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    for(int k = 0; k < q; ++k)
    {
        int num;
        scanf("%d", &num);

        int left = 0;
        int right = n - 1;
        int found = 0;

        while(left <= right)
        {
            int mid = left + (right - left) / 2;

            if(arr[mid] == num)
            {
                printf("%d\n", mid);
                found = 1;
                break;
            }

            else if(arr[mid] < num) left = mid + 1;
            else if(arr[mid] > num) right = mid - 1;
        }

        if(!found)
        {
            printf("Not found.\n");
        }
    }

    free(arr);
    return 0;
}