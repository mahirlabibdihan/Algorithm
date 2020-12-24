#include<stdio.h> 
#include<stdlib.h>

//Pass by refference - Passing the address of a variable
void PassRef(int *a)
{
	//a -> Address of a
	//*a -> Value of a
}
void CallPassRef()
{
	int a;
	PassRef(&a);
	int b[5];
	PassRef(b);
}
//Pass by value - Passing the value of a variable

//Function and variable name can be same unless you use both in the same function
void Dihan()
{
	int Dihan;
}//Correct

// void Nahid()
// {
// 	int Dihan;
// 	Dihan();
// }//Incorrect



//Can not return the address of local variable of a function unless it is allocated by malloc
int* LocalAddress()
{
	int *a=(int*)malloc(sizeof(int));
	return a;
}//Correct

// int* LocalAddress()
// {
// 	int a;
// 	return &a;
// }//Incorrect



int main()
{
	// int* dihan=Dihan();
	// printf("%d",*Dihan());
}