#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int isprime(int64_t num)
{
    int flag=0;
    for(int64_t i=2; i<=sqrt(num); i++)
    {
        if(num%i==0)
        {
            flag=1;
            return 0;
        }
    }
    if(flag==0)
    {
        return 1;
    }
}
int main(void)
{
    int64_t n;
    while((scanf("%I64d",&n))==1)
    {
        if(n==0)
        {
            break;
        }
        for(int64_t j=3; j<=(n/2); j=j+2)
        {
            if(isprime(j)&&isprime(n-j))
            {
                printf("%I64d = %I64d + %I64d\n",n,j,n-j);
                break;
            }
        }
    }
    return 0;
}
