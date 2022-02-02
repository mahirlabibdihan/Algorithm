// Fractional Knapsack problem
// Time complexity - O(nlogn)
// Can be solved in O(n)
/*
Given a set of items, each with a weight and a value, determine the number of each item to include in a collection so that the total weight is less than or equal to a given limit and the total value is as large as possible.
*/
/*
Maximum weight = min(sum of all weights,given limit)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Item
{
public:
    int value, weight;
    bool operator<(const Item &it)
    {
        // return (1.0 * this->value) / this->weight > (1.0 * it.value) / it.weight;
        return this->value * it.weight > it.value * this->weight;
    }
};
vector<float> fractionalKnapsack(vector<Item> items, int &C)
{
    sort(items.begin(), items.end()); // O(nlogn)
    int n = items.size();
    vector<float> A(n, 0);               // 0<=A[i]<=1
    for (int i = 0; i < n && C > 0; i++) // O(n)
    {
        if (items[i].weight < C)
        {
            A[i] = 1;
            C -= items[i].weight;
        }
        else
        {
            A[i] = 1.0 * C / items[i].weight;
            C = 0;
            break;
        }
    }
    return A;
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
    fractionalKnapsack(items, weightLimit);
}
/*
7 15
10 2
5 3
15 5
7 7
6 1
18 4
3 1
*/