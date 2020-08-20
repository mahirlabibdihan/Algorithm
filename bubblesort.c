#include<stdio.h>

void sort(int x[], int n)
{int i, j; for (j=0;j<n-1;j++)
           for (i=0;i<n-1-j;i++)
           if (x[i]>x[i+1])
            {int k=x[i]; x[i]=x[i+1]; x[i+1]=k;}
}


