#include<bits/stdc++.h>
using namespace std;
bool bfs(int s,vector<int>adj[],vector<int>&vis,vector<int>&lvl,vector<int>&prnt)
{
   
    
    vis[s]=1;
    lvl[s]=1;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int x=q.front();
        //cout<<x<<" ";
        if(vis[x]==1)
        return true;
        vis[x]=1;
        
        q.pop();
        for(int i=0;i<adj[x].size();i++)
        {
            if(vis[adj[x][i]]==0)
            {
                prnt[adj[x][i]]=x;
                lvl[adj[x][i]]=lvl[x]+1;
                //vis[adj[x][i]]=1;
                q.push(adj[x][i]);
            }
        }
    }

}
bool is_cycle(vector<int>adj[],vector<int>&vis,vector<int>&lvl,vector<int>&prnt,int n)
{
    for(int i=1;i<=n;i++)
    {
        cout<<i<<endl;
        
        if(!vis[i] && bfs(i,adj,vis,lvl,prnt))
        return true;
    }
    return false;
}
void shortest_path(vector<int>&prnt,int d)
{
    if(d==1)
    {
        cout<<d<<" ";
        return ;
    }
    shortest_path(prnt,prnt[d]);
    cout<<d<<" ";
}
int main()
{
    
    int n,e;
    cin >> n >> e;
    vector<int>adj[n+1],vis(n+1,0),lvl(n+1,-1),prnt(n+1,-1);
    for(int i=1;i<=e;i++)
    {
        int x,y;
        cin >> x>> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    //bfs(1,adj,vis,lvl,prnt);
    cout<<endl<<endl;
    // for(int i=1;i<lvl.size();i++)
    // {
    //     cout<<i<<' '<<lvl[i] << endl;

    // }
   // shortest_path(prnt,6);
   if(is_cycle(adj,vis,lvl,prnt,n))cout<<"YES"<<endl;
   else cout<<"NO"<<endl;
    
    


}