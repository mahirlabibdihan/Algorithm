#include<stdio.h>
#include<string.h>

void Remove(char s1[],int start,int end)
{
	int i;
	for(i=start;s1[end+i-start-1]!='\0';i++)
	{
		s1[i]=s1[end+i-start];
	}
}

void Stretch(char s1[],int start,int length)
{
	int i;
	for(i=strlen(s1);i>=start;i--)
	{
		s1[i+length]=s1[i];
	}
}
void Insert(char s1[],char s3[],int start)
{
	int i;
	for(i=start;s3[i-start]!='\0';i++)
	{
		s1[i]=s3[i-start];
	}
}
void Replace(char s1[],char s3[],int start,int end)
{
	Remove(s1,start,end);
	Stretch(s1,start,strlen(s3));
	Insert(s1,s3,start);
}
int main()
{
	char s1[501],s2[101],s3[11];
	int i,j;

	scanf("%500[^\n] %100[^\n] %10[^\n]",s1,s2,s3);

	for(i=0;s1[i]!='\0';i++)
	{
		for(j=i;s2[j-i]!='\0'&&s1[j]!='\0';j++)
		{
			if(s1[j]!=s2[j-i])
			{
				break;
			}
		}
		if(s2[j-i]=='\0')
		{
			Replace(s1,s3,i,j);
			i=i+strlen(s3)-1;
		}
		else if(s1[j]=='\0')
		{
			break;
		}
	}
	puts(s1);
}