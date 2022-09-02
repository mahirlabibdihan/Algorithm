#include <vector>
#include <climits>
#include "AllPairsShortestPath.hpp"
using namespace std;

void floydWarshall(vector<pair<int, float>> adj[], int n, vector<vector<float>> &dist, vector<vector<int>> &parent)
{
    init(adj, n, dist, parent); // Initialize matrices
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] < INT_MAX && dist[k][j] < INT_MAX && dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    parent[i][j] = parent[k][j];
                }
            }
        }
    }
}