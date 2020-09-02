#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
int main(void)
{
    int n,a,b;
    while(scanf("%d%d%d",&n,&a,&b)==3)
    {
        printf("%d",((a+b-1)%n+n)%n+1);
    }
    return 0;
}
