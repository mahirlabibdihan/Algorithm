void merge(int arr[], int left, int mid, int right)
{
   int i = left, j = mid + 1, k = 0, tmp[right - left + 1];
   ]m 
   // Merging left and right sub-array in a temporary array in sorted order.
   while (i <= mid && j <= right)
   {
      if (arr[i] <= arr[j])
      {
         tmp[k++] = arr[i++];
      }
      else
      {
         tmp[k++] = arr[j++];
      }
   }
   while (j <= right)
   {
      tmp[k++] = arr[j++];
   }
   while (i <= mid)
   {
      tmp[k++] = arr[i++];
   }

   // Copying the temporary array back to Original array
   for (i = left; i <= right; i++)
   {
      arr[i] = tmp[i - left];
   }
}

void mergeSort(int arr[], int left, int right)
{  
   if (left < right) 
   {
      int mid = (left + right) / 2;
      mergeSort(arr, left, mid);    // Dividing
      mergeSort(arr, mid + 1, right);     // Dividing
      merge(arr, left, mid, right);    // Merging
   }
}

#include<stdio.h>
int main()
{
     int arr[] = { 12, 11, 13, 5, 6 };
     int n = sizeof(arr) / sizeof(arr[0]);

     mergeSort(arr, 0 , n - 1);

     int i;
     for (i = 0; i < n; i++)
     {
          printf("%d ",arr[i]);
     }

     return 0;
}