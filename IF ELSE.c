#include<stdio.h>
main(void)
{
    float a,b;
    scanf("%f%f", &a,&b);
    if(a>b)
    {
        printf("%f is bigger",a);
    }
    else if(a<b)
    {
        printf("%f is bigger",b);
    }
    else
    {
        printf("%f and %f are equal", a,b);
    }
}
