void pathsum(vvll x, ll s, ll i, ll j)
{
    s += x[i][j];
    if (i == n - 1 & j == m - 1)
        ans = min(ans, s);
    else
    {
        if (i < n - 1)
            pathsum(x, s, i + 1, j);
        if (j < m - 1)
            pathsum(x, s, i, j + 1);
    }
}

ll minpathsum(vvll x)
{
    vvll dp(n, vll(m));
    ll i, j;
    f(i, 0, n) f(j, 0, n) dp[i][j] = x[i][j] + min(i > 0 ? dp[i - 1][j] : j == 0 ? 0
                                                                                 : INF,
                                                   j > 0 ? dp[i][j - 1] : i == 0 ? 0
                                                                                 : INF);
    return dp[n - 1][m - 1];
}

int main()
{
    cin >> n >> m;
    v2_in(x, n, m);
    out(pathsum(x));
}