//Program No 3
#include<stdio.h>
#include<math.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void main()
{
    int a,b;
    printf("input : ");
    scanf("%d %d",&a,&b);
    swap(&a,&b);
    printf("\noutput : ");
    printf("%d %d",a,b);
    
    
}