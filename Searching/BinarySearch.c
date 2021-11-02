/*int search(int n,int k)
{
    int l=0,r=n,m;

    while(l<=r)
    {
        m=(l+r)/2;
        if(k>m) l=m+1;
        else if(m>k) r=m-1;
        else {return m; break;}
    }

    if(l>r) return -1;
}


int search(int n,int k)
{
    int l=0,r=n,m;

    while(l+1<r)
    {
        m=(l+r)/2;
       (k>m)?r=m:l=m;
    }

    return l;//lowerbound

}

int search(int n,int k)
{
    int l=0,r=n,m;

    while(l+1<r)
    {
        m=(l+r)/2;
       (k>m)?r=m:l=m;
    }

    return l;//lowerbound
}*/

// More efficient
int binarySearch2(int arr[], int n, int k)
{
    int left = 0, right = n, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (k > arr[mid])
        {
            if (mid + 1 < n ? k < arr[mid + 1] : false)
            {
                return -1;
            }
            else
            {
                left = mid + 1;
            }
        }
        else if (k < arr[mid])
        {
            if (mid - 1 > -1 ? k > arr[mid - 1] : false)
            {
                return -1;
            }
            else
            {
                right = mid - 1;
            }
        }
        else return mid;
    }
    return -1;
}

int recursiveBinarySearch(int arr[], int left,int right, int k)
{
    if (left <= right)
    {
        int mid = (left + right) / 2;
        if (k > arr[mid]) recursiveBinarySearch(arr,mid + 1,right,k);
        else if (arr[mid] > k) recursiveBinarySearch(arr,left,mid - 1,k);
        else return mid;
    }
    return -1;
}

// Need to be in sorted order
int binarySearch(int arr[], int n, int k)
{
    int left = 0, right = n;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (k > arr[mid]) left = mid + 1;
        else if (arr[mid] > k) right = mid - 1;
        else return mid;
    }
    return -1;
}

// First element >= k
int lowerBound(int arr[], int n, int k)
{
    int left = 0, right = n;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (k > arr[mid]) left = mid + 1;
        else right = mid-1;
    }

    if(left<n && arr[left]<k)
    {
        left++;
    }
    return left;
}

// First element > k
int upperBound(int arr[], int n, int k)
{  
    int left = 0, right = n;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (k >= arr[mid]) left = mid + 1; 
        else right = mid-1;
    }

    if(left<n && arr[left]<=k)
    {
        left++;
    }
    return left;
}

#include<stdio.h>
int main()
{
    int arr[] = { 1, 2, 2 , 2, 5, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);


    printf("%d ", upperBound(arr, n, 2));

    return 0;
}