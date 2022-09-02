#include <vector>
#include <climits>
#include <queue>
using namespace std;

vector<int> toposort(vector<pair<int, float>> adj[], int n)
{
    vector<int> in_degree(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (pair<int, float> j : adj[i])
        {
            in_degree[j.first]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (in_degree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<bool> visited(n + 1, false);
    vector<int> topo_order;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        topo_order.push_back(u);
        for (pair<int, float> i : adj[u])
        {
            int v = i.first;
            if (!visited[v])
            {
                in_degree[v]--;
                if (in_degree[v] == 0)
                {
                    q.push(v);
                }
            }
        }
    }
    return topo_order;
}

void DAG_SSSP(vector<pair<int, float>> adj[], int n, int source, vector<float> &dist, vector<int> &parent)
{
    vector<int> topo_order = toposort(adj, n);
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }
    dist[source] = 0;
    for (int u : topo_order)
    {
        for (pair<int, float> i : adj[u])
        {
            int v = i.first;
            float w = i.second;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }
}