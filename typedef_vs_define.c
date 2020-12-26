#include<stdio.h>
/*---------Type definitions vs Macro definitions----------*/
// Syntax:
// typedef original alias;
// #define alias original
// typedef -> Follow scope rules.
// #define -> Doesn't follow scope rules.Works globally.
void f()
{
	// typedef long long ll;
	// #define ll long long 
}


// typedef interpretation is performed by the compiler where #define statements are performed by preprocessor.As a result #define errors doesn't give compile errors if we don't use them.typedef error always does.

#define ll long lon
// typedef long lon ll;


typedef char* ptr;
#define PTR char*

int main()
{
 	// scanf("%*c");
	ptr a,b,c;  //char *a,*b,*c;
	PTR A,B,C;  //char *A,B,C;
	// printf("%d %d %d \n",sizeof a,sizeof b,sizeof c);
	// printf("%d %d %d \n",sizeof A,sizeof B,sizeof C);
	


	printf("Size of Short: %d\n",sizeof(short));
	printf("Size of Integer: %d\n",sizeof(int));	
	printf("Size of Unsigned: %d\n",sizeof(unsigned));
	printf("Size of Pointer: %d\n",sizeof(void*));
	printf("Size of Long: %d\n",sizeof(long));
	printf("Size of Long Long: %d\n",sizeof(long long));
	printf("Size of Float: %d\n",sizeof(float));
	printf("Size of Double: %d\n",sizeof(double));
	printf("Size of Long Double: %d\n",sizeof(long double));
}