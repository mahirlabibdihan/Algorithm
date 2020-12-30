#include<stdio.h>

void String_Delete(char *str,int i)
{
	int j;
	for(j=i;str[j];j++)
	{
		str[j]=str[j+1];
	}
}
int main()
{
	char str[26]="IamDihan",c='a';
	int i;
	for(i=0;str[i];i++)
	{
		if(str[i]==c)
		String_Delete(str,i);
	}
	puts(str);
}