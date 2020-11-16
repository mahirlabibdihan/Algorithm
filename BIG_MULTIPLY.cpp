#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string Multiply(string a,string b)
{
	string Num1,Num2,Mul;
	int i,j,n=a.length(),m=b.length(),p=0,q=0;

	for(i=0;i<n;i++)
	{
		if(a[i]!='.')
		{
			Num1+=a[i];
		}
		else
		{
			p=n-1-i;
		}
	}

	for(i=0;i<m;i++)
	{
		if(a[i]!='.')
		{
			Num2+=b[i];
		}
		else
		{
			q=m-1-i;
		}
	}

	reverse(Num1.begin(),Num1.end());
    reverse(Num2.begin(),Num2.end());

    n=Num1.length();
    m=Num2.length();

    for(i=0;i<n+m;i++)
    {
    	Mul+='0';
    }

    for (i=0; i<n; i++) 
    { 
        int Carry = 0; 
        int temp1 = Num1[i] - '0'; 

        for (j=0; j<m; j++) 
        { 
            int temp2 = Num2[j] - '0'; 
  
            int temp = temp1*temp2 + Mul[i+j] + Carry-48; 
            
            Mul[i+j] = (temp% 10)+48;

            Carry = temp/10; 
        } 

        if (Carry) Mul[i+j] += Carry; 
    } 

    while (Mul.back()=='0') Mul.pop_back(); 

	n=Mul.length();

	if(p+q>0)
	{
		if(p+q>n)
		{
			for(i=n;i<p+q;i++)
			{		
				Mul+='0';
			}
		}

	 	Mul.insert(Mul.begin()+p+q,'.');
	 	reverse(Mul.begin(),Mul.end());
	 	while (Mul.back()=='0') Mul.pop_back(); 
	 	if(Mul.back()=='.') Mul.pop_back(); 
	}

	else
	{
		reverse(Mul.begin(),Mul.end());
	}

	
	return Mul;
}


int main()
{
	string Num1,Num2;
	cin>>Num1>>Num2;
	cout<<Multiply(Num1,Num2);
}