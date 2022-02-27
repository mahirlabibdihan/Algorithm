#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
// Prim’s MST algorithm: priority queue version
// MST exists only for connected graph.

// O(ElogV)
int Prim(vector<vector<pair<int, int>>> &adj, int start)
{ // "u" is current vertex
    int V = adj.size();
    vector<int> parent(V, -1); // parent[I] stores I’s closest neighbor
    vector<int> edgeWeight(V, INT_MAX);
    vector<bool> visited(V, false);
    priority_queue<pair<int, int>> pq; // Create heap - O(E)
    edgeWeight[start] = 0;
    pq.push({0, start}); // O(log(E))
    int minCost = 0;

    // There will be 2|E| push in pq and 2|E| pop in pq.
    // Each push/pop needs log|E| time

    // Our goal is to select V nodes with minimum edges
    for (int i = 0; i < V; i++) // O(V)
    {                           // Now build MST
        pair<int, int> temp;
        int u, w;
        // There can be multiple occurence of same node in the queue
        do
        {
            if (pq.empty())
            {
                cout << "Error: Disconnected Graph" << endl;
                return minCost; // Nothing to remove
            }
            temp = pq.top();
            u = temp.second;
            w = -temp.first;
            pq.pop();
        } while (visited[u]);
        visited[u] = true;
        minCost += w; // Since we have store the negative weights in pq
        cout << parent[u] << " " << u << " " << w << endl;
        for (pair<int, int> i : adj[u]) // Sum of length of all adjacency list is 2|E|
        {
            int v = i.first;
            int w = i.second;
            if (edgeWeight[v] > w) // If any vertex is already visited than this condition will always be false for that vertex. So we don't need to check that explicitly
            {                      // Update edgeWeight
                edgeWeight[v] = w;
                parent[v] = u;                // Update who it came from
                pq.push({-edgeWeight[v], v}); // Insert new distance in heap
            }
        }
        /*******************************************/
    }
    return minCost;
}