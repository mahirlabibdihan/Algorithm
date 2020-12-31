#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int Length=0,Column=0,Row=0,CursorRow=1,CursorColumn=1,Delete=0,Insert=1;
	FILE *OUT=fopen("Data.txt","r");
	if(!OUT)
	{
		puts("Can not access the file .");
		return 1;
	}
	fseek(OUT,0,SEEK_END);
	long FileSize=ftell(OUT);
	fclose(OUT);
	
	printf("Row & Column : ");
	while(EOF!=scanf("%d %d",&Row,&Column))
	{
		OUT=fopen("Data.txt","r");
		char *Data=(char*)malloc(FileSize+1);
		Length=0;
		CursorRow=1;
		CursorColumn=1;
		while(1)
		{
			char C=getc(OUT);
			if(C==EOF) break;

			if(Delete)
			{
				if(CursorRow!=Row||CursorColumn!=Column)
				{
					Data[Length++]=C;
					CursorColumn++;
				}	
				else
				{
					Column=0,Row=0;
				}
			}

			else
			{
				if(CursorRow!=Row||CursorColumn!=Column)
				{
					Data[Length++]=C;
					CursorColumn++;
				}	
				else
				{
					char Input;
					printf("Character : ");
					scanf("\n%c",&Input);
					Data[Length++]=Input;
					Data[Length++]=C;
					CursorColumn++;
					Column=0,Row=0;
				}
			}
			if(C=='\n')
			{
				CursorRow++;
				CursorColumn=1;
			}
		}
		Data[Length]='\0';
		fclose(OUT);
		OUT=fopen("Data.txt","w");
		fputs(Data,OUT);
		free(Data);
		fclose(OUT);
		printf("Row & Column : ");
	}
}  