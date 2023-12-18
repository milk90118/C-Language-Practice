#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char* str)
{
    int len = strlen(str);

    for(int i = 0; i < len / 2; ++i)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main()
{
    int t;
    scanf("%d", &t);

    char str[100][100];

    while(t--)
    {
        int n;
        scanf("%d", &n);

        for(int i = 0; i < n; ++i)
        {
            scanf("%s", str[i]);

            //reverse(str[i]);
        }

        for(int i = 0; i < n; ++i)
        {
            printf("%s ", str[n - i - 1]);
        }
        printf("\n");
    }

    return 0;
}