// Source: https://www.geeksforgeeks.org/Selection-sort/
void selectionSort1(int arr[], int n) {
	int i, j, min;

	// Worst Swaps: (n - 1) + (n - 2) + ..... + 1 = n(n + 1)/2 - n
    // Best Swaps: (n - 1) + (n - 2) + ..... + 1 = n(n + 1)/2 - n

	// One by one move boundary of unsorted subarray
	for (i = 0; i < n - 1; i++)
	{
		// Find the minimum element in unsorted array
		min = i;
		for (j = i + 1; j < n; j++) 
		{
			if (arr[j] < arr[min])    // Ascending
			{
				min = j;
			}
		}

		// Swap the found minimum element with the first element
		int k = arr[i];
		arr[i] = arr[min];
		arr[min] = k;
	}
}

// Modified
void selectionSort2(int arr[], int n) {
	int i, j, max;

	// Worst Swaps: (n - 1) + (n - 2) + ..... + 2 = n(n + 1)/2 - (n + 1)
    // Best Swaps: 0	

	// One by one move boundary of unsorted subarray
	for (i = n - 1; i > 1 ; i--)
	{
		// Find the minimum element in unsorted array
		max = i;
		for (j = 0; j < i; j++) 
		{
			if (arr[j] > arr[max]) 
			{
				max = j;
			}
		}

		// Swap the found minimum element with the first element
		if (max != i) 
		{
			int k = arr[i];
			arr[i] = arr[max];
			arr[max] = k;
		}
	}
}

#include<stdio.h>
int main()
{
     int arr[] = { 12, 11, 13, 5, 6 };
     int n = sizeof(arr) / sizeof(arr[0]);

     selectionSort2(arr, n);

     int i;
     for (i = 0; i < n; i++)
     {
          printf("%d ",arr[i]);
     }

     return 0;
}
/*
64 25 12 22 11
^			^
11 25 12 22 64
   ^		^
11 12 25 22 64
	  ^		^
11 12 22 25 64
		 ^	^
11 12 22 25 64
*/