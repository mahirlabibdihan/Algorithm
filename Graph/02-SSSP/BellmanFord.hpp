#include <vector>
#include <queue>
#include <climits>
using namespace std;

bool bellmanFord(vector<pair<int, float>> adj[], int n, int source, vector<float> &dist, vector<int> &parent)
{
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }
    dist[source] = 0;
    // O(VE)
    for (int i = 1; i <= n; i++)
    {
        // Relax all edges
        for (int u = 0; u < n; u++)
        {
            for (pair<int, float> e : adj[u])
            {
                int v = e.first;
                float w = e.second;
                if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                {
                    if (i == n)
                    {
                        return false; // Negative cycle
                    }
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                }
            }
        }
    }
    return true;
}