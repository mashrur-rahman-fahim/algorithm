#include <bits/stdc++.h>
using namespace std;
void Topological(int s, vector<pair<long long int, long long int>> adj[], vector<int> &vis, stack<int> &res, int w)
{
	vis[s] = 1;
	// cout<<s<<endl;
	for (int i = 0; i < adj[s].size(); i++)
	{
		if (vis[adj[s][i].first] == 0)
			Topological(adj[s][i].first, adj, vis, res, adj[s][i].second);
	}
	res.push(s);
}
void Topological_sort(int n, vector<pair<long long int, long long int>> adj[], vector<int> &vis, stack<int> &res)
{
	for (int i = 0; i < n; i++)
	{
		if (vis[i] == 0)
		{
			Topological(i, adj, vis, res, 0);
		}
	}
}
void print_shortest_Path(vector<pair<long long int, long long int>> pth[], int s, int d, int des)
{
	if (d == s)
	{

		cout << endl
			 << "THE COST IS: " << pth[des][0].first << endl;
		cout << "AND Shortest Path from Source " << s << " to: ";

		return;
	}

	print_shortest_Path(pth, s, pth[d][0].second, des);
	cout << d << " ";
}
void shortest_path(int n, stack<int> &res, vector<pair<long long int, long long int>> adj[], vector<pair<long long int, long long int>> pth[], int s, int d)
{

	while (!res.empty())
	{
		int u = res.top();
		// cout<<u<<endl;
		res.pop();
		for (int i = 0; i < adj[u].size(); i++)
		{

			if (pth[adj[u][i].first][0].first >= (pth[u][0].first + adj[u][i].second))
			{

				pth[adj[u][i].first][0] = {pth[u][0].first + adj[u][i].second, u};
			}
		}
	}

	print_shortest_Path(pth, s, d, d);
}

int main()
{
	int n, e;
	cout << "INPUT NODES AND EDGES: " << endl;
	cin >> n >> e;

	vector<pair<long long int, long long int>> adj[n], pth[n]; //{cost,from where it should come} for pth
	vector<int> vis(n, 0);
	stack<int> res, pr; // for a zero based graph
	cout << "Input U V AND COST: " << endl;
	for (int i = 0; i < e; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].push_back({y, w});
	}
	for (int i = 0; i < n; i++)
	{
		pth[i].push_back({INT_MAX, INT_MAX});
	}
	cout << "INPUT SOURCE AND DESTINATION: " << endl;
	int s, d;
	cin >> s >> d;
	pth[s][0].first = 0;

	Topological_sort(n, adj, vis, res);
	shortest_path(n, res, adj, pth, s, d);
}
//input graph
// 6
// 10
// 0 1 5
// 0 2 3
// 1 2 2
// 1 3 6
// 2 3 7
// 2 4 4
// 2 5 2
// 3 4 -1
// 3 5 1
// 4 5 -2
// 1 5