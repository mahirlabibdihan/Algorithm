#include<stdio.h>
#include<string.h>

int main()
{
	int New=0;
	char Line[100],In[100]="Bye .\n";
	FILE *IN=fopen("Data.txt","r");
	FILE *OUT=fopen("Data.txt","r+");
	if(!IN||!OUT)
	{
		puts("Can not access the file .")
		return 1;
	}
	int n=4,i=0;
	while(i<n-1)
	{
		char C=fgetc(OUT);
		fgetc(IN);
		if(C=='\n')i++;
		if(C==EOF)
		{
			New=1;
			break;
		}
	};
	n=ftell(OUT);
	fseek(OUT,n,SEEK_SET);
	while(fgets(Line,99,IN))
	{
		if(New)
		{
			fputc('\n',OUT);
			New=0;
		}		
		fputs(In,OUT);	
		strcpy(In,Line);
	}
	fputs(In,OUT);
	fclose(IN);
	fclose(OUT);
}