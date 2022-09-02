#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<int> adj[], vector<int> &par, vector<int> &dist, vector<bool> visited, int n, int start)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
    }
    queue<int> q;
    dist[start] = 0;
    q.push(start); // Initialize Q
    visited[start] = true;
    while (!q.empty())
    { // Process all vertices on Q
        int u = q.front();
        q.pop();
        cout << u << "->";
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                cout << v << " ";
                visited[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
                par[v] = u;
            }
        }
        cout << endl;
    }
}
int main()
{
    int n, m;
    // cin >> n >> m;
    n = 17;
    m = 33;
    vector<string> grid = {"#################################",
                           "##.#.#.#.#.#.#.###.#.#.#.#.#.#.##",
                           "#..#.#.....#.#.....#.#.....#.#..#",
                           "####.#####.#.###.###.#.#####.####",
                           "#...............................#",
                           "##.#.#####.#.###.###.#.#####.#.##",
                           "#..#.....#.#...#.#...#.#.....#..#",
                           "##.###.#.#.###.#.#.###.#.#.###.##",
                           "##.....#.......#.#.......#.....##",
                           "##.###.#.#.#.#.#.#.#.#.#.#.###.##",
                           "##...#.....#.#.....#.#.....#...##",
                           "####.#.#.###.###.###.###.#.#.####",
                           "#....#.#.....#.....#.....#.#....#",
                           "####.#.###.#.#.#.#.#.#.###.#.####",
                           "#......#...#...#.#...#...#......#",
                           "##.###.#.#.###.###.###.#.#.###.##",
                           "#################################"};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    vector<int> adj[n * m];
    vector<bool> visited(n * m, false);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int idx = m * i + j;
            if (j > 0)
            {
                adj[idx].push_back(idx - 1);
            }
            if (j < m - 1)
            {
                adj[idx].push_back(idx + 1);
            }
            if (i > 0)
            {
                adj[idx].push_back(idx - m);
            }
            if (i < n - 1)
            {
                adj[idx].push_back(idx + m);
            }
            if (grid[i][j] == '#')
            {
                visited[idx] = true;
            }
        }
    }
    cout << endl;
    int start = 400;
    int end = 427;
    vector<int> par(n * m);
    vector<int> dist(n * m);
    BFS(adj, par, dist, visited, n * m, start);
    int i = end;
    while (i > -1)
    {
        // cout << i << " " << par[i] << endl;
        cout << i << endl;
        grid[i / m][i % m] = '=';
        i = par[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}