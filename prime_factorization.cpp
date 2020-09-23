#include<stdio.h>

int isFactor(int n, int a)
{
	return (n % a == 0);
}

int isPrime(int n)
{
	if(n<=1) return 0;
	
	if(n<=3) return 1;

	if(n%2==0|n%3==0)return 0;

	for(int i=5;i*i<=n;i=i+6)
	{
		if((n%i==0)|(n%(i+2)==0)) return 0;
	}
   return 1;
}

int count(int n, int a)
{
	int c = 0;
	while (n % a == 0)
	{
		c++;
		n /= a;
	}
	return c;
}

int main()
{
	int n, i;

	scanf("%d", &n);

	for (i = 1; i * i <= n; i++)
	{
		if (isFactor(n, i))
		{
			if (i != 1)
			{
				if (isPrime(i))
				{
					printf("%d^%d ", i, count(n, i));
				}
			}
			if(i!=n/i)
			{
		   		if (isPrime(n / i))
			    {
	  				printf("%d^%d ", n / i, count(n, n / i));
			    }
			}
		}
	}
}
