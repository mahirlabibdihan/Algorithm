int partition(int arr[], int low , int high)
{
     int pivot = low;    // Pivot can be anything from low to high
     int i = low, j = high;
     while (i < j)
     {
          while (arr[i] <= arr[pivot])  // Ascending
               // while (arr[i] >= arr[pivot])  // Descending
          {
               i++;
          }
          while (arr[j] > arr[pivot])  // Ascending
               // while (arr[j] < arr[pivot])  // Descending
          {
               j--;
          }
          if (i < j)
          {
               int k = arr[i];
               arr[i] = arr[j];
               arr[j] = k;
          }
     }
     // If we had taken pivot=high , then we had to swap , arr[pivot] and arr[i] here
     int k = arr[pivot];
     arr[pivot] = arr[j];     
     arr[j] = k;
     return j;
}
void quickSort(int arr[], int low, int high)
{
     if (low < high)
     {
          int pI = partition(arr, low, high); // Partitioning Index
          quickSort(arr, low, pI - 1);   // Quick sort left partition
          quickSort(arr, pI + 1, high);  // Quick sort right partition
     }
}

#include<stdio.h>
int main()
{
     int arr[] = { 12, 11, 13, 5, 6 };
     int n = sizeof(arr) / sizeof(arr[0]);

     quickSort(arr, 0 , n - 1);

     int i;
     for (i = 0; i < n; i++)
     {
          printf("%d ", arr[i]);
     }

     return 0;
}

