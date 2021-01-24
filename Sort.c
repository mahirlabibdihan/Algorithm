/*
 ______   _________ _      _       _
|  ____ \|___   ___| |    | |     | |
| |    \ \   | |   | |____| |     | |
| |    | |   | |   |  ____  |     | |
| |____/ /___| |___| |    | |_____| |
|_______/|_________|_|    |_________|
M A H I R     L A B I B     D I H A N

*/
#include<stdio.h>
#define sort(a,...) Bubble_Sort(a,sizeof(a)/sizeof(a[0]),(NULL,##__VA_ARGS__))
#define swap(Type,a,b) {Type c=a;a=b;b=c;}

int cmp(void* a,void* b);

void Bubble_Sort(int *x,int n,int (*cmp)(void*,void*))
{
	int i, j,c=0; 
	for (j=n-1;j>1;j--)
	{
		for (i=0;i<j;i++)
		{
			if(cmp==NULL)
			{
				if(x[i]>x[i+1])
				{
					swap(int,x[i],x[i+1]);
				}
			}
			else if(cmp(&x[i+1],&x[i]))
            {
            	swap(int,x[i],x[i+1]);
            }
		}
	}
}

typedef struct{
	int a,b,c;
}STRUCT;

int cmp(void* a,void* b)
{
	return ((STRUCT*)b)->a<((STRUCT*)a)->a;
	// return *((STRUCT*)b)>*((STRUCT*)a);
}

void Struct_Sort(STRUCT *S,int n,int(*cmp)(void*,void*))
{
	int i, j,c=0; 
	for (j=n-1;j>1;j--)
	{
		for (i=0;i<j;i++)
		{
			if(cmp==NULL)
			{
				if(S[i].a>S[i+1].a)
				{
					swap(STRUCT,S[i],S[i+1]);
				}
			}
			else if(cmp(&S[i+1],&S[i]))
            {
            	swap(STRUCT,S[i],S[i+1]);
            }
		}
	}
}

int main()
{
	int x[10]={1,5,3,7,6,3,21,2,34,5};

	STRUCT S[10]={
		{1,2,3},
		{3,4,5},
		{5,6,7},
		{7,8,9},
		{9,10,11},
		{11,12,13},
		{13,14,15},
		{15,16,17},
		{17,18,19},
		{19,20,21}
	};

	Struct_Sort(S,10,cmp);

	int i;
	for(i=0;i<10;i++)
	{
		printf("%d %d %d\n",S[i].a,S[i].b,S[i].c);
	}
}