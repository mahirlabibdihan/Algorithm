#include<stdio.h> 
#include<stdlib.h>

//Function name is a pointer

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



//Function can not return more than one variable
void F1(){}  // No arguments & No return value
void F2(int a){}  // With arguments & No return value
int F3(){} // No arguments & with return value
int F4(int a){} // With argumnts & with return value


int main(int n,char *Argc[]) //Arguments in main function is Command-line argument //We can pass values to main function using command-line
{
	// int* dihan=Dihan();
	// printf("%d",*Dihan());
}