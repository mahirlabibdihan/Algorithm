// https://www.cs.princeton.edu/courses/archive/spr03/cos226/assignments/baseball.html
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "FordFulkerson.hpp"
using namespace std;

/*
      We will try to find the best case scenerio of "X winning the division".
      Assumptions:
      X has won all left matches against teams in and out of its division.
      Y (All other teams except X) has lost all matches against teams out of its division.
      Now we will simulate matches between all the teams in X's division (except X). And try to find if it is possible for X to win the division for a particular results of all the matches.

      X can win at most w[x]+r[x] matches. So no other team in X's division should win more than w[x]+r[x]. So we will limit i-th teams maximum number of wins to w[x]+r[x]-w[i]. If this is possible to finish all the remaining games under this condition, then X is not eliminated yet. Otherwise X is eliminated.
*/

void printNames(vector<string> names, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << names[i];
        if (i < n - 2)
        {
            cout << ", ";
        }
        else if (i < n - 1)
        {
            cout << " and ";
        }
    }
}

void printElimination(vector<string> name, vector<int> w, vector<int> r, vector<bool> reachable, int x, int n, vector<vector<int>> g)
{
    int nWins = 0, nLeft = 0, nTeam = 0;
    vector<string> names;
    for (int i = 0; i < n; i++)
    {
        if (reachable[i])
        {
            nWins += w[i];
            nTeam += 1;
            names.push_back(name[i]);
            for (int j = i + 1; j < n; j++)
            {
                if (reachable[j])
                {
                    nLeft += g[i][j];
                }
            }
        }
    }
    cout << name[x] << " is eliminated." << endl;
    cout << "They can win at most " << w[x] << " + " << r[x] << " = " << w[x] + r[x] << " games." << endl;
    printNames(names, nTeam);
    cout << (names.size() == 1 ? " has" : " have")
         << " won a total of " << nWins << " games." << endl;
    cout << "They play each other " << nLeft << " times." << endl;
    cout << "So on average, each of the teams wins " << (nWins + nLeft) << "/" << nTeam << " = " << (1.0 * (nWins + nLeft) / nTeam) << " games." << endl
         << endl;
}
void solve(vector<string> name, vector<int> w, vector<int> r, vector<vector<int>> g, int n)
{

    // Create graph
    // 0 to n-1: Teams node
    // n to n + n_games - 1: Games node
    int n_games = (n * (n - 1) / 2);
    int V = 2 + n_games + n; // Total nodes
    int s = V - 2;           // Source node
    int t = V - 1;           // Sink node
    int maxWins = max_element(w.begin(), w.end()) - w.begin();
    for (int x = 0; x < n; x++)
    {
        vector<bool> reachable(V);

        // Check trivial solution
        if (w[x] + r[x] < w[maxWins])
        {
            reachable[maxWins] = true;
            printElimination(name, w, r, reachable, x, n, g);
            continue;
        }

        // Building for edmond-karp
        vector<pair<int, int>> adj[V];
        for (int i = 0; i < n; i++)
        {
            if (i != x)
            {
                adj[i].push_back({t, w[x] + r[x] - w[i]});
            }
        }

        int max_flow = 0;
        for (int i = 0, node_id = n; i < n; i++)
        {
            for (int j = i + 1; j < n; j++, node_id++)
            {
                if (i != x && j != x)
                {
                    adj[s].push_back({node_id, g[i][j]});
                    adj[node_id].push_back({i, INT_MAX});
                    adj[node_id].push_back({j, INT_MAX});
                    max_flow += g[i][j];
                }
            }
        }

        int flow = fordFulkerson(adj, V, s, t, reachable);

        // No trivial check
        if (flow < max_flow)
        {
            printElimination(name, w, r, reachable, x, n, g);
        }
    }
}

int main()
{
    freopen("mf.in", "r", stdin);
    int n;
    cin >> n;
    vector<string> name(n);
    vector<int> w(n), l(n), r(n);
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        cin >> name[i] >> w[i] >> l[i] >> r[i];
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
        }
    }
    solve(name, w, r, g, n);
}
/*
Test cases:
4
Atlanta 83 71 8 0 1 6 1
Philadelphia 80 79 3 1 0 0 2
New_York 78 78 6 6 0 0 0
Montreal 77 82 3 1 2 0 0
5
New_York 75 59 28 0 3 8 7 3
Baltimore 71 63 28 3 0 2 7 4
Boston 69 66 27 8 2 0 0 0
Toronto 63 72 27 7 7 0 0 0
Detroit 49 86 27 3 4 0 0 0

Corner:
2
A 5 4 0 0 0
B 4 4 0 0 0
*/