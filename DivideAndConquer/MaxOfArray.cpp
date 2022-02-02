#define MAX(a, b) (a > b ? a : b)

//  Divide and Conquer approach
int maxOfArray(int arr[], int low, int high)
{
    if (low == high)
    {
        return arr[high]; // O(1)
    }
    if (high - low == 1)
    {
        return MAX(arr[low], arr[high]); // O(1)
    }
    int mid = (low + high) / 2;                                            // O(1)
    return MAX(maxOfArray(arr, low, mid), maxOfArray(arr, mid + 1, high)); // Divide -> 2T(N/2)
}
low
#include <iostream>
    using namespace std;
int main()
{

    int arr[] = {1, 5, 3, 2, 5, 7, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxOfArray(arr, n) << endl;
    cout << maxOfArray(arr, 0, n) << endl;
}