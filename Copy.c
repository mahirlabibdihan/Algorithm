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
int main(int n,char *Arg[])
{
	if(n<2) 
	{
		puts("The syntax of the command is incorrect.");
		return 0;
	}
	char *Data;
	FILE *In=NULL,*Out=NULL;
	In=fopen(Arg[1],"r");
	if(In==NULL)
	{
		printf("Could Not Find %s",Arg[1]);
		return 0;
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
			puts("\tFile not copied");
			return 0; 
		}
	}
	fclose(Out);
	
	fseek(In,0,SEEK_END);
	Data=(char*)malloc(sizeof(char)*(ftell(In)+1));
	fseek(In,0,SEEK_SET);

	char c;
	Out=fopen(Arg[2],"w");
	while(1)
	{
		c=fgetc(In);
		if(c==EOF) break;
		fputc(c,Out);
	}
	fclose(Out);
	fclose(In);
	puts("\tFile copied.");
}