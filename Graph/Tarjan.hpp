#include <iostream>
#include <climits>
#include <vector>
#include <stack>
using namespace std;

void getSCC(int u, vector<int> adj[], vector<int> &disc, vector<int> &low, vector<bool> &stackMember, stack<int> &st)
{
    static int time = 0;
    disc[u] = low[u] = ++time;
    st.push(u);
    stackMember[u] = true;
    for (int v : adj[u])
    {
        if (disc[v] == -1)
        {
            getSCC(v, adj, disc, low, stackMember, st);
            low[u] = min(low[u], low[v]);
        }
        else if (stackMember[v] == true)
        {
            low[u] = min(low[u], disc[v]);
        }
    }
    int w = 0; // To store stack extracted vertices
    if (low[u] == disc[u])
    {
        while (st.top() != u)
        {
            w = st.top();
            cout << w << " ";
            stackMember[w] = false;
            st.pop();
        }
        w = st.top();
        cout << w << "\n";
        stackMember[w] = false;
        st.pop();
    }
}
void getSCCs(vector<int> adj[], int n)
{
    vector<int> disc(n + 1, -1), low(n + 1, INT_MAX);
    vector<bool> stackMember(n + 1, false);
    stack<int> st;
    for (int i = 1; i <= n; i++)
    {
        if (disc[i] == -1)
        {
            getSCC(i, adj, disc, low, stackMember, st);
        }
    }
}