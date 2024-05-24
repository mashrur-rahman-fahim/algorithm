#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n,e;
    cin>>n>>e;
    vector<vector<pair<int,int>>>adj(n);
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});

    }
    vector<ll>w(n),p(n),vis(n,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    for(int i=0;i<n;i++){
        p[i]=i;
    w[i]=INT_MAX;
    }
    w[0]=0;
    p[0]=0;
    for(int i=0;i<n;i++)
    {
        q.push({w[i],i});
    }

    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        cout<<u<<endl;
        vis[u]=1;
        for(int i=0;i<adj[u].size();i++)
        {
            if(!vis[adj[u][i].first] && adj[u][i].second<w[adj[u][i].first])
            {
                p[adj[u][i].first]=u;
                w[adj[u][i].first]=adj[u][i].second;
                q.push({w[adj[u][i].first],adj[u][i].first});
            }
        }
    }
    ll cost=0;
    for(int i=0;i<n;i++)
    {
        if(i!=0){
        cout<<p[i]<<'-'<<i<<"="<<w[i]<<endl;
        cost=cost+w[i];}
    }
    cout<<cost<<endl;
    



}