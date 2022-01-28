#include <iostream>
using namespace std;
template <typename E, typename Comp>
void merge2(E *A, E *temp, int left, int mid, int right)
{
    for (int i = left; i <= right; i++) // Copy subarray to temp
        temp[i] = A[i];
    // Do the merge operation back to A
    int i1 = left;
    int i2 = mid + 1;
    for (int curr = left; curr <= right; curr++)
    {
        if (i1 == mid + 1) // Left sublist exhausted
            A[curr] = temp[i2++];
        else if (i2 > right) // Right sublist exhausted
            A[curr] = temp[i1++];
        else if (Comp::prior(temp[i1], temp[i2]))
            A[curr] = temp[i1++];
        else
            A[curr] = temp[i2++];
    }
}
template <typename E, typename Comp>
void merge1(E *A, E *temp, int left, int mid, int right)
{
    // Do the merge operation back to A
    // Do the merge operation. First, copy 2 halves to temp.
    // 12 11 13 5 6
    for (int i = left; i <= mid; i++)
    {
        temp[i] = A[i];
    }
    // right = 4 mid = 2
    // -----> ------>
    // -----> <------
    // j = 1 to 2
    // temp[4] = A[3]
    // temp[3] = A[4]
    for (int j = 1; j <= right - mid; j++)
    {
        temp[right - j + 1] = A[mid + j];
    }
    // for (int j = mid + 1; j <= right; j++)
    // {
    //     temp[right - j + mid + 1] = A[j];
    // }
    // Merge sublists back to A
    for (int i = left, j = right, k = left; k <= right; k++)
    {
        if (Comp::prior(temp[i], temp[j]))
        {
            A[k] = temp[i++];
        }
        else
        {
            A[k] = temp[j--];
        }
    }
}
template <typename E, typename Comp>
void mergeSort(E *A, E *temp, int left, int right)
{
    if (left >= right)
        return; // List of one/zero element
    int mid = left + (right - left) / 2;
    mergeSort<E, Comp>(A, temp, left, mid);
    mergeSort<E, Comp>(A, temp, mid + 1, right);
    merge1<E, Comp>(A, temp, left, mid, right);
}

template <typename E, typename Comp>
E *merge(E *leftArr, E *rightArr, int left, int mid, int right)
{
    const int n = right - left + 1;
    E *arr = new E[n];
    // Now we have to merge this left and right subarray into the original array
    for (int i = 0, j = 0, k = 0; k < n; k++)
    {
        if (i > mid) // Left sublist exhausted
        {
            arr[k] = rightArr[j++];
        }
        else if (j > right) // Right sublist exhausted
        {
            arr[k] = leftArr[i++];
        }
        else if (Comp::prior(leftArr[i], rightArr[j]))
        {
            arr[k] = leftArr[i++];
        }
        else
        {
            arr[k] = rightArr[j++];
        }
    }
    delete[] leftArr, rightArr;
    return arr;
}
template <typename E, typename Comp>
E *mergeSort(E *A, int left, int right)
{
    if (left > right)
    {
        return new E[0];
    }
    if (left == right)
    {
        E *arr = new E[1];
        arr[0] = A[left];
        return arr; // List of one/zero element
    }
    int mid = left + (right - left) / 2;
    E *leftArr = mergeSort<E, Comp>(A, left, mid);
    E *rightArr = mergeSort<E, Comp>(A, mid + 1, right);
    return merge<E, Comp>(leftArr, rightArr, left, mid, right);
}
template <typename E, typename Comp>
void msort(E *A, int n)
{
    E *arr = mergeSort<E, Comp>(A, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        A[i] = arr[i];
    }
    delete[] arr;
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
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    msort<int, Comp>(arr, n);
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}