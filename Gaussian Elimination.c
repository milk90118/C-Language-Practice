/* Gaussian Elimination: row reduction */

#include <stdio.h>
#include <string.h>

void printMat(float mat[100][100], int H, int W)
{
    for(int i = 0; i < H; ++i)
    {
        char ch = 'x';
        for(int j = 0; j < W; ++j)
        {
            printf("%f", mat[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    float a[100][100];

    int h, w;
    int idx = 0;

    scanf("%d %d", &h, &w);

    for(int i = 0; i < h; ++i)
    {
        for(int j = 0; j < w; ++j)
        {
            scanf("%f", &a[i][j]);
        }
    }

    //printMat(a, h, w);
    //printf("\n");

    while(1)
    {
        for(int i = idx + 1; i < h; ++i)
        {
            float mul = a[i][idx] / a[idx][idx];

            //printf("%f\n", mul);

            for(int j = 1; j < w; ++j)
            {
                a[i][j] -= a[idx][j] * mul;
            }
            a[i][idx] = 0;
        }
        //printMat(a, h, w);
        idx++;

        if(idx == h) break;
    }

    float ans[100];

    for(int i = h - 1; i >= 0; --i)
    {
        float right = a[i][w - 1];

        for(int j = w - 2; j > i; --j)
        {
            right -= ans[j] * a[i][j];
        }

        ans[i] = right / a[i][i];
    }

    for(int i = 0; i < w - 1; ++i)
    {
        printf("%.0f ", ans[i]);
    }

    return 0;
}