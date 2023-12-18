#include <stdio.h>
#include <stdlib.h>

int fac(int n)
{
    int res = 1;

    for(int i = 1; i <= n; ++i)
    {
        res *= 2;
    }
    return res;
}

void fillInGrids(int** mat, int start, int end, int size, int* num)
{
    if(size == 1)
    {
        mat[start][end] = *num;
        (*num)++;
        return;
    }

    int half = size / 2;
    fillInGrids(mat, start, end, half, num);
    fillInGrids(mat, start, end + half, half, num);
    fillInGrids(mat, start + half, end, half, num);
    fillInGrids(mat, start + half, end + half, half, num);

}

void printMat(int** mat, int h)
{
    for(int i = 0; i < h; ++i)
    {
        for(int j = 0; j < h; ++j)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int h, find;
    scanf("%d %d", &h, &find);

    h = fac(h);

    int** mat = malloc(h * sizeof(int*));

    for(int i = 0; i < h; ++i)
    {
        mat[i] = malloc(h * sizeof(int));
    }
    int begin = 1;

    fillInGrids(mat, 0, 0, h, &begin);
    printMat(mat, h);

    for(int i = 0; i < h; ++i)
    {
        for(int j = 0; j < h; ++j)
        {
            if(find == mat[i][j])
            {
                printf("%d %d", ++i, ++j);
                
                for (int k = 0; k < h; ++k) {
                    free(mat[k]);
                }
                free(mat);
                return 0;
            }
        }
    }
    
    for (int i = 0; i < h; ++i) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}