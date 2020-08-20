#include<stdio.h>

void merge(int x[],int l,int m, int h)
{  int i=l, j=m+1, k=l, y[h+1];
    while(i<=m&&j<=h)
    { if(x[i]<=x[j]) y[k++]=x[i++]; else y[k++]=x[j++];}
    while(j<=h) y[k++]=x[j++]; while(i<=m) y[k++]=x[i++];
    for(i=l;i<=h;i++)  x[i]=y[i]; }

void sort(int x[],int l,int h)
{    if(l<h) { int m=(l+h)/2;
   sort(x,l,m);  sort(x,m+1,h);  merge(x,l,m,h);} }


#include<stdio.h>

void merge(long long int x[],long long int l,long long int m,long long int h)
{  long long int i=l, j=m+1, k=l, y[h+1];
    while(i<=m&&j<=h)
    { if(x[i]<=x[j]) y[k++]=x[i++]; else y[k++]=x[j++];}
    while(j<=h) y[k++]=x[j++]; while(i<=m) y[k++]=x[i++];
    for(i=l;i<=h;i++)  x[i]=y[i]; }

void sort(long long int x[],long long int l,long long int h)
{    if(l<h) { long long int m=(l+h)/2;
   sort(x,l,m);  sort(x,m+1,h);  merge(x,l,m,h);} }
