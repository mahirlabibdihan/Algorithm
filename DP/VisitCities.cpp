#include <iostream>
#include <vector>
using namespace std;

// There can be total 2^10-1 combinations = 1024
// But we are checking 10! combinations = 3628800
// So there are overlapping subproblems
// Suppose 2 sequence of visit:
// 1 -> 3 -> 5
// 3 -> 5 -> 1
// The min cost of all combinations after visiting 3 cities is same for the two
/*
int traverse(vector<bool> visited, int visitedCities)
{
    if (visitedCities == totalCities)
    {
        return 0;
    }
    int minCost = 1 << 30;
    for (int i = 0; i < totalCities; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            int cost = traverse(mask, visitedCities + 1);
            for (int j = 0; j < totalCities; j++)
            {
                if (isSet(mask, j))
                {
                    cost += A[i][j];
                }
            }
            minCost = min(minCost, cost);
            visited[i] = false;
        }
    }
    return minCost;
}
*/
// Answer is dp[0]
// dp[0] = min{dp[1],dp[2],dp[4],d[8],dp[16],dp[32],dp[64],dp[128],dp[256],dp[512]}
// dp[1] = min{dp[3],dp[5],......dp[513]}
// dp[2] = min{dp[3],dp[6],......dp[514]}
// dp[3] = min{dp[7],dp[11],.....dp[515]}
// dp[0] = All Unvisited
// dp[1023] = All visited

// Answer is dp[1024]
// dp[0] = 0;
// dp[1] = A[0][0] + dp[0]
// dp[3] = min(A[1][1]+A[1][0]+dp[1],A[0][0]+A[0][1]+dp[2])
/*int dp[(1 << 10)];
int traverse(int mask, int visitedCities)
{
    if (visitedCities == totalCities)
    {
        return 0;
    }
    if (dp[mask])
    {
        return dp[mask];
    }
    int minCost = 1 << 30;
    for (int i = 0; i < totalCities; i++)
    {
        if (!isSet(mask, i))
        {
            mask = setBit(mask, i);
            int cost = traverse(mask, visitedCities + 1);
            for (int j = 0; j < totalCities; j++)
            {
                if (isSet(mask, j))
                {
                    cost += A[i][j];
                }
            }
            minCost = min(minCost, cost);
            mask = resetBit(mask, i);
        }
    }
    dp[mask] = minCost;
    return dp[mask];
}
int solve()
{
    return traverse(0, 0);
}*/

int setBit(int mask, int idx)
{
    return mask | (1 << idx);
}
int resetBit(int mask, int idx)
{
    return mask ^ (1 << idx);
}
bool isSet(int mask, int idx)
{
    return (mask & (1 << idx)) != 0;
}
// O((n^2)*(2^n))
int solve(vector<vector<int>> A, int totalCities)
{
    vector<int> dp((1 << 10), (1 << 30));
    dp[0] = 0;
    for (int i = 0; i < (1 << totalCities); i++)
    {
        for (int j = 0; j < totalCities; j++)
        {
            if (!isSet(i, j))
            {
                int mask = setBit(i, j); // Visit j-th city
                int cost = 0;            // Cost based on previous visits
                for (int k = 0; k < totalCities; k++)
                {
                    if (isSet(mask, k))
                    {
                        cost += A[j][k];
                    }
                }
                dp[mask] = min(dp[mask], dp[i] + cost);
            }
        }
    }
    return dp[(1 << totalCities) - 1];
}
int main()
{
    int totalCities;
    cin >> totalCities;
    vector<vector<int>> A(10, vector<int>(10));
    for (int i = 0; i < totalCities; i++)
    {
        for (int j = 0; j < totalCities; j++)
        {
            cin >> A[i][j];
        }
    }
    cout << solve(A, totalCities) << endl;
}
/*
What we will store at dp[i]?
Let, i = 21
21 = 0000010101
So, 21 means we have visited city 1,3 and 5.
So, in dp[21] we will store minimum cost to visit city 1,3,5 in any sequence.
There will be 3!=6 possible sequence to visit city 1,3,5. We will store the minimum cost among these 6 sequence in dp[21].
dp[1023] -> Answer
1023 = 1111111111

dp[1023] = 1<<10-1
*/