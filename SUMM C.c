#include<stdio.h>
int main(void)
{
    int n;
    int sumn1,sumn2,summ1,summ2;
    printf("\nEnter the value of n: ");
    scanf("%d",&n);
    sumn1=(n*(n-1))/2;
    sumn2=((n-1)*(n-2))/2;
    summ1=(sumn1*(sumn1-1))/2;
    summ2=(sumn2*(sumn2-1))/2;
    printf("\nSummation is: %d",summ2-summ1);
    return 0;
}
