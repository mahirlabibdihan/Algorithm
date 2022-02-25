#include <iostream>
#include <vector>
using namespace std;
struct Item
{
    int value, weight;
};
int knapsack(vector<Item> items, int pos, int n, int W)
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
}
int main()
{
    int n, weightLimit;
    cin >> n >> weightLimit;
    vector<Item> items(n);
    for (auto &i : items)
    {
        cin >> i.value >> i.weight;
    }
    cout << knapsack(items, 0, n, weightLimit);
}