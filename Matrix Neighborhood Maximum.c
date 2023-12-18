/* 
Practice: Matrix Neighborhood Maximum

You are given a matrix containing two-dimensional numbers,
where each element represents the value at that position.
Write a program that for each element in the matrix, finds the maximum value
among the eight numbers surrounding the element.
*/

#include <stdio.h>
#include <stdlib.h>

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};

void printMatrix(int mat[100][100], int m, int n)
{
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void findMax(int mat[100][100], int m, int n)
{
    int ans[100][100];
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            int max_value = -1e9;

            for(int k = 0; k < 8; ++k)
            {
                int new_i = dx[k] + i;
                int new_j = dy[k] + j;

                if(mat[new_i][new_j] > max_value && new_i >= 0 && new_j >= 0 && new_i < m && new_j < n)
                {
                    max_value = mat[new_i][new_j];
                }
            }
            if(max_value > mat[i][j]) ans[i][j] = max_value;
            else ans[i][j] = mat[i][j];
        }
    }
    printMatrix(ans, m, n);
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    int a[100][100];

    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            scanf("%d", &a[i][j]);
        }
    }
    //printMatrix(a, m, n);

    //printf("\nThe Converted Matrix:\n");
    findMax(a, m, n);
    return 0;
}