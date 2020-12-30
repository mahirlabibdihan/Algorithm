#include<stdio.h>

int main()
{
	
	FILE *In,*Out;
	int i;

	

	/****************** Read ********************/
	In=fopen("Binary.txt","wb");
	int ArrayIn[10]={1,2,3,4,5,6,7,8,9,10};
	// 1.
	fwrite(&ArrayIn,sizeof(ArrayIn[0])*10,1,In);

	// 2.
	// fwrite(&ArrayIn,sizeof(ArrayIn[0]),10,In);

	// 3.
	// for(i=0;i<10;i++)
	// {
	// 	fwrite(&ArrayIn[i],sizeof(ArrayIn[0]),1,In);
	// }
	/********************************************/

	fclose(In);

	

	/****************** Read ********************/
	Out=fopen("Binary.txt","rb");
	int ArrayOut[10];
	// 1.
	fread(&ArrayOut,sizeof(ArrayOut[0])*10,1,Out);

	// 2.
	// fread(&ArrayOut,sizeof(ArrayOut[0]),10,Out);

	// 3.
	// for(i=0;i<10;i++)
	// {
	// 	fread(&ArrayOut[i],sizeof(ArrayOut[0]),1,Out);
	// }
	/********************************************/
	
	for(i=0;i<10;i++)
	{
		printf("%d\n",ArrayOut[i]);
	}
	/*******************************************/

	fclose(Out);
}