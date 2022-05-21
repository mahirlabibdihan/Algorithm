#include <vector>
using namespace std;
// This function is a variation of DFSUtil() in https://www.geeksforgeeks.org/archives/18212
bool checkCycle(int u, vector<int> adj[], vector<bool> &visited, vector<bool> &recStack)
{
    if (visited[u] == false)
    {
        visited[u] = true;
        recStack[u] = true;
        for (auto v : adj[u])
        {
            if (!visited[v] && checkCycle(v, adj, visited, recStack))
            {
                return true;
            }
            else if (recStack[v])
            {
                return true;
            }
        }
    }
    recStack[u] = false; // remove the vertex from recursion stack
    return false;
}

bool isDAG(vector<int> adj[], int n)
{
    vector<bool> visited(n);
    vector<bool> recStack(n);
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && checkCycle(i, adj, visited, recStack))
        {
            return false;
        }
    }
    return true;
}