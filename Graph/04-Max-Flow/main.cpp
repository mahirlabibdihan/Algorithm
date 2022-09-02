#include <iostream>
#include <vector>
#include <iomanip>
#include "FordFulkerson.hpp"
#define INDEX 1
using namespace std;

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
        // cout << u << " " << v << " " << w << endl;
        adj[u - INDEX].push_back({v - INDEX, w});
    }
    int s, t;
    cin >> s >> t;
    cout << fordFulkerson(adj, n, s - 1, t - 1) << endl; // O(VE^2)
}
int main()
{
    freopen("mf.in", "r", stdin);
    // freopen("out.in", "w", stdout);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
}