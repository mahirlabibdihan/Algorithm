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
#include<stdlib.h>
#include<string.h>
#define qsort(a,b) Bubble_Sort(a,sizeof(a)/sizeof(*a),sizeof(*a),b)
int cmp(const void*,const void*);

void swap(void *a, void *b,int sz) 
{
    void *p = malloc(sizeof(sz));
    memcpy(p, a, sz);
    memcpy(a, b, sz);
    memcpy(b, p, sz);
    free(p);
}

void Bubble_Sort(void*x,int n,int sz,int(*cmp)(const void*,const void*))
{
	int i,j; 
	for (j=n-1;j>1;j--)
	{
		for (i=0;i<j;i++)
		{
			if(cmp(x+(i+1)*sz,x+i*sz))
            {
            	swap(x+(i+1)*sz,x+i*sz,sz);
            }
		}
	}
}

typedef struct{
	int a,b,c;
}STRUCT;

int cmp(const void* a,const void* b)
{
	return ((STRUCT*)b)->a<((STRUCT*)a)->a;
	// const int *A=a,*B=b; 
	// return *A<*B;
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

	qsort(S,cmp);

	// qsort(x,cmp);

	int i;
	for(i=0;i<10;i++)
	{
		printf("%d %d %d\n",S[i].a,S[i].b,S[i].c);
	}
}

