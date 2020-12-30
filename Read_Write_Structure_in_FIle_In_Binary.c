#include<stdio.h>

typedef struct Student{
	int Roll;
	char Name[6];
	int Score;
}Student;

int main()
{
	FILE *In,*Out;

	/****************** Write ********************/
	In=fopen("Binary.txt","wb");
	if(!In)
	{
		return 1;
	}
		
	scanf("%d %s %d",&S.Roll,S.Name,&S.Score);
	fwrite(&S,sizeof(S),1,In);
	fclose(In);
	/*********************************************/


	/******************* Read *********************/
	Out=fopen("Binary.txt","rb");
	if(!Out) 
	{
		return 2;
	}
	Student T;
	fread(&T,sizeof(T),1,Out);
	printf("%d %s %d\n",T.Roll,T.Name,T.Score);
	fclose(Out);
	/**********************************************/
}