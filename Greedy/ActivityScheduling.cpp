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
int greedy(vector<Activity> &works)
{
    sort(works.begin(), works.end());
    int lastFinishTime = -1, count = 0;
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
    for (auto &w : works)
    {
        cin >> w.start >> w.finish;
    }
    cout << greedy(works);
}