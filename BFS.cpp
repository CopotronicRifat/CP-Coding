#include<bits/stdc++.h>
using namespace std;
void bfs(vector<int>v[],int s,int des)
{
    int visit[100];
    int d[100];
    int pre[100];
    for(int i=1; i<100; i++)
    {
        visit[i]=0;
        d[i]=12345;
        pre[i]=-1;
    }
    visit[s]=1;
    d[s]=0;
    pre[s]=-1;
    queue<int>q;
    stack<int>ss;
    q.push(s);
    vector<int>::iterator it;
    while(!q.empty())
    {
        int u=q.front();
        for(it=v[u].begin(); it!=v[u].end(); it++)
            if(!visit[*it])
            {
                visit[*it]=1;
                d[*it]=d[u]+1;
                pre[*it]=u;
                //cout<<*it<<endl;
                q.push(*it);
            }
        q.pop();
    }
    cout<<"sorce to destination distance : "<<d[des]<<endl;
    cout<<"destination previous node is: "<<pre[des]<<endl;
    cout<<"destination to sorce traverse back to front"<<endl<<endl;
    cout<<des;
    while(pre[des]!=-1)
    {
        cout<<" "<<pre[des];
        des=pre[des];
    }
    //cout<<" "<<s<<endl;

}
int main()
{
    vector<int>v[100];
    int vertex,edge;
    cout<<"enter number of edge"<<endl;
    cin>>edge;
    for(int i=0; i<edge; i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);

    }
    int s,des;
    cout<<"enter sorce and destination node "<<endl;
    cin>>s>>des;
    bfs(v,s,des);
}
