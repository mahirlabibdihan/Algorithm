#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// O(n^1.59)
int makeEqualLength(string &a, string &b)
{
    while (a.length() < b.length()) a = '0' + a;
    while(b.length() < a.length()) b = '0' + b;
    return a.length();
}
string add(string a,string b)
{
	int n=a.length(),m=b.length();
	int len=makeEqualLength(a,b);
	int carry=0;
	string res;
	for(int i=len-1;i>=0;i--)
	{
		int sum = a[i]+b[i]+carry-2*'0';
		carry = sum/10;
		res = char((sum%10)+'0')+res;
	}
	if(carry) res = '1'+res;
	return res;
}
string sub(string a,string b)
{
	int n=a.length(),m=b.length();
	int len=makeEqualLength(a,b);
	int carry=0;
	string res;
	for(int i=len-1;i>=0;i--)
	{	
		int temp1=a[i]-'0';
		int temp2=b[i]-'0';

		int temp;
		if (carry + temp2 > temp1) {
			temp = (temp1 + 10) - (temp2 + carry);
			carry = 1;
		}
		else {
			temp = temp1 - (temp2 + carry);
			carry = 0;
		}
		res = char(temp+'0')+res;
	}
	return res;
}
string karatsuba(string a,string b)
{
	/*
	S1=> A*C
	S2=> B*D
	S3=> (A+B)*(C+D)
	S4=> S3-S2-S1 => (A+B)*(C+D)-AC-BD => (AC+AD+BC+BD)-AC-BD=A*D+B*C
	S5=> S1*(b^n)+S4*(b^(n/2))+S2

	b=base
	n=number of digits

	S10000 => AC  00  00
	  S400		AD+BC 00
	  	S2			  BD

	x=10^(n/2)*a+b
	y=10^(n/2)*c+d
	x*y=10^n*ac+10^(n/2)*(ad+bc)+bd
	*/
	int n=makeEqualLength(a,b);
	if(n==0) return 0;
	if(n==1)
	{
		return to_string(stoi(a)*stoi(b));
	}

	// Making even length
	if(n%2==1)
	{
		a='0'+a;
		b='0'+b;
		n++;
	} 

    string A = a.substr(0, n/2);
    string B = a.substr(n/2, n);
 	
    string C = b.substr(0, n/2);
    string D = b.substr(n/2, n);

    string s1 = karatsuba(A,C);
    string s2 = karatsuba(B,D);
    string s3 = karatsuba(add(A,B),add(C,D));
    string s4 = sub(s3,add(s1,s2));// add(karatsuba(A,D),karatsuba(B,C));

    for(int i=0;i<n;i++) s1+='0';
    for(int i=0;i<n/2;i++) s4+='0';

    string res=add(s1,add(s4,s2));

	while(res.size()>1 && res[0]=='0')
	{
		res = res.substr(1,res.size());
	} 
    return res;
} 
// O(n^2)
string multiply(string a,string b)
{
	int n=a.length(),m=b.length();
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	string mul;
	// Filling the result with '0'
	for (int i = 0; i < m + n; i++)
	{
		mul+='0';
	}

	for (int i = 0; i < n; i++)
	{
		int carry = 0;
		int j;
		for (j = 0; j < m; j++)
		{
			int temp = (a[i]-'0') * (b[j]-'0') + (mul[i + j]-'0') + carry;
			mul[i + j]= (temp % 10)+'0';
			carry = temp / 10;
		}

		if (carry) {
			mul[i + j]+=carry;
		}
	}

	while (mul.length() > 0 && mul.back() == '0') {
		mul.pop_back();
	}
	reverse(mul.begin(),mul.end());
	return mul;
}
int main()
{
	cout<<karatsuba("111","111");
}