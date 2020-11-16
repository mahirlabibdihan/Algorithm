#include<iostream>
#include<algorithm>
using namespace std;

int Carry=0;

string Add_Int(string a,string b)
{
	string Addition;
	int i,n=a.length(),m=b.length();

	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());

	if(m>n) { swap(a,b); swap(n,m);}

	int p=max(m,n);

	for(i=0;i<p;i++)
	{
		int temp,temp1,temp2;
		if(i>n-1)
		{
			temp1=0;
		}
		else
		{
			temp1=a[i]-48;
		}

		if(i>m-1)
		{
			temp2=0;
		}
		else
		{
			temp2=b[i]-48;
		}

		temp=temp1+temp2+Carry;

		Carry=temp/10;

		Addition+=(temp%10)+48;
		
	}

	if(Carry) Addition+=Carry;

	reverse(Addition.begin(),Addition.end());

	return Addition;
}

string Add_Frac(string a,string b)
{
	string Addition;
	int i,n=a.length(),m=b.length();

	if(m>n) { swap(a,b); swap(n,m); }

	int p=max(m,n);

	for(i=p-1;i>-1;i--)
	{
		int temp,temp1,temp2;

		if(i>n-1)
		{
			temp1=0;
		}
		else
		{
			temp1=a[i]-48;
		}

		if(i>m-1)
		{
			temp2=0;
		}
		else
		{
			temp2=b[i]-48;
		}

		temp=temp1+temp2+Carry;

		Carry=temp/10;

		Addition+=(temp%10)+48;
	}

	reverse(Addition.begin(),Addition.end());
	return (Addition.length()>0?".":"")+Addition;
}


string Add(string Num1,string Num2)
{
	string Num1Int,Num1Frac,Num2Int,Num2Frac;

	int i,n=Num1.length(),m=Num2.length();

	for(i=0;i<n&Num1[i]!='.';i++)
	{
		Num1Int+=Num1[i];
	}
	
	for(i++;i<n;i++)
	{
		Num1Frac+=Num1[i];
	}

	for(i=0;i<m&Num2[i]!='.';i++)
	{
		Num2Int+=Num2[i];
	}
	
	for(i++;i<m;i++)
	{
		Num2Frac+=Num2[i];
	}

	string SumFrac=Add_Frac(Num1Frac,Num2Frac);
	string SumInt=Add_Int(Num1Int,Num2Int);

	return SumInt+SumFrac;
}

int main()
{
	string Num1,Num2;
	cin>>Num1>>Num2;
	cout<<Add(Num1,Num2);
}