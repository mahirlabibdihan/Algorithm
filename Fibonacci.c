#include<stdio.h>
#include<stdlib.h>

int isFibonacci(int n)
{
	int Last=0,Current=1,i;
	for(i=0;i<=n;i++)
	{
		if(Current==n) return 1;
		else if(Current>n) return 0;	
		int temp=Current;
		Current+=Last;
		Last=temp;	
	}
}

int Nth_Fibonacci(int n)
{
	int Last=0,Current=1,i;
	for(i=0;i<n;i++)
	{
		int temp=Current;
		Current+=Last;
		Last=temp;	
	}
	return Current;
}

int RecursiveNth_Fibonacci(int n)
{
	if(n<2) return n;
	return RecursiveNth_Fibonacci(n-1)+RecursiveNth_Fibonacci(n-2);
}

int Sum_Fibonacci(int n)
{
	int Last=0,Current=1,i,Sum=0;
	for(i=0;i<=n;i++)
	{
		if(Current>n) return Sum;
		Sum+=Current;
		int temp=Current;
		Current+=Last;
		Last=temp;	
	}
	return Sum;
}

void Print_Fibonacci(int n)
{
	int Last=0,Current=1,i;
	for(i=0;i<n;i++)
	{
		printf("%d ",Current);
		int temp=Current;
		Current+=Last;
		Last=temp;	
	}
	puts("");
}

void RecursivePrint_Fibonacci(int n,int i,int Last,int Current)
{
	if(i==n) {puts(""); return;}
	printf("%d ",Current);
	int temp=Current;
	Current+=Last;
	Last=temp;	
	RecursivePrint_Fibonacci(n,i+1,Last,Current);
}

void RecursivePrint_Fibonacci2(int n)
{
	int i;
	for(i=1;i<n;i++)
	{
		printf("%d ",RecursiveNth_Fibonacci(i));
	}
	puts("");
}

void Store_Fibonacci(int n)
{
	int i;
	int *x=(int*)malloc(sizeof(int)*(n+1));
	for(i=0;i<=n;i++)
	{
		if(i<2) x[i]=i;
		else x[i]=x[i-1]+x[i-2];
	}
}

int RecursiveStore_Fibonacci(int n,int *x)
{
	if(n<2) x[n]=n;
    if(x[n]==-1) 
    {
    	x[n]=RecursiveStore_Fibonacci(n-1,x)+RecursiveStore_Fibonacci(n-2,x);
    }
}

int Dp_Nth_Fibonacci(int n,int *dp)
{
	if(n<2) dp[n]=n;
    if(dp[n]>-1) return dp[n];
    dp[n]=Dp_Nth_Fibonacci(n-1,dp)+Dp_Nth_Fibonacci(n-2,dp);
    return dp[n];
}

int main()
{
    int n;
    scanf("%d",&n);
    Print_Fibonacci(n);
    printf("%d\n",Sum_Fibonacci(n));
}