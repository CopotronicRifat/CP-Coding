#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int a[10] = {2, 4, 6, 7, 9, 11, -5, 8, 0, 7};
    sort(a+6, a+10);
    for(int i=0; i< 10; i++)
    {
        cout<< a[i] <<endl;
    }
    return 0;
}
