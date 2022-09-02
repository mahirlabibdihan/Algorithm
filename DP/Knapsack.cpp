#ifndef __0_1_KNAPSACK__
#define __0_1_KNAPSACK__
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
#define MAX 10000
struct Item
{
    int value, weight;
};
int **createDP(int n, int m)
{
    int **dp;
    try
    {
        dp = new int *[n];
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << e.what() << '\n';
        exit(-1);
    }
    for (int i = 0; i < n; i++)
    {
        try
        {
            dp[i] = new int[m];
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            exit(-1);
        }
    }
    return dp;
}
void deleteDP(int **dp, int n)
{
    for (int i = 0; i < n; i++)
    {
        delete[] dp[i];
    }
    delete[] dp;
}
// DnC O(2^n)
namespace A
{
    // Bottom up
    /*int knapsack(vector<Item> items, int pos, int n, int W)
    {
        if (pos == n || W == 0)
        {
            return 0;
        }
        else if (items[pos].weight > W)
        {
            return knapsack(items, pos + 1, n, W);
        }
        else
        {
            return max(items[pos].value + knapsack(items, pos + 1, n, W - items[pos].weight), knapsack(items, pos + 1, n, W));
        }
    }*/
    // Top Down
    int knapsack(vector<Item> items, int n, int W)
    {
        if (n == 0 || W == 0)
        {
            return 0;
        }
        else if (items[n - 1].weight > W)
        {
            return knapsack(items, n - 1, W);
        }
        else
        {
            return max(items[n - 1].value + knapsack(items, n - 1, W - items[n - 1].weight), knapsack(items, n - 1, W));
        }
    }
}

// DnC+DP = O(n*W)
namespace B
{
    int KS(vector<Item> items, int n, int W, int **dp)
    {
        if (dp[n][W] == -1)
        {
            if (n == 0 || W == 0)
            {
                dp[n][W] = 0;
            }
            else if (items[n - 1].weight > W)
            {
                dp[n][W] = KS(items, n - 1, W, dp);
            }
            else
            {
                dp[n][W] = max(items[n - 1].value + KS(items, n - 1, W - items[n - 1].weight, dp), KS(items, n - 1, W, dp));
            }
        }
        return dp[n][W];
    }
    int knapsack(vector<Item> items, int n, int W)
    {
        int **dp = createDP(n + 1, W + 1);
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= W; j++)
            {
                dp[i][j] = -1;
            }
        }
        int value = KS(items, n, W, dp);
        deleteDP(dp, n + 1);
        return value;
    }
} // namespace B

// O(n*W)
namespace C
{
    vector<int> backtrack(vector<Item> items, int n, int W, int **dp)
    {
        vector<int> x(n);
        for (int i = n, j = W; i > 0; i--)
        {
            if (j >= items[i - 1].weight && dp[i][j] == items[i - 1].value + dp[i - 1][j - items[i - 1].weight])
            {
                j -= items[i - 1].weight;
                x[i - 1] = 1;
            }
            else
            {
                x[i - 1] = 0;
            }
        }
        return x;
    }
    vector<int> knapsack(vector<Item> items, int n, int W)
    {
        int **dp = createDP(n + 1, W + 1);
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= W; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                else if (items[i - 1].weight > j)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = max(items[i - 1].value + dp[i - 1][j - items[i - 1].weight], dp[i - 1][j]);
                }
            }
        }
        // Backtrack
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= W; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        vector<int> x = backtrack(items, n, W, dp);
        deleteDP(dp, n + 1);
        return x;
    }
}

namespace D
{
    int knapsack(vector<Item> items, int n, int W)
    {
        int **dp = createDP(n + 1, W + 1);
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= W; j++)
            {
                dp[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= W; j++)
            {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                if (j + items[i].weight <= W)
                {
                    dp[i + 1][j + items[i].weight] = max(dp[i + 1][j + items[i].weight], items[i].value + dp[i][j]);
                }
            }
        }
        int value = dp[n][W];

        deleteDP(dp, n + 1);
        return value;
    }
};

namespace D
{
    int knapsack(vector<Item> items, int n, int W)
    {
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= W; j++)
            {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                if (j + items[i].weight <= W)
                {
                    dp[i + 1][j + items[i].weight] = max(dp[i + 1][j + items[i].weight], items[i].value + dp[i][j]);
                }
            }
        }
        return dp[n][W];
    }
};

int main()
{
    int n, weightLimit;
    cin >> n >> weightLimit;
    vector<Item> items(n);
    for (auto &i : items)
    {
        cin >> i.value >> i.weight;
    }
    // clock_t start;
    // start = clock();
    // cout << A::knapsack(items, n, weightLimit) << " Time: " << clock() - start << endl;
    // start = clock();
    // cout << B::knapsack(items, n, weightLimit) << " Time: " << clock() - start << endl;
    // start = clock();
    vector<int> result = C::knapsack(items, n, weightLimit);
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;
}
#endif
/*
24 6404180
825594 382745
1677009 799601
1676628 909247
1523970 729069
943972 467902
97426 44328
69666 34610
1296457 698150
1679693 823460
1902996 903959
1844992 853665
1049289 551830
1252836 610856
1319836 670702
953277 488960
2067538 951111
675367 323046
853655 446298
1826027 931161
65731 31385
901489 496951
577243 264724
466257 224916
369261 169684
*/
/*
4 5
12 2
10 1
20 3
15 2
*/