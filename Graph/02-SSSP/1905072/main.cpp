#include <iostream>
#include <vector>
#include "Dijkstra.hpp"
#include "BellmanFord.hpp"
using namespace std;
// For undirected graph
void printPath(int u, vector<int> &parent)
{
    if (parent[u] != -1)
    {
        printPath(parent[u], parent);
    }
    cout << u << " -> ";
}
int main()
{
    freopen("sssp.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<pair<int, float>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        float w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // adj[v].push_back({u, w});
    }
    int s, d;
    cin >> s >> d;
    vector<float> dist(n, INT_MAX);
    vector<int> parent(n, -1);

    // Task-1
    // dijkstra(adj, n, s, dist, parent);

    // Task-2
    if (!bellmanFord(adj, n, s, dist, parent))
    {
        cerr << "The graph contains a negative cycle" << endl;
        return EXIT_FAILURE;
    }
    cout << "The graph does not contain a negative cycle" << endl;
    //

    if (parent[d] == -1)
    {
        cerr << "Destination not reachable" << endl;
        return EXIT_FAILURE;
    }
    cout << "Shortest path cost: " << dist[d] << endl;
    printPath(parent[d], parent);
    cout << d << endl;

    return EXIT_SUCCESS;
}
