#include <iostream>
using namespace std;
// Heap Sort - O(nlogn)
void heapifyArray(int* arr, int n, int root)
{
	int largest = root; //initialize root as largest element
	int left = 2 * root + 1; //left child
	int right = 2 * root + 2; //right child
	// If left child is larger than root
	if (left < n)
	{
		if (arr[left] > arr[largest])
		{
			largest = left;
		}
	}
	// If right child is larger than largest so far
	if (right < n)
	{
		if (arr[right] > arr[largest])
		{
			largest = right;
		}
	}

	if (largest != root) //largest elemnt jodi root na hoy..
	{
		swap(arr[largest], arr[root]); //swap korey dibo
		heapifyArray(arr, n, largest); //recursively heapify
	}
}

// To heapify the whole tree we need to heapify all the non-leaf elements. From bottom to root.
void heapify(int *arr, int n)
{
	// Iterative
	// In array representation,	0th to (n/2)-1 th elements are non-leaf elements
	for (int i = (n / 2) - 1; i >= 0; i--)
	{
		heapifyArray(arr, n, i);
	}
}

void heapSort(int* arr, int n)
{
	heapify(arr, n);
	// We will delete the root of the heap, until the heap is empty.
	// So we will delete the maximum element of the heap everytime
	for (int i = n - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);		// move current root to end
		heapifyArray(arr, i, 0);	// call max heapify on the reduced heap
		// max heap - Ascending order
		// min heap - Descending order
	}
}

int main()
{
	int arr[] = { 12, 11, 13, 5, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);

	heapSort(arr, n);

	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}