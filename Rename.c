#include<stdio.h>
int main(int n,char *Arg[]) 
{
	if(n<2) 
	{
		puts("The syntax of the command is incorrect.");
		return 0;
	}
	FILE *In=NULL,*Out=NULL;
	In=fopen(Arg[1],"r");
	if(In==NULL)
	{
		printf("Could Not Find %s",Arg[1]);
		return 0;
	}
	else
	{
		fclose(In);
	}
	if(n>3) 
	{
		puts("The syntax of the command is incorrect.");
		return 0;
	}

	Out=fopen(Arg[2],"r");
	if(Out!=NULL)
	{
		printf("Overwrite %s? (y/n):",Arg[2]);
		char c=getchar();
		if('n'==c) 
		{
			puts("File not renamed");
			return 0; 
		}
	}
	fclose(Out);

   if (rename(Arg[1],Arg[2]))
   {
      printf("File not renamed");
   }
   else
   {
      printf("\tFile renamed");
   }
   return 0;
}