#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
class DSU
{
private:
    vector<int> parent; // Node array
    int find(int v)     // Find root
    {
        if (parent[v] == -1)
            return v;
        return parent[v] = find(parent[v]); // At root
    }

public:
    DSU(int n) : parent(n, -1) {} // Constructor
    void unite(int u, int v)      // Merge equivalences
    {
        int s1 = find(u); // O(logn)
        int s2 = find(v); // O(logn)
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
    int from, to;
    float weight;
    Edge() {}
    Edge(int from, int to, float weight)
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

// Topological sorting is possible only for DAG
// A DAG G has at least one vertex with in-degree 0 and one vertex with out-degree 0.
// Topological sorting is possible even when the DAG has disconnected components.

void topoSortDFSHelp(int u, vector<int> adj[], vector<bool> &visited, stack<int> &st)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            topoSortDFSHelp(v, adj, visited, st);
        }
    }
    st.push(u);
}

vector<int> topoSortDFS(vector<int> adj[], int n)
{
    vector<bool> visited(n + 1, false);
    stack<int> st;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            topoSortDFSHelp(i, adj, visited, st);
        }
    }
    vector<int> topo_order;
    while (!st.empty())
    {
        topo_order.push_back(st.top());
        st.pop();
    }
    return topo_order;
}

// Kahn's algorithm
vector<int> topoSortBFS(vector<int> adj[], int n)
{
    vector<int> in_degree(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j : adj[i])
        {
            in_degree[j]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (in_degree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<bool> visited(n + 1, false);
    vector<int> topo_order;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        topo_order.push_back(u);
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                in_degree[v]--;
                if (in_degree[v] == 0)
                {
                    q.push(v);
                }
            }
        }
    }
    return topo_order;
}

// Print strongly connected component
void getSCC(int u, vector<int> adj[], vector<bool> &visited, vector<int> &scc)
{
    visited[u] = true;
    scc.push_back(u);
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            getSCC(v, adj, visited, scc);
        }
    }
}
void fillOrder(int u, vector<int> adj[], vector<bool> &visited, stack<int> &st)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            fillOrder(v, adj, visited, st);
        }
    }
    st.push(u);
}

// O(E)
void transpose(vector<int> adj[], vector<int> adjTr[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j : adj[i])
        {
            adjTr[j].push_back(i);
        }
    }
}

vector<vector<int>> getSCCs(vector<int> adj[], int n)
{
    vector<bool> visited(n + 1, false);
    stack<int> st;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            fillOrder(i, adj, visited, st);
        }
    }
    vector<int> adjTr[n + 1];
    transpose(adj, adjTr, n);
    fill(visited.begin(), visited.end(), false);
    vector<vector<int>> sccs;
    while (!st.empty())
    {
        int u = st.top();
        st.pop();
        if (!visited[u])
        {
            vector<int> scc;
            getSCC(u, adjTr, visited, scc);
            sccs.push_back(scc);
        }
    }
    return sccs;
}

void DFS(vector<vector<int>> &adj, int u)
{ // Depth first search
  // PreVisit(G, v); // Take appropriate action
    int n = adj.size();
    vector<bool> visited(n);
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            DFS(adj, v);
        }
    }
    // PostVisit(G, v); // Take appropriate action
}
void BFS(vector<vector<int>> &adj, int start)
{
    int n = adj.size();
    vector<bool> visited(n);
    queue<int> q;
    q.push(start); // Initialize Q
    visited[start] = true;
    while (!q.empty())
    { // Process all vertices on Q
        int u = q.front();
        q.pop();
        // PreVisit(G, v); // Take appropriate action
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int maxBPM(vector<vector<bool>> bpGraph, int n, int m)
{
    int V = n + m + 2;
    int s = V - 2;
    int t = V - 1;
    vector<pair<int, int>> adj[V];
    for (int u = 0; u < n; u++)
    {
        for (int v = 0; v < m; v++)
        {
            if (bpGraph[u][v])
            {
                adj[u].push_back({n + v, 1});
            }
        }
    }
    for (int u = 0; u < n; u++)
    {
        adj[s].push_back({u, 1});
    }
    for (int u = 0; u < m; u++)
    {
        adj[n + u].push_back({t, 1});
    }
    return fordFulkerson(adj, V, s, t);
}

// Print min s-t cut
// for (int u = 0; u < n; u++)
// {
//     if (reachable[u])
//     {
//         for (auto [v, w] : adj[u])
//         {
//             if (!reachable[v])
//             {
//                 cout << u << " - " << v << endl;
//             }
//         }
//     }
// }

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

int64_t bfs(vector<int> adj[], int n, vector<vector<int64_t>> capacity, int s, int t, vector<int> &parent)
{
    fill(parent.begin(), parent.end(), -1);
    queue<pair<int, int64_t>> q;
    q.push({s, LLONG_MAX});
    while (!q.empty())
    {
        auto [u, flow] = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (v != s && parent[v] == -1 && capacity[u][v] > 0)
            {
                parent[v] = u;
                int64_t new_flow = min(flow, capacity[u][v]);
                if (v == t)
                {
                    return new_flow;
                }
                q.push({v, new_flow});
            }
        }
    }
    return 0;
}

int64_t fordFulkerson(vector<pair<int, int64_t>> adj[], int n, int s, int t)
{
    vector<vector<int64_t>> capacity(n, vector<int64_t>(n, 0));
    // O(E)
    for (int u = 0; u < n; u++)
    {
        for (auto [v, w] : adj[u])
        {
            capacity[u][v] = w;
        }
    }

    vector<int> new_adj[n];
    // O(E)
    for (int u = 0; u < n; u++)
    {
        for (auto [v, w] : adj[u])
        {
            new_adj[u].push_back(v);
            new_adj[v].push_back(u);
        }
    }
    int64_t flow = 0;
    while (true)
    {
        vector<int> parent(n);
        int64_t new_flow = bfs(new_adj, n, capacity, s, t, parent); // O(V+E)
        if (new_flow == 0)
        {
            break;
        }
        flow += new_flow;
        // O(V)
        for (int cur = t; cur != s; cur = parent[cur])
        {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
        }
    }
    return flow;
}
// O(V)
int isEdge(vector<pair<int, int64_t>> adj[], int u, int v)
{
    for (int i = 0; i < adj[u].size(); i++)
    {
        if (adj[u][i].first == v)
        {
            return i;
        }
    }
    return -1;
}
int isParallelEdge(vector<pair<int, int64_t>> adj[], int u, int v, int n)
{
    for (int i = 0; i < adj[u].size(); i++)
    {
        if (adj[u][i].first >= n)
        {
            int k = adj[u][i].first;
            if (adj[k].front().first == v)
            {
                return i;
            }
        }
    }
    return -1;
}
int main()
{
    int n, m;
    cin >> n >> m;
    int extra = 0;
    vector<pair<int, int64_t>> adj[n + m / 2];
    // O(VE)
    for (int i = 0; i < m; i++)
    {
        int64_t u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        if (isEdge(adj, u, v) != -1)
        {
            int j = isEdge(adj, u, v);
            adj[u][j].second += w;
            if (isParallelEdge(adj, v, u, n) != -1)
            {
                int k = isParallelEdge(adj, v, u, n);
                adj[v][k].second += w;
                adj[adj[v][k].first].front().second += w;
            }
        }
        else if (isParallelEdge(adj, u, v, n) != -1)
        {
            int k = isParallelEdge(adj, u, v, n);
            adj[u][k].second += w;
            adj[adj[v][k].first].front().second += w;
        }
        else if (isEdge(adj, v, u) != -1)
        {
            // cout << "3" << endl;
            adj[u].push_back({n + extra, w});
            adj[n + extra].push_back({v, w});
            extra++;
        }
        else
        {
            adj[u].push_back({v, w});
        }
    }
    cout << fordFulkerson(adj, n + extra, 0, n - 1) << endl;
}