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
int stripClosest(vector<Point> &P, int start, int end, int midX, float d)
{
    vector<Point> strip; // Array of points whose x are in range of [midX-d,midX+d]
    for (int i = start; i < end; i++)
    {
        if (abs(P[i].x - midX) < d)
        {
            strip.push_back(P[i]);
        }
    }
    float minDist = d; // Initialize the minimum distance as d
    int n = strip.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < min(i + 7, n); j++)
        {
            minDist = min(minDist, dist(strip[i], strip[j]));
        }
    }
    return minDist;
}
void merge(vector<Point> &P, int start, int mid, int end)
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
}
// 2T(n/2)+O(n)
float divide(vector<Point> P, int start, int end)
{
    if (end - start <= 1)
    {
        return FLT_MAX;
    }
    int mid = (start + end) / 2;
    int midX = P[mid].x;
    float dl = divide(P, start, mid); // T(n/2)
    float dr = divide(P, mid, end);   // T(n/2)
    float d = min(dl, dr);
    merge(P, start, mid, end);                   // O(n) - Merges based on y
    return stripClosest(P, start, end, midX, d); // O(n)
}
float closest(vector<Point> P)
{
    // Sort based on x
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
