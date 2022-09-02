#ifndef __KRUSKAL__
#define __KRUSKAL__
#include <vector>
#include <algorithm>
#include "DSU.hpp"
#include "Edge.hpp"
using namespace std;

// E<v^2
// logE<2logV
// logE = O(logV)
// O(ElogE+ElogV) -> O(ElogV)
vector<Edge> kruskal(vector<pair<int, float>> adj[], int n)
{ // Kruskal’s MST algorithm
    DSU A(n);
    vector<Edge> edge_list;
    for (int u = 0; u < n; u++) // Put the edges on the array
    {
        for (pair<int, float> i : adj[u])
        {
            int v = i.first;
            float w = i.second;
            edge_list.push_back(Edge(u, v, w));
        }
    }
    sort(edge_list.begin(), edge_list.end()); // O(ElogE)
    // Our goal is to select V-1 edges

    vector<Edge> mst_edges;
    // O(ElogV)
    for (Edge e : edge_list)
    { // Combine equiv classes
        int u = e.from;
        int v = e.to;
        float w = e.weight;
        if (A.differ(u, v)) // O(logV)
        {
            A.unite(u, v); // Combine equiv sets // O(logV)
            mst_edges.push_back(Edge(u, v, w));
        }
    }
    return mst_edges;
}
#endif