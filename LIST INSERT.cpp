#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector <int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.insert(l.begin()+1,0);
    for(int i=0; i<l.size(); i++)
    {
        cout<<l[i]<<endl;
    }
    return 0;
}
