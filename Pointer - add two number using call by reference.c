#include <stdio.h>

int add(int* a, int* b) // call by reference
{
    int sum = *a + *b;
    return sum;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d", add(&a, &b));
    return 0;
}