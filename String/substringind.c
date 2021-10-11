#include<stdio.h>

char* mystrstr(char *str1,char *str2)
{
	int i,j;
	for(i=0;*(str1+i)!='\0';i++)
	{
		for(j=i;*(str2+j-i)!='\0'&&*(str1+j)!='\0';j++)
		{
			if(*(str1+j)!=*(str2+j-i))
			{
				break;
			}
		}
		if(*(str2+j-i)=='\0')
		{
			return str1+i;
		}
		else if(*(str1+j)=='\0')
		{
			break;
		}
	}
	return NULL;
}

int main()
{
	char str1[101],str2[101];
	int i,j;
	scanf("%100[^\n] %100[^\n]",str1,str2);
	printf("%s",(mystrstr(str1,str2)?mystrstr(str1,str2):"NULL"));
}