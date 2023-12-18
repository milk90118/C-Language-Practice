/* H Index

Given an array of integers citations where citation[i] is the number of citations
a researcher received for their ith paper, return compute the researcher's h index.
According to the definition of h-index on Wikipedia: A scientist has an index h
if h of their n papers have at least h citations each,
and the other n - h papers have no more than h citations each.

If there are several possible values for h, the maximum one is taken as the h-index.

The length of the citation will be in the range from 1 to 100,
and the range of the citation[i] is 0 to 100.

The first line of the input is the length of citation, and the second line contains
how many citations of each paper.

Sample Input:
5
3 0 6 1 5
Sample Output:
3
Sample Explanation:
5 indicates the researcher has 5 papers in total.
3 0 6 1 5 means each of papers had received 3, 0, 6, 1, 5 citations respectively.
Since the researcher has 3 papers with at least 3 citations each and the remaining 2
with no more than 3 citations each, their h-index is 3.
*/

#include <stdio.h>
#include <stdlib.h>

void hIndex(int a[], int c)
{
    //int max_cite = 0;
    int cnt;

    /*for(int i = 0; i < c; ++i)
    {
        if(a[i] > max_cite)
        {
            max_cite = a[i];
        }
    }
    printf("Max citation: %d\n", max_cite);*/

    for(int i = c; i >= 0; --i)
    {
        cnt = 0;
        for(int j = 0; j < c; ++j)
        {
            if(a[j] >= i)
            {
                cnt++;
            }
        }

        if(cnt >= i)
        {
            printf("H index: %d\n", i);
            //max_cite = i;
            return;
        }
        //else max_cite = i;
    }
    //printf("H index: %d\n", max_cite);
}

int main()
{
    int c;
    scanf("%d", &c);

    int* citations = malloc(c * sizeof(int));

    if(citations == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for(int i = 0; i < c; ++i)
    {
        scanf("%d", &citations[i]);
    }

    hIndex(citations, c);
    return 0;
}