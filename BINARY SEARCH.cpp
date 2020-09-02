#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[]={1,4,7,3,7,8,4,6,7};
    if(binary_search(a,a+7,10))
    {
        cout<<"Found"<<endl;
    }
    else
    {
        cout<<"Not Found"<<endl;
    }
    return 0;
}
