#include<stdio.h>
#include<math.h>
int main(void)
{
    int i,t;
    long int c,mid;
    long int s,x,y;
    long int diff;
    scanf("%ld",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%ld",&s);
        double a= sqrt(s);
        c=ceil(a);
        mid = c*c-(c-1);
        x=y=c;
        if(mid==s)
        {
            x=y=c;
        }
        else if(c%2!=0)
        {
            diff=abs(mid-s);
            if(s>mid)
                x=c-diff;
            else y=c-diff;
        }
        else
        {
            diff=abs(mid-s);
            if(s>mid)
                y=c-diff;
            else x=c-diff;
        }
        printf("Case %d: %ld %ld\n",i,x,y);
    }
    return 0;
}
