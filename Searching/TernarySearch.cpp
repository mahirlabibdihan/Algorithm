#include <iostream>
using namespace std;
/*
Ternary search is slower than binary search.
https://slaystudy.com/why-binary-search-is-preferred-over-ternary-search/
Number of comparison in each iteration = 4
*/
// O(log3n)
int rTernarySearch(int arr[], int left, int right, int k)
{
    if (left <= right)
    {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;
        if (k == arr[mid1])
        {
            return mid1;
        }
        if (k == arr[mid2])
        {
            return mid2;
        }
        if (k < arr[mid1])
        {
            return rTernarySearch(arr, left, mid1 - 1, k);
        }
        else if (k > arr[mid2])
        {
            return rTernarySearch(arr, mid2 + 1, right, k);
        }
        else
        {
            return rTernarySearch(arr, mid1 + 1, mid2 - 1, k);
        }
    }
    return -1;
}
int TernarySearch(int arr[], int left, int right, int k)
{
    while (left <= right)
    {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;
        if (k == arr[mid1])
        {
            return mid1;
        }
        if (k == arr[mid2])
        {
            return mid2;
        }
        if (k < arr[mid1])
        {
            right = mid1 - 1;
        }
        else if (k > arr[mid2])
        {
            left = mid2 + 1;
        }
        else
        {
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {1, 5, 7, 8, 10};
    cout << rTernarySearch(arr, 0, 5, 7) << endl;
}