#include<stdio.h> 
#include<stdlib.h>

void F1(int m,int (*x)[m]) // Not applicable in C++
{

}
void F2(int** y) // Applicable in C++
{

}
int main()
{
	int a[10];//a==&a[0]
	int* b=(int*)malloc(sizeof(int)*10);//b!=&b[0]

	int a1[10];
	// a1=a;  //Array address can't be changed
	int *b1;
	b1=b;



	int c[10][10];//c==c[0]&&c[0]==&c[0][0]
	int (*e)[10]=c;




	int** d=(int**)malloc(sizeof(int*)*10);
	int i;for(i=0;i<10;i++)*(d+i)=(int*)malloc(sizeof(int)*10);//d!=d[0]&&d[0]!=&d[0][0]
	int** f=d;


	F1(10,c);
	F2(d);



	long long n;scanf("%lld",&n);
	int g[n];  // No chance of error handling for negative or large size.

	int *h=(int*)malloc(sizeof(int)*n);
	if(h==NULL) // On failure
	{
		if(n<0) printf("Array size is negative.");
		else printf("Array size is too large.");
		return 0;
	}


}