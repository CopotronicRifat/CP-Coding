#include<iostream>
#include<cstdio>
using namespace std;
int main(void)
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0; i<n; i++)
    {
        printf("%d",a[i]);
    }
    return 0;
}
