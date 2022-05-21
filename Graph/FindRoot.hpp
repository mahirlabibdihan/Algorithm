#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Find a node from where every other node can be visited
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
    vector<bool> visited(n, false);
    stack<int> st;

    for (int i = 0; i < n; i++)
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

int findRoot(vector<int> adj[], int n)
{
    int root = topoSortDFS(adj, n).front();
    vector<bool> visited(n, false);
    stack<int> st;
    topoSortDFSHelp(root, adj, visited, st);
    if (st.size() == n)
    {
        return root;
    }
    else
    {
        return -1;
    }
}