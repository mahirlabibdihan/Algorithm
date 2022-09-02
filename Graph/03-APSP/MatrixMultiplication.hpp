#include <vector>
#include <climits>
#include "AllPairsShortestPath.hpp"
using namespace std;

vector<vector<float>> extendShortestPaths(vector<vector<float>> L_old, vector<vector<float>> dist, vector<vector<int>> &parent, int n)
{
    vector<vector<float>> L_new(n, vector<float>(n, INT_MAX));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (L_old[i][k] < INT_MAX && dist[k][j] < INT_MAX && L_new[i][j] > L_old[i][k] + dist[k][j])
                {
                    L_new[i][j] = L_old[i][k] + dist[k][j];
                }
            }
        }
    }
    return L_new;
}

void matrixMultiplication(vector<pair<int, float>> adj[], int n, vector<vector<float>> &dist, vector<vector<int>> &parent)
{
    init(adj, n, dist, parent); // Initialize weight matrix

    vector<vector<float>> L = dist;
    for (int m = 2; m <= n - 1; m++)
    {
        L = extendShortestPaths(L, dist, parent, n);
    }
    dist = L;
}

// Not same output for negative edges as matrixMultiplication
void matrixMultiplicationFaster(vector<pair<int, float>> adj[], int n, vector<vector<float>> &dist, vector<vector<int>> &parent)
{
    init(adj, n, dist, parent); // Initialize weight matrix

    for (int m = 1; m < n; m *= 2)
    {
        dist = extendShortestPaths(dist, dist, parent, n);
    }
}