#include <stdio.h>

double eval(double a[],double x,int n)
{
	int i;
	double s=0,c=1;;

	for(i=0;i<n;i++)
	{
		s+=a[i]*c;
		c*=x;
	}
	return s;
}

void add(double f[],double g[],double h[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		h[i]=f[i]+g[i];
	}
}
int main()
{
	double a[10]={1,2,3,4,5,6,7,8,9,10};
	printf("%lf\n",eval(a,2,3));
	double b[10]={10,9,8,7,6,5,4,3,2,1},c[10];
	add(a,b,c,10);
}