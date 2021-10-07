#include<stdio.h>
#include<string.h>

int main()
{
	int i,k=3,n=10;

	int x[]={1,2,3,4,5,6,7,8,9,10};
	
	for(i=0;i<n;i++)
	{
		int c=x[i];
		x[i]=x[(i+k<n?i+k:n-1)];

		x[(i+k<n?i+k:n-1)]=c;
	}


	for(i=0;i<n;i++)
	{
		printf("%d ",x[i]);
	}
}