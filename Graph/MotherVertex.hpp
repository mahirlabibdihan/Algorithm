#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Find a node from where every other node can be visited
void DFS(int u, vector<int> adj[], vector<bool> &visited)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            DFS(v, adj, visited, st);
        }
    }
}

int getMother(vector<int> adj[], int n)
{
    vector<bool> visited(n, false);
    int v;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            DFS(i, adj, visited);
            v = i;
        }
    }
    return v;
}

int findMother(vector<int> adj[], int n)
{
    int mother = getMother(adj, n);
    vector<bool> visited(n, false);
    DFS(mother, adj, visited);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            return -1;
        }
    }
    return mother;
}