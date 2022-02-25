#include <iostream>
#include <vector>
#include <algorithm>
#include <cfloat>
#include <cmath>
#include <map>
using namespace std;
struct Point
{
    long long x, y;
};
struct MIN_DIST
{
    Point i, j;
    double d;
};
int compareX(const void *a, const void *b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->x - p2->x);
}
int compareY(const void *a, const void *b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->y - p2->y);
}
double dist(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y));
}
MIN_DIST bruteForce(Point P[], int n)
{
    double min = DBL_MAX;
    Point l, r;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
            {
                min = dist(P[i], P[j]);
                l = P[i];
                r = P[j];
            }
    return {l, r, min};
}
MIN_DIST stripClosest(Point strip[], int size, double d)
{
    double min = d; // Initialize the minimum distance as d
    Point l, r;
    qsort(strip, size, sizeof(Point), compareY);
    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i], strip[j]) < min)
            {
                min = dist(strip[i], strip[j]);
                l = strip[i];
                r = strip[j];
            }

    return {l, r, min};
}
MIN_DIST closestUtil(Point P[], int start, int end)
{
    int n = end - start;
    if (n <= 3)
    {
        return bruteForce(P, n);
    }
    int mid = (start + end) / 2;
    Point midPoint = P[mid];
    MIN_DIST dl = closestUtil(P, start, mid);
    MIN_DIST dr = closestUtil(P, mid, end);
    MIN_DIST d;
    if (dl.d < dr.d)
    {
        d = dl;
    }
    else
    {
        d = dr;
    }
    Point strip[n];
    int j = 0;
    for (int i = start; i < end; i++)
        if (abs(P[i].x - midPoint.x) < d.d)
            strip[j] = P[i], j++;
    MIN_DIST s = stripClosest(strip, j, d.d);
    if (s.d < d.d)
    {
        return s;
    }
    else
    {
        return d;
    }
}
MIN_DIST closest(Point P[], int n)
{
    qsort(P, n, sizeof(Point), compareX);
    return closestUtil(P, 0, n);
}
int main()
{
    map<pair<int, int>, int> idx;
    int n;
    cin >> n;
    Point p[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].x >> p[i].y;
        idx[{p[i].x, p[i].y}] = i;
    }
    MIN_DIST m = closest(p, n);
    int a = idx[{m.i.x, m.i.y}];
    int b = idx[{m.j.x, m.j.y}];
    printf("%d %d %.6f", min(a, b), max(a, b), m.d);
    return 0;
}
