///lcs
#include<bits/stdc++.h>
using namespace std;
void lcs(string s1,string s2)
{
    int n=s1.size(),m=s2.size();
    int l[n+1][m+1];
    for(int i=0; i<=n; i++)
        for(int j=0; j<=m; j++)
            if(i==0||j==0)
                l[i][j]=0;
            else if(s1[i-1]==s2[j-1])
                l[i][j]=l[i-1][j-1]+1;
            else
                l[i][j]=max(l[i-1][j],l[i][j-1]);
    //return l[n][m];
    int ld=l[n][m];
    cout<<"here matching: "<<ld<<"  char "<<endl;
    char ls[ld+1];
    ls[ld]='\0';
    while(n>0||m>0)
    {
        if(s1[n-1]==s2[m-1])
        {
            ls[ld-1]=s1[n-1];
            n--,m--,ld--;
        }
        else if(l[n][m]>l[n][m-1])
            n--;
        else
            m--;
    }
    cout<<ls<<endl;
}
int main()
{
    string s1,s2;
    cout<<"enter first & 2nd string"<<endl;
    cin>>s1>>s2;
    lcs(s1,s2);
}
