#include<iostream>
#include<algorithm>
using namespace std;

int Carry=0;

string Sub_Int(string a,string b)
{
	string Substraction;
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

		Carry=(Carry+temp2>temp1);
		
		temp=temp1-temp2+10*Carry-Carry;
		
		Substraction+=temp+48;
	}

	reverse(Substraction.begin(),Substraction.end());
	return Substraction;
}



string Sub_Frac(string a,string b)
{
	string Substraction;
	int i,n=a.length(),m=b.length();

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

		Carry=(Carry+temp2>temp1);

		temp=temp1-temp2+10*Carry-Carry;

		Substraction+=temp+48;
	}

	reverse(Substraction.begin(),Substraction.end());

	return (Substraction.length()>0?".":"")+Substraction;
}


string Substract(string Num1,string Num2)
{
	string Num1Int,Num1Frac,Num2Int,Num2Frac;

	int i,n=Num1.length(),m=Num2.length();
	bool Negative=false;

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

	string SubFrac,SubInt;

	if(Num2Int.length()>Num1Int.length()|(Num2Int.length()==Num1Int.length()&Num2Int>Num1Int))
	{
		SubFrac=Sub_Frac(Num2Frac,Num1Frac);
		SubInt=Sub_Int(Num2Int,Num1Int);
		Negative=true;
	}
	else
	{
		SubFrac=Sub_Frac(Num1Frac,Num2Frac);
		SubInt=Sub_Int(Num1Int,Num2Int);
	}

	return (Negative?"-":"")+SubInt+SubFrac;
}

int main()
{
	string Num1,Num2;
	cin>>Num1>>Num2;
	cout<<Substract(Num1,Num2);
}