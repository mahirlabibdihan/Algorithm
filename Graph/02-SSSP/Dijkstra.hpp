#include <vector>
#include <queue>
#include <climits>
using namespace std;

void dijkstra(vector<pair<int, float>> adj[], int n, int source, vector<float> &dist, vector<int> &parent)
{
    vector<bool> visited(n, false);
    priority_queue<pair<float, int>> pq;
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }
    dist[source] = 0;
    pq.push({-dist[source], source});

    // Initialize heap array
    // O(ElogV)
    for (int i = 0; i < n; i++)
    { // Now, get distances
        pair<int, float> temp;
        int u;
        do
        {
            if (pq.empty())
            {
                // Nothing to remove
                return;
            }
            temp = pq.top();
            u = temp.second;
            pq.pop(); // O(logV)
        } while (visited[u]);
        visited[u] = true;
        for (pair<int, float> i : adj[u]) // Sum of length of all adjacency list is 2|E|
        {
            int v = i.first;
            float w = i.second;

            // RELAX
            if (!visited[v] && dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;  // Update distance
                parent[v] = u;          // Update who it came from
                pq.push({-dist[v], v}); // Insert new distance in heap // O(logV)
            }
        }
    }
}