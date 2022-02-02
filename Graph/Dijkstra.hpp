#include "Graph/Graph.hpp"
#include "Heap/AHeap.hpp"
#define INFINITY 1 << 30
class DijkElem
{
public:
    int vertex, distance;
    DijkElem()
    {
        vertex = -1;
        distance = -1;
    }
    DijkElem(int u, int d)
    {
        vertex = u;
        distance = d;
    }
};
class DDComp
{
public:
    static bool prior(DijkElem a, DijkElem b)
    {
        return a.distance < b.distance;
    }
};
// Dijkstra’s shortest paths algorithm with priority queue
void Dijkstra(Graph *G, int *dist, int start)
{
    for (int i = 0; i < G->n(); i++)
    {
        dist[i] = INFINITY;
        G->setMark(i, VISITED);
    } // Initialize
    dist[start] = 0;
    // Initialize heap array
    Heap<DijkElem, DDComp> *H = new AHeap<DijkElem, DDComp>(G->e()); // Create heap
    H->insert(DijkElem(start, 0));
    for (int i = 0; i < G->n(); i++)
    { // Now, get distances
        DijkElem temp;
        int u;
        do
        {
            if (H->size() == 0)
                return; // Nothing to remove
            temp = H->removeFirst();
            u = temp.vertex;
        } while (G->getMark(u) == VISITED);
        G->setMark(u, VISITED);
        if (dist[u] == INFINITY)
            return; // Unreachable vertices
        for (int v = G->first(u); v < G->n(); v = G->next(u, v))
        {
            if (dist[v] > (dist[u] + G->weight(u, v)))
            { // Update dist
                dist[v] = dist[u] + G->weight(u, v);
                H->insert(DijkElem(v, dist[v])); // Insert new distance in heap
            }
        }
    }
    delete H;
}