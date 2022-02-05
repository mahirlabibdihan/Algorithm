/*
n plants
k friends
As gradually the cost of plants will increase. So, we will buy the cheapest plants later.
If we sort the array of plants in decreasing order,
then i-th (0<=i<k) friend will buy the {i+0*k,i+1*k,i+2*k.....} where 0<=i+j*k<n
So, i-th plant will be bought by (i%k)-th friend. With the price ((i/k)+1)*a[i].
We don't need to know which friend bougth which plant. We just need to know the buying price of each plant.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
unsigned int greedy(vector<int> a, int n, int k)
{
    sort(a.begin(), a.end(), greater<int>());
    unsigned int cost = 0;
    for (int i = 0; i < n; i++)
    {
        cost += ((i / k) + 1) * a[i]; // This plant is bougth by (i%k)-th friend. And it is (i/k)-th plant he has bought. So the price is ((i / k) + 1) * a[i]
    }
    return cost;
}
int main()
{
    // freopen("in.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &i : a)
    {
        cin >> i;
    }
    cout << greedy(a, n, k) << endl;
}
/*
Test cases:
Input:
3 3 
2 5 6
Output:
13
Input:
3 2 
2 5 6
Output:
15
Corner case:
Input:
100 2
1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 
Output:
2550000000
This will create overflow if we use 'int'[-2147483647,2147483647] for calculating output.
*/