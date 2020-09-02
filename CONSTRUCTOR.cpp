#include<iostream>
using namespace std;
class dist
{
private:
    int s,n;
public:
    dist()
    {
        cout<<"Initializing constructor!!"<<endl;
        s=0;
    }
    ~dist()
    {
        cout<<"Destructing constructor!!"<<endl;
    }
    void showdist()
    {
        cin>>n;
        for(int i=1; i<=n; i++)
        {
            s=s+i;
        }
        cout<<s<<endl;
    }
};
int main(void)
{
    dist d1;
    //d1.showdist();
    return 0;
}
