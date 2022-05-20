#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
Question: The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate span of stock’s price for all n days.
The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is "less than" its price on the given day.
*/

// O(n^2)
/*vector<int> calculateSpan(vector<int> price)
{
    int n = price.size();
    vector<int> span(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = i - 1; (j >= 0) && (price[i] > price[j]); j--)
        {
            span[i]++;
        }
    }
    return span;
}*/
// O(n)
vector<int> calculateSpan(vector<int> price)
{
    int n = price.size();
    stack<int> st;
    vector<int> span(n, 0);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && price[st.top()] < price[i])
        {
            st.pop(); // n times pop
        }
        span[i] = (st.empty()) ? (i + 1) : (i - st.top());
        // i+1 means all the spans before i is smaller than price[i]
        // i - st.top() means all the spans from st.top() to i is smaller than price[i]
        st.push(i); // n times push
    }
    return span;
}
int main()
{
    vector<int> price = {5, 3, 4, 3};
    vector<int> span = calculateSpan(price);
    for (int i : span)
    {
        cout << i << " ";
    }
}