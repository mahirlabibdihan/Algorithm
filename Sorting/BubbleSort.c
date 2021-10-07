// Source: https://www.geeksforgeeks.org/Bubble-sort/
void bubbleSort1(int arr[], int n)
{
    // Worst Swaps: (n - 1) + (n - 2) + ..... + 1 = n(n + 1)/2 - n
    // Best Swaps: 0
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])    // Ascending
            // if(arr[j] < arr[j + 1])  // Descending
            {
                int k = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = k;
            }
        }
    }
}

// Modified
void bubbleSort2(int arr[], int n)
{
    // Worst Swaps: (n - 1) + (n - 2) + ..... + 2 = n(n + 1)/2 - (n + 1)
    // Best Swaps: 0
    int i, j;
    for (i = n - 1; i > 1; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int k = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = k;
            }
        }
    }
}

#include<stdio.h>
int main()
{
     int arr[] = { 12, 11, 13, 5, 6 };
     int n = sizeof(arr) / sizeof(arr[0]);

     bubbleSort2(arr, n);

     int i;
     for (i = 0; i < n; i++)
     {
          printf("%d ",arr[i]);
     }

     return 0;
}
/*
64 25 12 22 11
^           ^
25 12 22 11 64
^        ^
12 22 11 25 64
^     ^
12 11 22 25 64
^  ^
11 12 22 25 64
*/