/* 第一行有一個整數代表 N ：有幾份文件
接下來 N 行：第一個數字 K 代表這份文件有多少個整數
接續 K 個數字：文件資料 (<=100,0000)
Q：幾筆詢問。Q 行：每行有兩個整數 a、b 詢問第 a 到第 b 個資料為何*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int** ptr = malloc(n * sizeof(int*));

    for(int i = 0; i < n; ++i)
    {
        int k;

        scanf("%d", &k);

        int* arr = malloc(k * sizeof(int));
        ptr[i] = arr;

        for(int j = 0; j < k; ++j)
        {
            scanf("%d", &arr[j]);
        }
    }

    int q;
    scanf("%d", &q);

    while(q--)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        printf("%d\n", ptr[a][b]);
    }

    for(int i = 0; i < n; ++i)
    {
        free(ptr[i]);
    }
    free(ptr);

    return 0;
}