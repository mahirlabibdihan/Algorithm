#include <iostream>
using namespace std;
#include "HeapSort.hpp"
#include "BubbleSort.hpp"
#include "SelectionSort.hpp"
#include "QuickSort.hpp"
#include <algorithm>
#include "MergeSort.hpp"
#include "InsertionSort.hpp"
int main()
{
    int arr[] = {4, 3, 2, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    Insertion::sort(arr, arr + n, less<int>());
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}