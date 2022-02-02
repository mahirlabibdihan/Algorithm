#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class Job
{
public:
    int id;
    int deadline, profit;
    Job()
    {
        this->id = '\0';
        this->deadline = 0;
        this->profit = 0;
    }
    Job(int id, int deadline, int profit)
    {
        this->id = id;
        this->deadline = deadline;
        this->profit = profit;
    }
    bool operator<(const Job &j)
    {
        return this->deadline < j.deadline;
    }
};
class Comp
{
public:
    bool operator()(const Job &a, const Job &b)
    {
        return a.deadline < b.deadline;
    }
};

vector<Job> jobSequence(vector<Job> jobs)
{
    sort(jobs.begin(), jobs.end());
    int n = jobs.size();
    priority_queue<Job, vector<Job>, Comp> pq;
    vector<Job> sequence;
    for (int i = n - 1; i >= 0; i--)
    {
        int availableSlots;
        if (i == 0)
        {
            availableSlots = jobs[i].deadline;
        }
        else
        {
            availableSlots = jobs[i].deadline - jobs[i - 1].deadline;
        }
        pq.push(jobs[i]);
        while (availableSlots > 0 && !pq.empty())
        {
            Job job = pq.top();
            pq.pop();
            sequence.push_back(job);
            availableSlots--;
        }
    }
    return sequence;
}
int main()
{
    int n;
    cin >> n;
    vector<Job> jobs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> jobs[i].deadline >> jobs[i].profit;
        jobs[i].id = i;
    }
    vector<Job> sequence = jobSequence(jobs);
    for (int i = sequence.size() - 1; i >= 0; i--)
    {
        cout << sequence[i].id << " ";
    }
}
/*
5
a 2 100
b 1 19
c 2 27
d 1 25
e 3 15
*/