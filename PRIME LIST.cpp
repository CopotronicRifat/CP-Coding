#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int isprime(long int num)
{
    int flag=0;
    for(long int j=2; j<=sqrt(num); j++)
    {
        if(num%j==0)
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
    long int a[80000];
    long int k=0;
    for(long int i=3; i<1000000; i=i+2)
    {
        if(isprime(i))
        {
            a[k]=i;
            k++;
            cout<<i<<endl;
        }
    }
    vector<int> v(a,a+k);
    long int n;
    while((scanf("%lld",&n))==1)
    {
        if(n==0)
        {
            break;
        }
        for(long int m=3; m<=(n/2); m=m+2)
        {
            if(binary_search(v.begin(), v.end(), n-m))
            {
                printf("%ld = %ld + %ld\n",n,m,n-m);
                //cout<<n<<" = "<<m<<" + "<<n-m<<endl;
            }
        }
    }
    return 0;
}
