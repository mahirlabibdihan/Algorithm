#include <iostream>
using namespace std;

template <typename E, typename Comp>
int partition(E A[], int left, int right, E &pivot)
{
    int i = left - 1;
    for (int j = left; j < right; j++)
    {
        if (Comp::prior(A[j], pivot))
        {
            i++;
            swap(A[i], A[j]);
        }
    }
    // <pivot  --- pivot --- >=pivot
    return i + 1; // Return first position in right partition
}
/*template <typename E, typename Comp>
int partition(E A[], int i, int j, E &pivot)
{
    do
    { // Move the bounds inward until they meet
        while (Comp::prior(A[i], pivot))
        {
            i++;
        } // Move l right and
        while ((i < j) && Comp::prior(pivot, A[j]))
        {
            j--;
        }                 // r left
        swap(A[i], A[j]); // Swap out-of-place values
    }while (i < j)                     // Stop when they cross
    return i;             // Return first position in right partition
}*/

// The function will choose the pivot index
template <typename E>
inline int findpivot(E A[], int l, int r)
{
    return l + (r - l) / 2;
}

// This function will decide where to put pivot before sorting
template <typename E, typename Comp>
void qsort(E A[], int left, int right)
{ // Quicksort
    if (right <= left)
        return; // Don’t sort 0 or 1 element
    // We can choose the first or last element as pivot.
    // But that will produce a poor partitioning when the array is already sorted.
    int pivotIdx = findpivot(A, left, right);
    swap(A[pivotIdx], A[right]); // Put pivot at end
    // k will be the first position in the right subarray
    int k = partition<E, Comp>(A, left, right, A[right]);
    swap(A[k], A[right]); // Put pivot in place
    qsort<E, Comp>(A, left, k - 1);
    qsort<E, Comp>(A, k + 1, right);
}
class Comp
{
public:
    static bool prior(const int &a, const int &b)
    {
        return a < b;
    }
};

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    qsort<int, Comp>(arr, 0, n - 1);
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}