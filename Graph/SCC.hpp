#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Print strongly connected component
void getSCC(int u, vector<int> adj[], vector<bool> &visited, vector<int> &scc)
{
    visited[u] = true;
    scc.push_back(u);
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            getSCC(v, adj, visited, scc);
        }
    }
}
void fillOrder(int u, vector<int> adj[], vector<bool> &visited, stack<int> &st)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            fillOrder(v, adj, visited, st);
        }
    }
    st.push(u);
}

// O(E)
void transpose(vector<int> adj[], vector<int> adjTr[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j : adj[i])
        {
            adjTr[j].push_back(i);
        }
    }
}
bool isSCC(vector<int> adj[], int n)
{
    vector<bool> visited(n + 1, false);
    stack<int> st;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            fillOrder(i, adj, visited, st);
        }
    }
    vector<int> adjTr[n + 1];
    transpose(adj, adjTr, n);
    fill(visited.begin(), visited.end(), false);
    vector<vector<int>> sccs;
    int u = st.top();
    st.pop();
    vector<int> scc;
    getSCC(u, adjTr, visited, scc);
    return (scc.size() == n);
}

vector<vector<int>> getSCCs(vector<int> adj[], int n)
{
    vector<bool> visited(n + 1, false);
    stack<int> st;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            fillOrder(i, adj, visited, st);
        }
    }
    vector<int> adjTr[n + 1];
    transpose(adj, adjTr, n);
    fill(visited.begin(), visited.end(), false);
    vector<vector<int>> sccs;
    while (!st.empty())
    {
        int u = st.top();
        st.pop();
        if (!visited[u])
        {
            vector<int> scc;
            getSCC(u, adjTr, visited, scc);
            sccs.push_back(scc);
        }
    }
    return sccs;
}
