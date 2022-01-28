#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Activity
{
public:
    int start, finish;
    bool operator<(const Activity &a)
    {
        return this->finish < a.finish;
    }
};
int greedy(vector<Activity> works)
{
    int count = 0, n = works.size();
    sort(works.begin(), works.end());
    int lastFinishTime = -1;
    for (auto i : works)
    {
        if (i.start >= lastFinishTime)
        {
            count++;
            lastFinishTime = i.finish;
            cout << i.start << " " << i.finish << endl;
        }
    }
    return count;
}
int main()
{
    int n;
    cin >> n;
    vector<Activity> works(n);
    for (auto &i : works)
    {
        cin >> i.start >> i.finish;
    }
    cout << greedy(works);
}