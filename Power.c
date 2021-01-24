
#include "Make.h"
// ll pow(ll a,ll b)
// {int c=1;while(b--)c*=a;return c;}


int recursivePower(int x,int n)
{
    if(n==0) return 1;
    return x*recursivePower(x,n-1);
}


int binaryExponentiation(int x,int n)
{
    if(n==0) return 1;
    else if(n%2 == 0) return binaryExponentiation(x*x,n/2);
    else return x*binaryExponentiation(x*x,(n-1)/2);
}

double Root(double n,double x)
{
	double l = 0, r = n, m = 0;
	if (n<=1) r = 1;
	while (r-l>.000000000001)
	{
		double temp = (l+r)/2;
		if (m==temp)
		{
			break;
		}
		m = temp;
		(binaryExponentiation(m,x)>n)? r = m : l = m;
	}
	return m;
}

pair<double,double> Fraction(double s)
{
	string WholeNum = s ,DecNum=1;

	int i,j;

	while(WholeNum-int(WholeNum)>.0000001)
	{	
		WholeNum*=10;
		DecNum*=10;

	}

	string temp = WholeNum;
	for (i =2; i<=WholeNum ;i++)
	{
		if (fmod(WholeNum , i)== 0 && fmod(DecNum , i)== 0)
		{
			WholeNum / = i;
			DecNum / =i ;
		}
	}
	return {WholeNum,DecNum}; 
}

double Power(double Number,double Power)
{
	pair<double,double> Num(Fraction(Power));
	// cout<<"->"<<Power<<" "<<Num<<" "<<Div<<endl;
	Number =binaryExponentiation(Number, Num.first);
	// cout<<endl<<Num<<" "<<Div<<" "<<Number<<endl;
	if (Num.second> 1) return Root(Number,Num.second);
	return Number;
}


// string strpow(string a,string b)
// {
// 	string c="1";

// 	if(b[0]<'0')
// 	{
// 		b[0]=96-b[0];
// 		while(b>"0")
// 		{
// 			b=Substract(b,"1");
// 			c=Divide(c,a);
// 			//cout<<c<<endl;
// 		}
// 	}

// 	else
// 	{
// 		while(b>"0")
// 		{
// 			b=Substract(b,"1");
// 			c=Multiply(c,a);
// 		}

// 	}
// 	return c;
// }

int main()
{

}