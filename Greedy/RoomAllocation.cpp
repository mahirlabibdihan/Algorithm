#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Activity
{
public:
    int start, finish, id;
    bool operator<(const Activity &a)
    {
        if (this->finish < a.finish)
        {
            return true;
        }
        else if (this->finish == a.finish)
        {
            return this->start < a.start;
        }
        return false;
    }
};
vector<vector<Activity>> greedy(vector<Activity> &works, int n)
{
    sort(works.begin(), works.end());
    vector<vector<Activity>> rooms;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < count; j++)
        {
            if (works[i].start > rooms[j].back().finish)
            {
                rooms[j].push_back(works[i]);
                break;
            }
        }
        if (j == count)
        {
            vector<Activity> room;
            room.push_back(works[i]);
            rooms.push_back(room);
            count++;
        }
    }
    return rooms;
}
int main()
{
    int n;
    cin >> n;
    vector<Activity> works(n);
    for (int i = 0; i < n; i++)
    {
        cin >> works[i].start >> works[i].finish;
        works[i].id = i;
    }
    vector<vector<Activity>> rooms = greedy(works, n);
    vector<int> allocation(n);
    int count = rooms.size();
    for (int i = 0; i < count; i++)
    {
        for (auto j : rooms[i])
        {
            allocation[j.id] = i + 1;
        }
    }
    cout << count << endl;
    for (int i : allocation)
    {
        cout << i << " ";
    }
}