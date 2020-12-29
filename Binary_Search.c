#include<stdio.h>

int search(int n,int k)
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

}

