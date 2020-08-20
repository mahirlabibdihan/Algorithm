#include<stdio.h>

void swap(int *a,int *b)
{int c=*a; *a=*b; *b=c;}

void sort(int x[],int n)
{
    int i,j,k;
      for(i=1;i<n;i++)
         for(j=i;j>0&&x[j]<x[j-1];j--)
            swap(&x[j],&x[j-1]);
}


int main()

{
    int x[10],i;

    for(i=0;i<10;i++)
        scanf("%d",&x[i]);

        sort(x,10);

        for(i=0;i<10;i++)
        printf("%d ",x[i]);

}

