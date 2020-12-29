#include<stdio.h>
#define X 0.8
#define abs(x)  ( x>=0 ? x : -x ) 
/******Redefining Macro*******/
#define MAX 1000
#undef MAX
#define MAX 100
/****************************/




#define print_dec(var)  printf(#var"=%d\n",var);
int main()
{
	int a=10;
	print_dec(a);

	
	// int counter=5;
	// print_dec(counter);
	
	// printf("%s %s %d %s",__DATE__,__TIME__,__LINE__,__FILE__);


	printf("%d",MAX);
}  