#include <stdio.h> 
int main()
{
	FILE* Ptr=fopen("a.exe","rb");
	FILE* Out=fopen("decompile.txt","w");
	fseek(Ptr,0,SEEK_END);
	long n=ftell(Ptr);
	int i;
	rewind(Ptr);

	for(i=0;i<n;i++)
	{
		char c=getc(Ptr);
		if((c>='A'&&c<='Z')||(c>='a'&&c<='z'))
		{
			fputc(c,Out);
		}
		// else if(c=='\n'||c==' '||c=='<'||c=='>'||c=='*'||c=='%')
		// {
		// 	fputc(c,Out);
		// }
		else
		{
			fputc(c,Out);
		}
	};
	fclose(Out);
	fclose(Ptr);
}