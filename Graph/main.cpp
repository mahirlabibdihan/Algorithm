#include <iostream>
#include "ShortestPath.hpp"
int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, float>> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        float w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    vector<float> dist(n);
    vector<int> parent(n);
    DAG_SSSP(adj, n, 1, dist, parent);
    for (int i = 0; i < n; i++)
    {
        cout << dist[i] << " ";
    }
}
/*
9 12
0 1 4
0 7 8
1 7 11
1 2 8
7 8 7
7 6 1
8 6 6
2 3 7
2 8 2
2 5 4
6 5 2
3 5 14
*/