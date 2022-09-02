#ifndef __APSP__
#define __APSP__
#include <vector>
using namespace std;
void init(vector<pair<int, float>> adj[], int n, vector<vector<float>> &dist, vector<vector<int>> &parent)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                dist[i][j] = 0;
            }
            else
            {
                dist[i][j] = INT_MAX;
            }
            parent[i][j] = -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (pair<int, float> j : adj[i])
        {
            dist[i][j.first] = j.second;
            parent[i][j.first] = i;
        }
    }
}
#endif