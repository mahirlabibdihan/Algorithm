// C++ program to Count
// Inversions in an array
// using Merge Sort
#include <iostream>
using namespace std;
typedef long long int64;
/* This funt merges two sorted arrays
and returns inversion count in the arrays.*/
int64 merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int64 invCount = 0;
    int temp[right + 1];
    for (int i = left, j = mid, k = left; i < mid || j <= right; k++)
    {
        if (i == mid)
        {
            temp[k] = arr[j++];
        }
        else if (j > right)
        {
            temp[k] = arr[i++];
        }
        else if (arr[i] <= arr[j])
        {
            temp[k] = arr[i++];
        }
        else
        {
            temp[k] = arr[j++];
            /*An inversion in an array A of n distinct elements is a pair of indices (i, j) such that i < j and
A[i] > A[j].*/
            invCount = invCount + (mid - i);
        }
    }

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return invCount;
}
int64 divide(int arr[], int left, int right)
{
    if (right <= left)
        return 0;
    int64 invCount = 0;
    int mid = (right + left) / 2;
    invCount += divide(arr, left, mid);
    invCount += divide(arr, mid + 1, right);
    invCount += merge(arr, left, mid + 1, right);
    return invCount;
}

int64 mergeSort(int arr[], size_t array_size)
{
    return divide(arr, 0, array_size - 1);
}

// Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << mergeSort(arr, n) << endl;
        ;
    }
}