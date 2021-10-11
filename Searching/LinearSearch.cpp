// Doen't need to be in sorted order
int linearSearch(int arr[],int n,int k)
{
	for(int i=0;i<n;i++)
	{
		if(arr[i] == k) return i;
	}
	return -1;
}
#include<stdio.h>
int main()
{
     int arr[] = { 1, 2, 3, 4, 5 };
     int n = sizeof(arr) / sizeof(arr[0]);

     printf("%d ", linearSearch(arr, n,5));

     return 0;
}