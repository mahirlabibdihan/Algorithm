#include<stdio.h>
int main(int n,char *Arg[]) 
{
	if(n!=2) 
	{
		puts("The syntax of the command is incorrect.");
		return 0;
	}
	FILE* In=fopen(Arg[1],"r");
	if(In==NULL)
	{
		printf("Could Not Find %s",Arg[1]);
		return 0;
	}
	else
	{
		fclose(In);
	}
   if (remove(Arg[1])==NULL)
      printf("The file is Deleted successfully");
   else
      printf("The file is not Deleted");
   return 0;
}