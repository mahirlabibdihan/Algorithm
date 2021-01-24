/*
 ______   _________ _      _       _
|  ____ \|___   ___| |    | |     | |
| |    \ \   | |   | |____| |     | |
| |    | |   | |   |  ____  |     | |
| |____/ /___| |___| |    | |_____| |
|_______/|_________|_|    |_________|
M A H I R     L A B I B     D I H A N

*/
#include <stdio.h> 
int main()
{
	FILE* Ptr=fopen("supershrink.bmp","rb");

	while(1)
	{
		int a;
		fread(&a,4,1,Ptr);
		if(a==EOF)break;
		printf("%d ",a);
	};

	// for(char C=fgetc(Ptr);C!=EOF;C=fgetc(Ptr))
	// {
	// 	putchar(C);
	// }



	fclose(Ptr);
}