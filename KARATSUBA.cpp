#include<iostream>
#include<cstdio>
#include<cmath>
int main(void)
{
int x,y,m=1;
scanf("%d",&x);
scanf("%d",&y);
while(1)
{
    if(pow(2,m)>=sqrt(x))
    {
        break;
    }
    else
    {
        m++;
    }
}
printf("m: %d",m);
int xl=x%m;
int xh=floor(x/m);
int yl=y%m;
int yh=floor(y/m);
int a=xh*yh;
int b=(xl+xh)*(yl*yh);
int c=xl*yl;
printf("\nMultiplication is: %d",a*m*m+(b-a-c)*m+c);
return 0;
}
