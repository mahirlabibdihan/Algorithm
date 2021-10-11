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

// Need to be in sorted order
int binarySearch1(int arr[], int n, int k)
{
    int left = 0, right = n, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (k > arr[mid]) left = mid + 1;
        else if (arr[mid] > k) right = mid - 1;
        else return mid;
    }
    return -1;
}

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

#include<stdio.h>
int main()
{
    int arr[] = { 1, 2, 4, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d ", binarySearch2(arr, n, 3));

    return 0;
}