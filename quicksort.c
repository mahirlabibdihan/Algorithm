
#include<stdio.h>

void swap(int *a,int *b)
{int c=*a; *a=*b; *b=c;}

void sort(int x[],int l,int h)
{ if(l<h) {int a=l,i=l,j=h,k;
 while(i<j) { while(x[i]<=x[a]) i++;  while(x[j]>x[a]) j--;
      if(i<j) swap(&x[i],&x[j]); } swap(&x[a],&x[j]);
    sort(x,l,j-1);   sort(x,j+1,h);  } }


#include<stdio.h>

void sort(int x[],int l,int h)
{ if(l<h) {int a=h,i=l,j=h,k;
 while(i<j) { while(x[i]>=x[a]) i++;  while(x[j]<x[a]) j--;
       if(i<j) swap(&x[i],&x[j]); }  swap(&x[a],&x[j]);
    sort(x,l,j-1);   sort(x,j+1,h);  } }


