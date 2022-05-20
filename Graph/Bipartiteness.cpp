#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Connected graph
bool isBipartite(vector<vector<int>> &adj, int start)
{
	int V = adj.size();
	vector<int> color(V, 0);
	queue<int> q;
	q.push(start); // Initialize Q
	color[start] = 1;
	while (!q.empty())
	{ // Process all vertices on Q
		int u = q.front();
		q.pop();
		// PreVisit(G, v); // Take appropriate action
		for (int v : adj[u])
		{
			if (!color[v])
			{
				color[v] = -color[u];
				q.push(v);
			}
			else if (color[u] == color[v])
			{
				return false;
			}
		}
	}
	return true;
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cout << (isBipartite(adj, 0) ? "Yes" : "No") << endl;
}