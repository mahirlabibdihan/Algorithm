#include<stdio.h>
#include<string.h>

void rightRotate(char s[], int l, int r, int k)
{
	int n = r - l + 1, i;
	k %= n;

	for (i = r - 1; i > l - 1; i--)
	{
		if (i - k >= l - 1)
		{
			swap(&s[i], &s[i - k]);
		}
		else
		{
			if (n % k == 0) break;
			k -= n % k;
			i++;
			n = i - l + 1;
		}
	}
}

int main()
{
	int i,k=5,n=12;

	int x[]={1,2,3,4,5,6,7,8,9,10,11,12};
	
	for(i=n-1;i>0;i--)
	{
		int c=x[i];
		x[i]=x[(i-k>-1?i-k:0)];

		x[(i-k>-1?i-k:0)]=c;
		for(int j=0;j<n;j++)
	{
		printf("%d ",x[j]);
	}
	puts("");
	}


	for(i=0;i<n;i++)
	{
		printf("%d ",x[i]);
	}
}