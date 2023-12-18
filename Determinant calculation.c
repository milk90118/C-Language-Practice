/* Determinant Calculation */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printMat(float mat[100][100], int size)
{
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size; ++j)
        {
            printf("%f ", mat[i][j]);
        }
        printf("\n");
    }
}

void swapRows(float mat[100][100], int row1, int row2, int size)
{
    for(int i = 0; i < size; ++i)
    {
        float temp = mat[row1][i];
        mat[row1][i] = mat[row2][i];
        mat[row2][i] = temp;
    }
}

void upperTriangle(float mat[100][100], int size, int* sign)
{
    for(int i = 0; i < size; ++i)
    {
        if(mat[i][i] == 0)
        {
            int swapRow = i + 1;

            while(swapRow < size && mat[swapRow][i] == 0)
            {
                swapRow++;
            }

            if(swapRow < size)
            {
                swapRows(mat, i, swapRow, size);
                *sign = -(*sign);
            }
        }

        for(int j = i + 1; j < size; ++j)
        {
            float mul = mat[j][i] / mat[i][i];

            for(int k = i; k < size; ++k)
            {
                mat[j][k] -= mat[i][k] * mul;
            }
        }
    }

    /*for(int idx = 0; idx < h - 1; ++idx)
    {
        for(int i = idx + 1; i < h; ++i)
        {
            if(mat[idx][idx] == 0)
            {
                printf("Error: Division by zero.\n");
                return;
            }

            float mul = mat[i][idx] / mat[idx][idx];

            for(int j = 0; j < w; ++j)
            {
                mat[i][j] -= mat[idx][j] * mul;
            }

            //mat[i][idx] = 0;
        }
    }
    printMat(mat, h, w);*/
}

float determinant(float mat[100][100], int size)
{
    float det = 1;
    int sign = 1;

    upperTriangle(mat, size, &sign);

    for(int i = 0; i < size; ++i)
    {
        det *= mat[i][i];
    }

    return det * sign;
}

int main()
{
    int size;
    float a[100][100];

    while(scanf("%d", &size) != EOF)
    {
        for(int i = 0; i < size; ++i)
        {
            for(int j = 0; j < size; ++j)
            {
                scanf("%f", &a[i][j]);
            }
        }

        float f = determinant(a, size);

        int ans = round(f);
        if(ans > 0) ans %= 100000007;
        else
        {
            ans += 100000007;
            ans %= 100000007;
        }

        printf("%d\n", ans);
    }

    return 0;
}