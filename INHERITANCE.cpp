#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    class A
    {
    private:
        int n=0;
    public:
        for(int i=1;i<=n;i++)
        {
            n=n+i;
        }
        cout<<n<<endl;
    };
    class B
    {
    private:
        int m=0;
    public:
        for(int j=1;j<=m;j++)
        {
            m=m+j;
        }
        cout<<m<<endl;
    };
    class C: private A, private B
    {
        int d=n-m;
        cout<<d<<endl;
    };
    class D: private C
    {
        cout<<abs(d)<<endl;
    };

    return 0;
}
