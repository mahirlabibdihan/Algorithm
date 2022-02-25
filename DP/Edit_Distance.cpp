#include <iostream>
#include <climits>
using namespace std;

// Transform a to b
int min(int x, int y, int z) { return min(min(x, y), z); }
int DnC(string a, string b, int n, int m)
{
    if (n == 0)
    {
        return m; // Insert all characters of b to a
    }
    else if (m == 0)
    {
        return n; // Delete all characters from a
    }
    if (a[n - 1] == b[m - 1])
    {
        // Keep
        return DnC(a, b, n - 1, m - 1);
    }
    else
    {
        return 1 + min(
                       DnC(a, b, n - 1, m - 1), // Replace
                       DnC(a, b, n - 1, m),     // Delete
                       DnC(a, b, n, m - 1)      // Insert
                   );
    }
}
int DP(string a, string b, int n, int m)
{
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= m; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return dp[n][m];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        cout << DP(a, b, a.size(), b.size()) << endl;
    }
}