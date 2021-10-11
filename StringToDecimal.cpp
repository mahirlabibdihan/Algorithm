#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
unsigned long long StringToDecimal(string Number)
{
	unsigned long long Decimal=0;
	int n=Number.length(),i;

	for(i=0;i<n;i++)
	{
		Decimal*=10;
		Decimal+=Number[i]-48;
	}

	return Decimal;
}

string DecimalToString(unsigned long long Decimal)
{
	string Number;
	while(Decimal>0)
	{
		Number+=48+Decimal%10;
		Decimal/=10;
	}
	reverse(Number.begin(),Number.end());
	return Number;
}

int main()
{
	string Number;
	cin>>Number;
	cout<<StringToDecimal(Number)<<endl;
	cout<<DecimalToString(StringToDecimal(Number));
}