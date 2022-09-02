// A C++ program to find maximal
// Bipartite matching.
#include <iostream>
#include <cstring>
#include <vector>
#include "FordFulkerson.hpp"
using namespace std;

int main()
{
    // Input
    int m, n;
    cin >> m >> n;
    int x, y;
    cin >> x >> y;
    int p;
    cin >> p;

    int V = x + y + 2;
    vector<pair<int, int>> adj[V];
    for (int i = 0; i < p; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({x + v, m});
    }

    int s = V - 2;
    int t = V - 1;

    // Connect boys to source
    for (int u = 0; u < x; u++)
    {
        adj[s].push_back({u, n});
    }

    // Connect girls to sink
    for (int u = 0; u < y; u++)
    {
        adj[x + u].push_back({t, n});
    }

    // Find max flow of created graph
    vector<vector<int>> capacity(V, vector<int>(V, 0));
    cout << fordFulkerson(adj, V, s, t, capacity) << endl;

    // Output
    for (int u = 0; u < x; u++)
    {
        for (auto [v, w] : adj[u])
        {
            cout << u << " " << v - x << " " << capacity[v][u] << endl;
        }
    }
}
