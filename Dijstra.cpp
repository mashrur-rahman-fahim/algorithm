#include<bits/stdc++.h>
using namespace std;
#define ll long long
int min1(vector<vector<pair<ll,ll>>>&adj,vector<vector<pair<ll,ll>>>&pth,vector<int>&vis)
{
    int m=INT_MAX;int m_idx=0;
    for(int i=0;i<adj.size();i++)
    {
        if(vis[i]==0)
        {
            if(m>pth[i][0].first)
            {
                m_idx=i;
                m=pth[i][0].first;
            }
        }
    }
    vis[m_idx]=1;
    return m_idx;
}
void dijkstra(vector<vector<pair<ll,ll>>>&adj,vector<vector<pair<ll,ll>>>&pth,vector<int>&vis)
{
    int n=adj.size();
    while(n--){
    int u=min1(adj,pth,vis);
    
    for(int i=0;i<adj[u].size();i++)
    {
        if(pth[adj[u][i].first][0].first>(pth[u][0].first+adj[u][i].second))
        {
            pth[adj[u][i].first][0]={(pth[u][0].first+adj[u][i].second),u};
        }
    }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    vector<vector<pair<ll,ll>>>adj(n),pth(n);//{cost,from where it comes}
    vector<int>vis(n,0);
    for(int i=0;i<e;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
    }
    for(int i=0;i<n;i++)
    {
        pth[i].push_back({INT_MAX,INT_MAX});
    }
    int s;
    cin>>s;
    pth[s][0].first=0;
    dijkstra(adj,pth,vis);
    


}