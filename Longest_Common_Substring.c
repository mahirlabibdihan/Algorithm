#include<stdio.h>
#include<string.h>

#define max(a,b) ((a)>(b)?(a):(b))

int Find_SubString(char *String1,char *String2)
{
    int p=strlen(String1),q=strlen(String2),j,k,c=0;

    for(j=0; j<=p-q; j++)
    {
        for(k=0; k<q; k++)
        {
            if(String2[k]!=String1[k+j])  break;
        }
        if(k==q)  return j;
    }
    return -1;
}

void LCS(char *String1,char *String2)
{
	int Size=0,Index=-1;
	int i,j,k;

	int n=strlen(String1);

	// Generatinng all the substrings of String1
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n+1;j++) 
		{
			char Temp[j-i+1],Length=0;
			for(k=i;k<j;k++) 
			{
				Temp[Length++]=String1[k];
			}
			Temp[Length]='\0';	

			// Checking if any substring of string1 is present in string2
			int Ind=Find_SubString(String2,Temp);

			// Find using strstr()
			// char *P=strstr(String2,Temp);
			// if(!P) continue;
			// int Ind=P-String2;
			if(Ind>-1)
			{
				// If substring exits , then taking the longest of them 
				if(strlen(Temp)>Size)
				{
					Index=Ind;
					Size=strlen(Temp);
				}
			}
		}
	}


	// Printing the longest common substring
	if(Index>-1)
	{
		for(i=Index;i<Index+Size;i++)
		{
			printf("%c",String2[i]);
		}
	}
}

int main()
{
	char String1[10]="abcdxyz",String2[10]="xyzabcd";
	LCS(String1,String2);
}