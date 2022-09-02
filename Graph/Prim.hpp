#ifndef __PRIM__
#define __PRIM__
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include "Edge.hpp"
using namespace std;

// O(ElogV)

vector<Edge> prim(vector<pair<int, float>> adj[], int n, int start)
{                              // "u" is current vertex
    vector<int> parent(n, -1); // parent[I] stores I’s closest neighbor
    vector<float> edge_weight(n, INT_MAX);
    vector<bool> visited(n, false);
    priority_queue<pair<float, int>> pq;
    edge_weight[start] = 0;
    pq.push({0, start});
    vector<Edge> mst_edges;
    // There can be |E| push in pq and |E| pop in pq.
    // Each push/pop needs log|E| time
    // Time complexity: O(ElogE)

    // Our goal is to select n nodes with minimum edges
    for (int i = 0; i < n; i++) // O(V)
    {                           // Now build MST
        pair<float, int> temp;
        int u;
        float w;
        // There can be multiple occurence of same node in the queue
        do
        {
            if (pq.empty())
            {
                // Nothing to remove
                return mst_edges;
            }
            temp = pq.top();
            u = temp.second;
            w = -temp.first;
            pq.pop();
        } while (visited[u]);
        visited[u] = true;
        if (parent[u] != -1)
        {
            mst_edges.push_back(Edge(parent[u], u, w));
        }
        for (pair<int, float> i : adj[u]) // Sum of length of all adjacency list is 2|E|
        {
            int v = i.first;
            float w = i.second;
            if (!visited[v] && edge_weight[v] > w)
            { // Update edgeWeight
                edge_weight[v] = w;
                parent[v] = u;                 // Update who it came from
                pq.push({-edge_weight[v], v}); // Insert new distance in heap // O(logE)
            }
        }
    }
    return mst_edges;
}
#endif