#include<bits/stdc++.h>
using namespace std;
int find(int x,vector<int>&path)
{
    if(path[x]==x)return x;
    find(path[x],path);
}

int main()
{
    int n,e;
    cin>>n>>e;
    vector<vector<int>>adj;
    for(int i=0;i<e;i++)
    {
        int w,u,v;
        cin>>u>>v>>w;
        adj.push_back({w,u,v});
    }
    sort(adj.begin(),adj.end());
    vector<int >path(n);
    vector<pair<int,int>>t;
    int cost=0;
    for(int i=0;i<n;i++)
    path[i]=i;
    for(int i=0;i<adj.size();i++)
    {
        int x=find(adj[i][1],path);
        int y=find(adj[i][2],path);
        if(x!=y)
        {
            t.push_back({adj[i][1],adj[i][2]});
            cost=cost+adj[i][0];
            // cout<<adj[i][1]<<'-'<<adj[i][2]<<"= "<<adj[i][0]<<endl;
            path[y]=x;

        }
    }
    for(int i=0;i<t.size();i++)
    cout<<t[i].first<<"-"<<t[i].second<<endl;
    cout<<cost<<endl;

}