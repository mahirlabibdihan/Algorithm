#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, vector<int> adj[], int count, int &max_count, int &farthest, int prev)
{
    if (count >= max_count)
    {
        max_count = count;
        farthest = u;
    }
    // cout << u << " " << count << endl;
    for (int v : adj[u])
    {
        if (v != prev)
        {
            dfs(v, adj, count + 1, max_count, farthest, u);
        }
    }
}
int getDiagram(vector<int> adj[], int n)
{
    int max_count = 0;
    int x, y;
    dfs(0, adj, 1, max_count, x, -1);
    // cout << x << endl;
    dfs(x, adj, 1, max_count, y, -1);
    // cout << y << endl;
    return max_count;
}