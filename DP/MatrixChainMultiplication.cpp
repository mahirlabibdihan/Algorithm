#include <vector>
#include <climits>
#include <iostream>
using namespace std;

// Matrix pultiplication cost: rA*cA*cB
/*void multiply(int a[][N], int rA, int cA, int b[][N], int rB, int cB, int c[][N])
{
    for (int i = 0; i < rA; i++)
    {
        for (int j = 0; j < cB; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < cA; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}*/
int dp[10][10];
int lookUpChain(vector<int> p, int i, int j)
{
    // cout << i << " " << j << " " << dp[i][j] << endl;
    if (dp[i][j] < INT_MAX)
    {
        return dp[i][j];
    }
    if (i == j)
    {
        dp[i][j] = 0;
    }
    else
    {
        for (int k = i; k < j; k++)
        {
            dp[i][j] = min(dp[i][j], lookUpChain(p, i, k) + lookUpChain(p, k + 1, j) + p[i - 1] * p[k] * p[j]); // p[i - 1] * p[k] * p[j] = The cost of multiplying two matrix. the "multiply" function above demonstrate the process
        }
    }
    return dp[i][j];
}
int memorizedMatrixChain(vector<int> p)
{
    int n = p.size() - 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = INT_MAX;
        }
    }
    return lookUpChain(p, 1, n);
}
int matrixChainOrder(vector<int> p)
{
    int n = p.size() - 1;
    int dp[n + 1][n + 1];
    int s[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 0;
    }
    for (int l = 2; l <= n; l++) // l = chain length
    {
        for (int i = 1; i <= n - l + 1; i++)
        {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int q = dp[i][k] + dp[k + 1][j] + (p[i - 1] * p[k] * p[j]);
                cout << q << endl;
                if (q < dp[i][j])
                {
                    dp[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i > j)
            {
                printf("%10c ", '*');
            }
            else
            {
                printf("%10d ", dp[i][j]);
            }
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
            {
                printf("%3c ", '*');
            }
            else
            {
                printf("%3d ", s[i][j]);
            }
        }
        cout << endl;
    }
    return dp[1][n];
}
int main()
{
    vector<int> p = {30, 35, 15, 5, 10, 20, 25};
    cout << matrixChainOrder(p) << endl;
}