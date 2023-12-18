#include <stdio.h>

typedef struct{
    int feet;
    int inch;
} distance;

distance addTwoDistance(distance a, distance b)
{
    distance total;
    total.inch = a.inch + b.inch;
    total.feet = a.feet + b.feet + total.inch / 12; 
    /* 1 feet has 12 inches
    1100 inches = 91 feets + 8 inches */
    total.inch = total.inch % 12;

    return total;
}

int main()
{

    printf("Enter first distance in feet & inches:");
    distance firstDis, secDis;
    scanf("%d %d", &firstDis.feet, &firstDis.inch);

    printf("Enter second distance in feet & inches:");
    scanf("%d %d", &secDis.feet, &secDis.inch);

    distance ans = addTwoDistance(firstDis, secDis);

    printf("Total distance - Feet %d, Inches: %d\n", ans.feet, ans.inch);
    return 0;
}
