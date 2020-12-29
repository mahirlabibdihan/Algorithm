#include<stdio.h> 

int Recursive_isPrime(int n,int i)
{
    if(i*i>n) return 1;
    else if(n%i) Recursive_isPrime(n,i+1);
    else return 0;
}

int isPrime(int n)
{
	int i;
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0) return 0;
	}
	return 1;
}

int main()
{
	int n;
	printf("%d %d\n",isPrime(n),Recursive_isPrime(n,2));
}
