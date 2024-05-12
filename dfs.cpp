#include<bits/stdc++.h>
using namespace std;
void dfs(int s,vector<int>adj[],vector<int>&vis)
{
    vis[s]=1;
    cout<<s<<" ";
    for(int i=0;i<adj[s].size();i++)
    {
        if(vis[adj[s][i]]==0)
        dfs(adj[s][i],adj,vis);
    }

}
int main()
{
    int n,e;
    cin>>n>>e;
    vector<int>adj[n],vis(n,0);
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    //    adj[y].push_back(x);
    }
    dfs(0,adj,vis);

}