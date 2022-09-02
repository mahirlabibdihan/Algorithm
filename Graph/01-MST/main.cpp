#include "Prim.hpp"
#include "Kruskal.hpp"

float getCost(vector<Edge> mst)
{
    float cost = 0;
    for (Edge e : mst)
    {
        cost += e.weight;
    }
    return cost;
}
void printMst(vector<Edge> mst)
{
    int n = mst.size();
    cout << '{';
    for (int i = 0; i < n; i++)
    {
        cout << '(' << mst[i].from << ',' << mst[i].to << ')';
        if (i < n - 1)
        {
            cout << ',';
        }
    }
    cout << '}' << endl;
}

// For undirected graph
int main()
{
    freopen("mst.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<pair<int, float>> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        float w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<Edge> mstK = kruskal(adj, n);
    vector<Edge> mstP = prim(adj, n, 0);
    if (mstK.size() < n - 1)
    {
        cerr << "ERROR: Disconnected graph" << endl;
        return EXIT_FAILURE;
    }
    cout << "Cost of the minimum spanning tree : " << getCost(mstK) << endl;
    cout << "List of edges selected by Prim's: ";
    printMst(mstP);
    cout << "List of edges selected by Kruskal's: ";
    printMst(mstK);
}
/*
7 13
0 1 14
0 2 21
0 3 5
0 5 7
1 6 19
1 5 2
1 2 15
2 4 4
2 6 3
3 4 22
4 5 15
5 6 18
6 4 2

V-1+V-2+V-3+...+V-(V-2)+V-(V-1)
V*V-(1+2+3+...+V-2+V-1)
V*V - V(V-1)/2
V*V - V*V/2 + V/2
V*(V+1)/2
*/