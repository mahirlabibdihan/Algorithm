// Source: https://www.geeksforgeeks.org/Insertion-sort/
void insertionSort1(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        // Inserting key into sorted array
        arr[j + 1] = key;
    }
}

// Modified
void insertionSort2(int arr[], int n)
{
    int i, j, k;
    for (i = 1; i < n; i++)
    {
        // Taking one element from unsorted part, and inserting it to sorted part.
        for (j = i; j > 0 && arr[j - 1] > arr[j] ; j--)
        {
            int k = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = k;
        }
    }
}

#include<stdio.h>
int main()
{
     int arr[] = { 12, 11, 13, 5, 6 };
     int n = sizeof(arr) / sizeof(arr[0]);

     insertionSort2(arr, n);

     int i;
     for (i = 0; i < n; i++)
     {
          printf("%d ",arr[i]);
     }

     return 0;
}
/*
22 21 23 15 16
^  ^
21 22 23 15 16
^     ^
21 22 23 15 16
^        ^
15 21 22 23 16
^           ^
15 16 21 22 23
*/