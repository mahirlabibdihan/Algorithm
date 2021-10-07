#include<stdio.h> 

int Recursive_isPrime(int n,int i)
{
    if(i*i>n) return 1;
    else if(n%i) Recursive_isPrime(n,i+1);
    else return 0;
}


int Prime(int n)      // Fastest
{
	if(n<=1) return 0;
	if(n<=3) return 1;
	if(n%2==0|n%3==0) return 0;
	int i;
	for(i=5;i*i<=n;i+=6) 
	{
		if(n%i==0) return 0;
		else if(n%(i+2)==0) return 0;
	}
	return 1;
}  


#include<stdio.h> 
int isPrime(int n)
{
	int i;
	if(n<2) return 0;
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0) return 0;
	}
	return 1;
}
int nth_Prime(int n){
	int i=0,count=0;
	while(count != n)
	{
		i++;
		if(isPrime(i)) count++;
	}
	return i;
}
int main()
{
	printf("%d",nth_Prime(25));
}
