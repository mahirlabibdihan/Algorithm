#include <bits/stdc++.h>
using namespace std;
#define INF 1e18
#define ll long long
#define pll pair<ll, ll>
#define MAX 100001
vector<vector<pll>> edge(MAX); // connected vertex
vector<ll> dist(MAX, INF);     // minimum distance of a vertex from the source
vector<ll> par(MAX, -1);       // parent vertex of a child vertex

int n, m, u, v, a, b, c;

class graph
{
public:
    graph(m, a)
    {
        input(m);
        bfs(a);
    }

    void input(int m)
    {
        while (m--)
        {
            int a, b, c;
            cin >> a >> b >> c;
            edge[a].push_back({b, c});
            edge[b].push_back({a, c});
        }
    }

    void djikstra(int a)
    {
        priority_queue<pll> q;

        dist[a] = 0;
        q.push({dist[a], a});

        while (!q.empty())
        {
            int u = q.top().second;
            q.pop();
            for (auto i : adj[u])
            {
                int v = i.first;
                if (dist[v] > dist[u] + i.second)
                {
                    dist[v] = dist[u] + i.second;
                    par[v] = u;
                    q.push({-dist[v], v});
                }
            }
        }
    }

    void path(int i)
    {
        if (i != 1)
            path(par[i]);
        cout << i << " ";
    }
};

int main()
{
    cin >> n >> m;

    graph a(m, a);

    if (par[n] < 0)
        cout << -1;

    else
        a.path(n);
}
