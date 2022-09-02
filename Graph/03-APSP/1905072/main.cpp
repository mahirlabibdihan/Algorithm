#include <iostream>
#include <vector>
#include <iomanip>
#include "FloydWarshall.hpp"
#include "MatrixMultiplication.hpp"
#define INDEX 1
using namespace std;

template <typename T>
void printMatrix(vector<vector<T>> &mat, int n, int m, int width = 3)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == INT_MAX)
            {
                cout << setw(width) << right << "INF"
                     << " ";
            }
            else
            {
                cout << setw(width) << right << mat[i][j]
                     << " ";
            }
        }
        cout << endl;
    }
}

void printPath(int u, vector<int> &parent)
{
    if (parent[u] != -1)
    {
        printPath(parent[u], parent);
    }
    cout << u + INDEX << " -> ";
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, float>> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        float w;
        cin >> u >> v >> w;
        adj[u - INDEX].push_back({v - INDEX, w});
    }
    vector<vector<float>> dist(n, vector<float>(n));
    vector<vector<int>> parent(n, vector<int>(n));

    floydWarshall(adj, n, dist, parent);
    cout << "Floyd Warshall:" << endl;
    printMatrix(dist, n, n);
    // printMatrix(parent, n, n);

    matrixMultiplication(adj, n, dist, parent);
    cout << "\nMatrix Multiplication:" << endl;
    printMatrix(dist, n, n);

    /*int s, d;
    cin >> s >> d;
    printPath(parent[s][d], parent[s]);
    cout << d << endl;*/
}
int main()
{
    freopen("apsp.in", "r", stdin);
    // freopen("out.in", "w", stdout);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
}