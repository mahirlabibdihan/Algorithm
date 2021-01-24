#include<stdio.h>
double Sqrt(float n)
{
	double l=0.0,r=n,m;

	while(r-l>.0000001)
	{
		m=(l+r)/2;
		if(m*m>n) r=m;
		else l=m;
	}
	
	return m;
} 

double Sqrt(double n)
{
	double l=0.0,r=max(n,1),m=0;
	if(n<0) 
	{
		puts("Root of negative number not possible.");
		return 0;
	}
	while(r-l>.000000001)
	{
		double temp=(l+r)/2;
		if(m==temp) break;
		m=temp;
		if(m*m>n) r=m;
		else l=m;
	}

	return m;
} 

/*
def mysqrt(X):
	low=0.0
	high=X
	while high-low>.0001:
		mid=(low+high)/2
		print low, high, mid, mid*mid
		if mid*mid>X:
			high=mid
		else:
			low=mid

	print mid,mid*mid
        return mid

mysqrt(15)*/

int main()
{
	// double n,x,d=1,p;
	// cin>>n;
	// x=p=n/2;

	// while(d>0.000001)
	// {
 //        x=(x+n/x)/2;
 //        d=abs(p-x);
 //        p=x;
	// }
	// cout<<p;

	printf("%g",Sqrt(37.4567));
}