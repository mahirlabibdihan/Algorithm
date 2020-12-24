#include<stdio.h> 
#include<stdlib.h>

//Function name is a pointer



//Pass by refference - Passing the address of a variable
void PassRef(int *b)
{
	//b -> Address of b
	//*b -> Value of b
	*b=5; // a will also be 5
}
void CallPassRef()
{
	int a;
	PassRef(&a);
	int b[5];
	PassRef(b);
}



//Pass by value - Passing the value of a variable
void PassVal(int b)
{
	//b is a local variable of function PassVal
	//b -> Value of a
	//&b -> Address of b (not a)
	b=5; // value of a will not change
}
void CallPassVal()
{
	int a;
	PassVal(a);
}




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
void F1(){}  // No parameter & No return value
void F2(int a){}  // With parameter & No return value
int F3(){} // No parameter & with return value
int F4(int a){} // With parameter & with return value




void Function(int a,int b); //Function protottype or declaration // int a,int b are parameters 

int main(int n,char *Argc[]) //Arguments in main function is Command-line argument //We can pass values to main function using command-line
{
	// int* dihan=Dihan();
	// printf("%d",*Dihan());
	Function(5,4); //Calling Function //5,4 are arguments
}

void Function(int a,int b) //Function definition
{
	a=a+b;
}