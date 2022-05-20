#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// Topological sorting is possible only for DAG
// A DAG G has at least one vertex with in-degree 0 and one vertex with out-degree 0.
// Topological sorting is possible even when the DAG has disconnected components.

void topoSortDFSHelp(int u, vector<int> adj[], vector<bool> &visited, stack<int> &st)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            topoSortDFSHelp(v, adj, visited, st);
        }
    }
    st.push(u);
}

vector<int> topoSortDFS(vector<int> adj[], int n)
{
    vector<bool> visited(n + 1, false);
    stack<int> st;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            topoSortDFSHelp(i, adj, visited, st);
        }
    }
    vector<int> topo_order;
    while (!st.empty())
    {
        topo_order.push_back(st.top());
        st.pop();
    }
    return topo_order;
}

// Kahn's algorithm
vector<int> topoSortBFS(vector<int> adj[], int n)
{
    vector<int> in_degree(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j : adj[i])
        {
            in_degree[j]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
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
        for (int v : adj[u])
        {
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