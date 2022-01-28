#include <iostream>
#include <cstring>
using namespace std;
// Naive approach
int ans;
void traverse(int a[], int i, int n, int c, long long sum)
{
    if (i == n)
    {
        ans = max(c, ans);
        return;
    }
    if (a[i] < 0)
    {
        traverse(a, i + 1, n, c, sum);
        if (sum + a[i] >= 0)
        {
            traverse(a, i + 1, n, c + 1, sum + a[i]);
        }
    }
    else
    {
        traverse(a, i + 1, n, c + 1, sum + a[i]);
    }
}

// Efficient approach
// Function to find the length of the
// longest subsequence with non negative
// prefix sum at each position
void longestSubsequence(int *arr, int N)
{
    // Stores the maximum sum possible
    // if we include j elements till
    // the position i
    int dp[N][N + 1];

    // Initialize dp array with -1
    memset(dp, -1, sizeof dp);

    // Maximum subsequence sum by
    // including no elements till
    // position 'i'
    for (int i = 0; i < N; ++i)
    {
        dp[i][0] = 0;
    }
    // Maximum subsequence sum by
    // including first element at
    // first position
    dp[0][1] = (arr[0] >= 0 ? arr[0] : -1);

    // Iterate over all the remaining
    // positions
    for (int i = 1; i < N; ++i)
    {
        for (int j = 1; j <= (i + 1); ++j)
        {
            // If the current element is excluded
            if (dp[i - 1][j] != -1)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
            // If current element is included
            // and if totat sum is positive or not
            if (dp[i - 1][j - 1] >= 0 && dp[i - 1][j - 1] + arr[i] >= 0)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + arr[i]);
            }
        }
    }

    int ans = 0;
    // Select the maximum j by which
    // a non negative prefix sum
    // subsequence can be obtained
    for (int j = 0; j <= N; ++j)
    {
        if (dp[N - 1][j] >= 0)
        {
            ans = j;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    // Print the answer
    cout << ans << endl;
}

// Driver Code
int main()
{
    int arr[] = {4, -4, 1, -3, 1, -3};
    int N = sizeof arr / sizeof arr[0];
    longestSubsequence(arr, N);

    return 0;
}
