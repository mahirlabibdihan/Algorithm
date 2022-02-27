#include <iostream>
#include <vector>
#include <algorithm>
#include <cfloat>
#include <cmath>
#include <map>
using namespace std;
struct Point
{
    int x, y;
};
bool compareX(const Point &p1, const Point &p2)
{
    return p1.x < p2.x;
}
bool compareY(const Point &p1, const Point &p2)
{
    return p1.y < p2.y;
}
float dist(const Point &p1, const Point &p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
// O(7n)
float merge(vector<Point> &P, int start, int mid, int end, float d)
{
    vector<Point> temp(end);
    for (int i = start, j = mid, k = start; i < mid || j < end; k++)
    {
        if (i == mid)
        {
            temp[k] = P[j++];
        }
        else if (j == end)
        {
            temp[k] = P[i++];
        }
        else if (P[i].y <= P[j].y)
        {
            temp[k] = P[i++];
        }
        else
        {
            temp[k] = P[j++];
        }
    }
    for (int i = start; i < end; i++)
    {
        P[i] = temp[i];
    }
    vector<Point> strip;
    for (int i = start; i < end; i++)
    {
        if (abs(P[i].x - P[mid].x) < d)
        {
            strip.push_back(P[i]);
        }
    }
    float minDist = d; // Initialize the minimum distance as d
    int n = strip.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < min(i + 8, n); j++)
        {
            float ds = dist(strip[i], strip[j]);
            if (ds < minDist)
            {
                minDist = ds;
            }
            else
            {
                break;
            }
        }
    }
    return minDist;
}
// 0(7n)
float divide(vector<Point> P, int start, int end)
{
    if (end - start <= 1)
    {
        return FLT_MAX;
    }
    int mid = (start + end) / 2;
    float dl = divide(P, start, mid); // T(n/2)
    float dr = divide(P, mid, end);   // T(n/2)
    float d = min(dl, dr);
    float dm = merge(P, start, mid, end, d); // O(n)
    return dm;
}
float closest(vector<Point> P)
{
    sort(P.begin(), P.end(), compareX); // O(nlogn)
    return divide(P, 0, P.size());      // O(nlogn)
}
int main()
{
    int n;
    cin >> n;
    vector<Point> P(n);
    for (int i = 0; i < n; i++)
    {
        cin >> P[i].x >> P[i].y;
    }
    float m = closest(P);
    cout << m << endl;
    return 0;
}
