// C++ program to Count
// Inversions in an array
// using Merge Sort
#include <iostream>
using namespace std;

/* This funt merges two sorted arrays
and returns inversion count in the arrays.*/
int merge(int arr[], int left, int mid,
          int right)
{
    int i, j, k;
    int invCount = 0;
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
int divide(int arr[], int left, int right)
{
    if (right <= left)
        return 0;
    int invCount = 0;
    int mid = (right + left) / 2;
    invCount += divide(arr, left, mid);
    invCount += divide(arr, mid + 1, right);
    invCount += merge(arr, left, mid + 1, right);
    return invCount;
}

int mergeSort(int arr[], size_t array_size)
{
    return divide(arr, 0, array_size - 1);
}

// Driver code
int main()
{
    int arr[] = {1, 20, 6, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = mergeSort(arr, n);
    cout << " Number of inversions are " << ans << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

// This is code is contributed by rathbhupendra
