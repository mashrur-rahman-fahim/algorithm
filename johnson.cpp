#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool w_isNeg(vector<vector<pair<ll, ll>>> &adj)
{
    for (int i = 0; i < adj.size(); i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            if (adj[i][j].second < 0)
                return true;
        }
    }
    return false;
}
int mini(vector<vector<pair<ll, ll>>> &adj, vector<ll> &cost, vector<ll> &vis)
{
    int mi = INT_MAX;
    int mi_idx = 0;
    for (int i = 0; i < adj.size(); i++)
    {
        if (vis[i] == 0)
        {
            if (mi > cost[i])
            {
                mi = cost[i];
                mi_idx = i;
            }
        }
    }
    vis[mi_idx] = 1;
    return mi_idx;
}
vector<ll> dijkstra(int s, vector<vector<pair<ll, ll>>> &adj)
{

    vector<ll> vis(adj.size(), 0);
    vector<ll> cost;
    for (int i = 0; i < adj.size(); i++)
    {
        cost.push_back(INT_MAX);
    }
    cost[s] = 0;

    int n = adj.size();

    while (n--)
    {

        ll u = mini(adj, cost, vis);
        for (int i = 0; i < adj[u].size(); i++)
        {
            if (cost[adj[u][i].first] > cost[u] + adj[u][i].second)
            {
                cost[adj[u][i].first] = cost[u] + adj[u][i].second;
            }
        }
    }
    return cost;
}
void bellman(vector<vector<pair<ll, ll>>> &adj)
{
    int t = adj.size();
    vector<vector<pair<ll, ll>>> cpy(t + 1);
    int new_node = adj.size();
    for (int i = 0; i < adj.size(); i++)
    {
        cpy[new_node].push_back({i, 0});
    }
    for (int i = 0; i < adj.size(); i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
            cpy[i].push_back({adj[i][j].first, adj[i][j].second});
    }

    int n = cpy.size() - 1;
    vector<ll> cost;
    for (int i = 0; i < cpy.size(); i++)
    {
        cost.push_back(INT_MAX);
    }
    cost[new_node] = 0;

    int s = cpy.size();

    while (n--)
    {
        s = cpy.size();
        for (int i = new_node; i < s; i++)
        {
            for (int j = 0; j < cpy[i].size(); j++)
            {

                if (cost[cpy[i][j].first] > (cost[i] + cpy[i][j].second))
                {

                    cost[cpy[i][j].first] = cost[i] + cpy[i][j].second;
                }
            }
            if (i == new_node)
            {
                i = -1;
                s = s - 1;
            }
        }
    }

    for (int i = 0; i < adj.size(); i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            adj[i][j].second = adj[i][j].second + cost[i] - cost[adj[i][j].first];
        }
    }
}
void print(vector<vector<ll>> &total)
{
    for (int i = 0; i < total.size(); i++)
    {
        for (int j = 0; j < total[i].size(); j++)
        {
            cout << total[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    ll n, e;
    cin >> n >> e;
    vector<vector<pair<ll, ll>>> adj(n);
    for (int i = 0; i < e; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    vector<ll> res;
    vector<vector<ll>> total_cost;
    if (w_isNeg(adj))
        bellman(adj);
    for (int i = 0; i < adj.size(); i++)
    {
        res.clear();
        res = dijkstra(i, adj);
        total_cost.push_back(res);
    }
    print(total_cost);
}