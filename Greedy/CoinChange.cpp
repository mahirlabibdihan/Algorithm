#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// 1 7 11 15
// This greedy solution doesn't work for amount 18
// Greedy solution: 15 1 1 1
// Correct solution: 11 7
vector<int> coinChange(int amount, vector<int> allCoins)
{
    sort(allCoins.begin(), allCoins.end(), greater<int>());
    vector<int> coins;
    for (int i : allCoins)
    {
        while (i <= amount)
        {
            coins.push_back(i);
            amount -= i;
        }
        if (amount == 0)
        {
            return coins;
        }
    }
    return vector<int>();
}
int main()
{
    int n;
    cin >> n;
    vector<int> allCoins(n);
    for (int &i : allCoins)
    {
        cin >> i;
    }
    int amount;
    cin >> amount;
    vector<int> coins = coinChange(amount, allCoins);
    for (int i : coins)
    {
        cout << i << " ";
    }
}
