#include <iostream>
using namespace std;
// Modified
template <typename E, typename Comp>
void iSort(E *A, int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        // Taking one element from unsorted part, and inserting it to sorted part.
        for (int j = i; j > left && Comp::prior(A[j], A[j - 1]); j--)
        {
            swap(A[j], A[j - 1]);
        }
    }
}
void insertionSort2(int arr[], int n)
{
    int i, j, k;
    for (i = 1; i < n; i++)
    {
        // Taking one element from unsorted part, and inserting it to sorted part.
        for (j = i; j > 0 && arr[j - 1] > arr[j]; j--)
        {
            swap(arr[j], arr[j - 1]);
        }
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort2(arr, n);

    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
template <typename E, typename Comp>
void iSort(E *A, int n)
{
    if (n < 2)
    {
        return;
    }
    iSort<E, Comp>(A, n - 1);
    for (int j = n - 1; j > 0 && Comp::prior(A[j], A[j - 1]); j--)
    {
        swap(A[j], A[j - 1]);
    }
}