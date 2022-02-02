#include "Graph/Graph.hpp"
#include "Heap/AHeap.hpp"
#include "DSU/DSU.hpp"
class KruskElem
{ // An element for the heap
public:
    int from, to, distance; // The edge being stored
    KruskElem()
    {
        from = -1;
        to = -1;
        distance = -1;
    }
    KruskElem(int f, int t, int d)
    {
        from = f;
        to = t;
        distance = d;
    }
};
class Comp
{
public:
    static bool prior(KruskElem a, KruskElem b)
    {
        return a.distance < b.distance; // Min-Heap
    }
};
void Kruskal(Graph *G)
{                                         // Kruskal’s MST algorithm
    DSU A(G->n());                        // Equivalence class array
    KruskElem *E = new KruskElem[G->e()]; // Array of edges for min-heap
    int edgecnt = 0;
    // Converting graph to array of edges
    for (int v = 0; v < G->n(); v++) // Put the edges on the array
    {
        for (int w = G->first(v); w < G->n(); w = G->next(v, w))
        {
            E[edgecnt].distance = G->weight(v, w);
            E[edgecnt].from = v;
            E[edgecnt++].to = w;
        }
    }
    // Sorting the array in non-decreasing order of weight of edges
    // Heapify the edges
    Heap<KruskElem, Comp> *H = new AHeap<KruskElem, Comp>(E, edgecnt, edgecnt); // Create
    int numMST = G->n();                                                        // Initially n equiv classes
    // Need to choose n-1 edges for n vertices
    for (int i = 0; numMST > 1; i++)
    { // Combine equiv classes
        KruskElem temp;
        temp = H->removeFirst(); // Get next cheapest edge
        int v = temp.from;
        int u = temp.to;
        if (A.differ(v, u))
        {                  // If in different equiv sets
            A.unite(v, u); // Combine equiv sets
            // AddEdgetoMST(temp.from, temp.to); // Add edge to MST
            numMST--; // One less vertex in MST
        }
    }
    delete[] E;
    delete H;
}