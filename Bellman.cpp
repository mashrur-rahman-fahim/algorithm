#include<bits/stdc++.h>
using namespace std;
#define ll long long
void Bellman(vector<vector<pair<ll,ll>>>&adj,vector<vector<pair<ll,ll>>>&pth)
{
    int s=adj.size()-1;
    while(s--)
    {
        for(int i=0;i<adj.size();i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                if(pth[adj[i][j].first][0].first>(pth[i][0].first+adj[i][j].second))
                {
                    pth[adj[i][j].first][0]={(pth[i][0].first+adj[i][j].second),i};
                }
            }
        }
    }
}
bool detect_neg(vector<vector<pair<ll,ll>>>&adj,vector<vector<pair<ll,ll>>>&pth)
{
    for(int i=0;i<adj.size();i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            if(pth[adj[i][j].first][0].first>(pth[i][0].first+adj[i][j].second))
                {
                    return true;
                }
        }
    }
    return false;
}
int main()
{
    int n,e;
    cin>>n>>e;
    vector<vector<pair<ll,ll>>>adj(n),pth(n);
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
    pth[0][0].first=0;
    Bellman(adj,pth);
    if(detect_neg(adj,pth))
    cout << "yes"<<endl;
    cout<<pth[4][0].first<<endl;
}
// input 
// 5
// 10
// 1 2 5
// 1 3 8
// 1 4 -4
// 2 1 -2
// 3 2 -3
// 3 4 9
// 4 0 2
// 4 2 7
// 0 1 6
// 0 3 7
