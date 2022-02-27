#include <vector>
#include <queue>
using namespace std;
void BFS(vector<vector<int>> &adj, int start)
{
    int n = adj.size();
    vector<bool> visited(n);
    queue<int> q;
    q.push(start); // Initialize Q
    visited[start] = true;
    while (!q.empty())
    { // Process all vertices on Q
        int u = q.front();
        q.pop();
        // PreVisit(G, v); // Take appropriate action
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}