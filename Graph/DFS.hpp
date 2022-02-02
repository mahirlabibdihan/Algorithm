#include "Graph/Graph.hpp"

void DFS(Graph *G, int v)
{ // Depth first search
    // PreVisit(G, v); // Take appropriate action
    G->setMark(v, VISITED);
    for (int w = G->first(v); w < G->n(); w = G->next(v, w))
    {
        if (G->getMark(w) == UNVISITED)
        {
            DFS(G, w);
        }
    }
    // PostVisit(G, v); // Take appropriate action
}