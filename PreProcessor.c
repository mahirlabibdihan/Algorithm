#include<stdio.h>
#define X 0.8
#define print_dec(var)  printf("%s=%d\n",#var,var);



#define abs(x)  ( x>=0 ? x : -x ) 

int main()
{
	// int counter=5;
	// print_dec(counter);
	
	// printf("%s %s %d %s",__DATE__,__TIME__,__LINE__,__FILE__);


	printf("%d",abs(10-13));
}  