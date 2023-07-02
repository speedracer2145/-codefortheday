//Program No 2
#include<stdio.h>
struct Distance
{
    int ft;
    int inch;
};
int main()
{
    struct Distance d1, d2, sum;
    scanf("%d", &d1.ft);
    scanf("%d", &d1.inch);
    scanf("%d", &d2.ft);
    scanf("%d", &d2.inch);

    sum.inch = d1.inch + d2.inch;
    sum.ft = d1.ft + d2.ft;
    if (sum.inch >= 12) 
    {
        sum.ft += sum.inch / 12;
        sum.inch %= 12;
    }

    printf("\nTotal distance- Feet: %d, Inches: %d", sum.ft, sum.inch);
    return 0;

}