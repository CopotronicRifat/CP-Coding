#include<iostream>
#include<cstdio>
using namespace std;
int main(void)
{
    typedef unsigned long long int64_t;
    int64_t i,w,n,m;
    int t;
    scanf("%d",&t);
    for(int j=0; j<t; j++)
    {
        scanf("%llu",&w);
        if((w%2)!=0)
        {
            printf("Case %d: Impossible\n",j+1);
            continue;
        }
        for(i=2; i<=w/2; i=i+2)
        {
            m=w/i;
            if(((w%i)==0)&&((m%2)!=0))
            {
                break;
            }
        }
            printf("Case %d: %llu %llu\n",j+1,m,i);
    }
    return 0;
}
