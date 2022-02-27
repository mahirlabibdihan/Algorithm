#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;
int Kruskal(vector<vector<pair<int, int>>> adj)
{ // Kruskal’s MST algorithm
    class DSU
    {
    private:
        vector<int> parent;      // Node array
        int find(int curr) const // Find root
        {
            while (parent[curr] != -1)
                curr = parent[curr];
            return curr; // At root
        }

    public:
        DSU(int n) : parent(n, -1) {} // Constructor
        void unite(int u, int v)      // Merge equivalences
        {
            int s1 = find(u);
            int s2 = find(v);
            if (s1 != s2)
            {
                parent[s2] = s1;
            }
        }
        bool differ(int u, int v) // True if not in same tree
        {
            return find(u) != find(v);
        }
    };
    class Edge
    {
    public:
        int from, to, weight;
        Edge() {}
        Edge(int from, int to, int weight)
        {
            this->from = from;
            this->to = to;
            this->weight = weight;
        }
        bool operator<(const Edge &e)
        {
            return this->weight < e.weight;
        }
    };
    int V = adj.size();
    DSU A(V);                   // Equivalence class array
    vector<Edge> edgeList;      // Create heap - O(E) // Create
    for (int u = 0; u < V; u++) // Put the edges on the array
    {
        for (pair<int, int> i : adj[u])
        {
            int v = i.first;
            int w = i.second;
            edgeList.push_back(Edge(u, v, w));
        }
    }
    sort(edgeList.begin(), edgeList.end());
    // Our goal is to select V-1 edges
    int minCost = 0;
    int mstEdges = 0;
    for (Edge e : edgeList)
    { // Combine equiv classes
        Edge temp;
        int u = e.from;
        int v = e.to;
        int w = e.weight;
        if (A.differ(u, v))
        {
            A.unite(u, v); // Combine equiv sets
            cout << u << " " << v << " " << w << endl;
            minCost += w;
            mstEdges++;
        }
    }
    if (mstEdges < V - 1)
    {
        cout << "Error: Disconnected Graph" << endl;
    }
    return minCost;
}