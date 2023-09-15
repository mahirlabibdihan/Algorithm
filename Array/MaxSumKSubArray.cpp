#include <climits>

int maxSum(int arr[], int n, int k)
{
   // k must be greater
   if (k < n)
   {
      return INT_MIN;
   }
   int maxSum = 0;
   for (int i = 0; i < k; i++)
   {
      maxSum += arr[i];
   }

   int sum = maxSum;
   for (int i = k; i < n; i++)
   {
      sum += arr[i] - arr[i - k];
      maxSum = max(sum, maxSum);
   }
   return maxSum;
}
int main()
{
}