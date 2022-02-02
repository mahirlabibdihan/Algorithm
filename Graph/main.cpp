#include "Graph/LGraph.hpp"
#include "Prim.hpp"
int main()
{
    int n, m;
    cin >> n >> m;
    Graph *G = new LGraph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        G->setEdge(u, v, w);
        G->setEdge(v, u, w);
    }
    Prim(G, new int[n], 0);
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