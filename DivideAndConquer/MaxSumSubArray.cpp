#include <iostream>
#include <climits>
using namespace std;
// O(n^3)
int mSAS1(int arr[], int n)
{
   if (n == 0)
      return 0;

   int maxSum = arr[0];
   for (int i = 0; i < n; i++)
   {
      for (int j = i; j < n; j++)
      {
         int sum = 0;
         for (int k = i; k <= j; k++)
         {
            sum += arr[k];
         }
         maxSum = max(maxSum, sum);
      }
   }
   return maxSum;
}
// O(n^2)
int mSAS2(int arr[], int n)
{
   if (n == 0)
      return 0;
   int preSum[n] = {arr[0]};
   for (int i = 1; i < n; i++)
   {
      preSum[i] = preSum[i - 1] + arr[i];
   }
   int maxSum = arr[0];
   for (int i = 0; i < n; i++)
   {
      for (int j = i; j < n; j++)
      {
         int sum = preSum[j] - preSum[i] + arr[i];
         maxSum = max(maxSum, sum);
      }
   }
   return maxSum;
}

// DAC O(nlogn)
// https://www.youtube.com/watch?v=3GD-3UZGsVI
// https://www.geeksforgeeks.org/maximum-subarray-sum-using-divide-and-conquer-algorithm/
int maxCrossingSum(int arr[], int l, int m, int h)
{
   // Include elements on left of mid.
   int left_sum = INT_MIN;
   for (int i = m, sum = 0; i >= l; i--)
   {
      sum = sum + arr[i];
      left_sum = max(sum, left_sum);
   }

   // Include elements on right of mid
   int right_sum = INT_MIN;
   for (int i = m + 1, sum = 0; i <= h; i++)
   {
      sum = sum + arr[i];
      right_sum = max(sum, right_sum);
   }

   return left_sum + right_sum;
}

// Returns sum of maximum sum subarray in aa[l..h]
int maxSubArraySum(int arr[], int l, int r)
{
   if (l == r)
   {
      return arr[l];
   }

   int m = (l + r) / 2;
   int lss = maxSubArraySum(arr, l, m);
   int rss = maxSubArraySum(arr, m + 1, r);
   int css = maxCrossingSum(arr, l, m, r);
   return max(css, max(lss, rss));
}

// Dp - O(n)
int maxSubArraySum(int arr[], int n)
{
   if (n == 0)
      return 0;

   int maxSum = arr[0];
   int sum = arr[0];

   for (int i = 1; i < n; i++)
   {
      sum = max(arr[i], sum + arr[i]);
      maxSum = max(maxSum, sum);
   }
   return maxSum;
}

int main()
{
   int arr[] = {-3, 1, -8, 4, -1, 2, 1, -5, 5};
   int n = sizeof(arr) / sizeof(arr[0]);
   int max_sum = mSAS2(arr, n);
   printf("Maximum contiguous sum is %d\n", max_sum);
   // getchar();
   return 0;
}
