#include <iostream>
#include <vector>
#include <climits>
using namespace std;
typedef long long int64;
int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    for (int &i : h)
    {
        cin >> i;
    }
    vector<int64> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i] = min(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));
        if (i > 1)
        {
            dp[i] = min(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
        }
    }
    cout << dp[n - 1] << endl;
}