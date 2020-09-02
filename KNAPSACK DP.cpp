#include<bits/stdc++.h>
using namespace std;
void knaspack(int wt[],int vl[],int n,int kn)
{
    int k[n+1][kn+1];
    for(int i=0; i<=n; i++)
        for(int j=0; j<=kn; j++)
            if(i==0||j==0)
                k[i][j]=0;
            else if(j>=wt[i-1])
                k[i][j]=max(vl[i-1]+k[i-1][j-wt[i-1]],k[i-1][j]);
            else
                k[i][j]=k[i-1][j];
    //return k[n][kn];
    int itm=k[n][kn];
    cout<<"knaspack vlue is: "<<itm<<endl;
    cout<<"taken data : "<<endl;
    vector<int>v;
    while(n>0||kn>0)
    {
        if(k[n][kn]==k[n-1][kn])
        {
            //cout<<k[n][kn]<<" "<<k[n-1][kn]<<endl;
            n--;
        }
        else
        {
            //cout<<k[n][kn]<<" "<<k[n-1][kn-1]<<endl;
            //a[itm-1]=n-1;

            kn-=wt[n-1];

            v.push_back(n-1);
            n--;
        }
    }
    for(int i=v.size()-1; i>=0; i--)
        cout<<wt[v[i]]<<endl;
}

int main()
{
    int n,kn;
    cin>>n;
    int wt[n+1],vl[n+1];
    cout<<"enter weight of data"<<endl;
    for(int i=0; i<n; i++)
        cin>>wt[i];
    cout<<"enter value"<<endl;
    for(int i=0; i<n; i++)
        cin>>vl[i];
    cout<<"enter knaspack size:"<<endl;
    cin>>kn;
    knaspack(wt,vl,n,kn);
}
