#ifndef __DSU__
#define __DSU__
#include <vector>
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
#endif