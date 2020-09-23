#include<stdio.h>
#include<stdlib.h>

int isFactor(int n, int a)
{
	return (n % a == 0);
}

int isPrime(int n)
{
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0) return 0;
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
			if (isPrime(n / i))
			{
				printf("%d^%d ", n / i, count(n, n / i));
			}
		}
	}
}