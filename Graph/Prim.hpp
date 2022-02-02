#include "Graph/Graph.hpp"
#include "PriorityQueue/PriorityQueue.hpp"
#define NIL -1
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
    // friend ostream &operator<<(ostream &os, DijkElem e);
};
// ostream &operator<<(ostream &os, DijkElem e)
// {
//     os << '(' << e.vertex << " " << e.distance << ')';
//     return os;
// }
class Comp
{
public:
    static bool prior(DijkElem a, DijkElem b)
    {
        return a.distance < b.distance;
    }
};
// Prim’s MST algorithm: priority queue version
void Prim(Graph *G, int *edgeWeight, int start)
{                                  // "u" is current vertex
    int *parent = new int[G->n()]; // parent[I] stores I’s closest neighbor
    for (int i = 0; i < G->n(); i++)
    {
        edgeWeight[i] = INFINITY;
        parent[i] = NIL;
        G->setMark(i, UNVISITED);
    } // Initialize
    edgeWeight[start] = 0;
    Heap<DijkElem, Comp> *H = new AHeap<DijkElem, Comp>(G->e()); // Create heap - O(E)
    H->insert(DijkElem(start, 0));                               // O(log(E))

    for (int i = 0; i < G->n(); i++)
    { // Now build MST
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
        // cout << u << endl;
        // AddEdgetoMST(V[u], u); // Add edge to MST
        for (int v = G->first(u); v < G->n(); v = G->next(u, v))
        {
            if (edgeWeight[v] > G->weight(u, v)) // If any vertex is already visited than this condition will always be false for that vertex. So we don't need to check that explicitly
            {                                    // Update edgeWeight
                edgeWeight[v] = G->weight(u, v);
                parent[v] = u;                         // Update who it came from
                H->insert(DijkElem(v, edgeWeight[v])); // Insert new distance in heap - O(logE)
            }
        }
        // cout << H << endl;
    }
    delete[] parent;
    delete H;
}

/*void Prim(Graph *G, int *edgeWeight, int start)
{                                  // "u" is current vertex
    int *parent = new int[G->n()]; // parent[I] stores I’s closest neighbor
    for (int i = 0; i < G->n(); i++)
    {
        edgeWeight[i] = INFINITY;
        parent[i] = NIL;
        G->setMark(i, UNVISITED);
    } // Initialize
    edgeWeight[start] = 0;
    PriorityQueue<DijkElem, Comp> *H = new PriorityQueue<DijkElem, Comp>(G->e()); // Create heap - O(E)
    bool bitMask[G->n() + 1] = {};
    H->insertKey(DijkElem(start, 0)); // O(log(E))
    bitMask[start] = true;
    for (int i = 0; i < G->n(); i++)
    { // Now build MST
        DijkElem temp = H->extractMax();
        int u = temp.vertex;

        G->setMark(u, VISITED);
        // cout << u << endl;
        // AddEdgetoMST(V[u], u); // Add edge to MST
        for (int v = G->first(u); v < G->n(); v = G->next(u, v))
        {
            if (edgeWeight[v] > G->weight(u, v)) // If any vertex is already visited than this condition will always be false for that vertex. So we don't need to check that explicitly
            {                                    // Update edgeWeight
                edgeWeight[v] = G->weight(u, v);
                parent[v] = u; // Update who it came from
                if (bitmask[v])
                {
                    H->increaseKey(v,)
                }
                else
                {
                    H->insertKey(DijkElem(v, edgeWeight[v])); // Insert new distance in heap - O(logE)
                    bitMask[v] = true;
                }
            }
        }
        // cout << H << endl;
    }
    delete[] parent;
    delete H;
}*/