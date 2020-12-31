#include<stdio.h>

int main()
{
	int Array[10]={1,2,3,4,5,6,7,8,9,10};

	FILE *In,*Out;

	In=fopen("Binary.txt","wb");

	fwrite(Array,sizeof(Array[0]),10,In);

	fclose(In);

	Out=fopen("Binary.txt","rb");

	int Array2[10];

	int i;
	// for(i=0;i<10;i++)
	{
		fread(Array2,sizeof(4),10,Out);
	}
	
	for(i=0;i<10;i++)
	{
		printf("%d\n",Array2[i]);
	}

	fclose(Out);
}