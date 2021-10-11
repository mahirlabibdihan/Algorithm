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
#include<string.h>
int main()
{
	char S[]="Dihan",n=strlen(S);
	int i=0;

	for(i=0;i<n-i-1;i++)
	{
		S[i]^=S[n-i-1]^=S[i]^=S[n-i-1];
	}
	puts(S);
}