#include <vector>
using namespace std;
void DFS(vector<vector<int>> &adj, int u)
{ // Depth first search
  // PreVisit(G, v); // Take appropriate action
    int n = adj.size();
    vector<bool> visited(n);
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            DFS(adj, v);
        }
    }
    // PostVisit(G, v); // Take appropriate action
}