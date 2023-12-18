/* 給你兩個字串，比較是否相同，但大小寫視為相同 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int t;
    scanf("%d", &t);
    getchar();

    while(t--)
    {
        char str1[105];
        char str2[105];

        fgets(str1, sizeof(str1), stdin);
        str1[strcspn(str1, "\n")] = '\0';

        fgets(str2, sizeof(str2), stdin);
        str2[strcspn(str2, "\n")] = '\0';

        /*int len1 = strlen(str1);
        int len2 = strlen(str2);

        if(len1 != len2)
        {
            printf("Fail\n");
            continue;
        }*/

        int same = 1;

        for(int i = 0; str1[i] != '\0'; ++i)
        {
            if(tolower(str1[i]) != tolower(str2[i]))
            {
                printf("Fail\n");
                same = 0;
                break;
            }
        }
        if(same) printf("Pass\n");
    }

    return 0;
}