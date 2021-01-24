/*
 ______   _________ _      _       _
|  ____ \|___   ___| |    | |     | |
| |    \ \   | |   | |____| |     | |
| |    | |   | |   |  ____  |     | |
| |____/ /___| |___| |    | |_____| |
|_______/|_________|_|    |_________|
M A H I R     L A B I B     D I H A N

*/


/* 
	+   ->    Series
	|   ->    Parallel



Sample Input : 10+10+(4|(5+6))
Sample Output : 22.93333333333   (Without Scaling)
Sample Output : 22.93333   (With scale = 5)
*/

int scale=15;
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
string Pi = "3.141592654";
int AddCarry;
int SubCarry;
string Add(string, string);
string Div(string, string);
string Mul(string, string);
string Sub(string, string);
string Mod(string, string);
string Bodmash(string);
string Parallel(string,string);
string Scale(string,int,int=0);
pair<string,string> Fraction(string);
int main()
{	
	string In;
	while (1)
	{
		cout<<": ";
		getline(cin, In);
		if(In=="exit") exit(0);
		cout << "-> "<<Scale(Bodmash(In),scale) << endl<<endl;		// For Scaled Output after decimal Point
		// cout << "-> "<< Bodmash(In) << endl<<endl;		// Output Without Scaling
	}
}

string Trim(string a)
{
	if (a == "∞") return a;
	string Int, Frac;
	int i, n = a.length();

	for (i = 0; i < n; i++)
	{
		if (a[i] == '.') break;
		Int += a[i];
	}
	for (; i < n; i++)
	{
		Frac += a[i];
	}

	if (Int[0] == '-')
		while (Int.length() > 0 && Int[0] == '0')
		{
			Int.erase(Int.begin() + 1);
		}

	else
		while (Int.length() > 0 && Int[0] == '0')
		{
			Int.erase(Int.begin());
		}

	while (Frac.length() > 0 && Frac.back() == '0')
	{
		Frac.pop_back();
	}
	if (Frac.length() > 0 && Frac.back() == '.')
	{
		Frac.pop_back();
	}

	string Number = Int + Frac;
	if (Number.length() > 0) return Number;
	return "0";
}

int Compare(string a, string b)
{
	a = Trim(a);
	b = Trim(b);
	//cout<<"->"<<a<<" "<<b<<endl;
	int i, n = a.length(), m = b.length();
	string Num1Int, Num1Frac, Num2Int, Num2Frac;

	for (i = 0; i < n; i++)
	{
		if (a[i] == '.') break;
		Num1Int += a[i];
	}
	for (i++; i < n; i++)
	{
		Num1Frac += a[i];
	}

	for (i = 0; i < m; i++)
	{
		if (b[i] == '.') break;
		Num2Int += b[i];
	}
	for (i++; i < m; i++)
	{
		Num2Frac += b[i];
	}

	if (Num1Int[0] == '-')
		while (Num1Int.length() > 0 && Num1Int[0] == '0')
		{
			Num1Int.erase(Num1Int.begin() + 1);
		}

	else
		while (Num1Int.length() > 0 && Num1Int[0] == '0')
		{
			Num1Int.erase(Num1Int.begin());
		}

	if (Num2Int[0] == '-')
		while (Num2Int.length() > 0 && Num2Int[0] == '0')
		{
			Num2Int.erase(Num2Int.begin() + 1);
		}

	else
		while (Num2Int.length() > 0 && Num2Int[0] == '0')
		{
			Num2Int.erase(Num2Int.begin());
		}

	while (Num1Frac.length() > 0 && Num1Frac.back() == '0')
	{
		Num1Frac.pop_back();
	}
	while (Num2Frac.length() > 0 && Num2Frac.back() == '0')
	{
		Num2Frac.pop_back();
	}

	if (Num1Int.length() == 0) Num1Int = "0";
	if (Num2Int.length() == 0) Num2Int = "0";
	if (Num1Frac.length() == 0) Num1Frac = "0";
	if (Num2Frac.length() == 0) Num2Frac = "0";
	// cout<<endl<<"->1."<<Num1Int<<" 2."<<Num1Frac<<" 3."<<Num2Int<<" 4."<<Num2Frac<<endl;

	if (Num1Int[0] == '-' && Num2Int[0] != '-') return -1;
	else if (Num1Int[0] != '-' && Num2Int[0] == '-') return 1;

	if (Num1Int.length() > Num2Int.length()) return 1;
	else if (Num1Int.length() == Num2Int.length())
	{
		if (Num1Int > Num2Int) return 1;
		else if (Num1Int == Num2Int)
		{
			if (Num1Frac > Num2Frac) return 1;
			else if (Num1Frac < Num2Frac) return -1;
			else return 0;
		}
		else return -1;
	}
	else return -1;
}

string Scale(string a, int n=15, int round)
{
	int i, j, s = a.length();
	for (i = 0; i < s; i++)
	{
		if (a[i] == '.') break;
	}
	//cout<<m.length()-i-4<<endl;
	for (j = 0; j < s - i - n - 2; j++)
	{
		a.pop_back();
	}
	if (j == s - i - n - 2)
	{
		if (round == 1)
		{
			a.pop_back();
			if (a.back() == '.')
			{
				a.pop_back();
			}
			a.back()++;
		}
		else if (round == -1)
		{
			a.pop_back();
			if (a.back() == '.')
			{
				a.pop_back();
			}

		}

		else if (round == 0)
		{
			if (a.back() > '4')
			{

				if (a[a.length() - 2] == '.')
				{
					a.pop_back();
					a.pop_back();
					a.back()++;
				}
				else if (a[a.length() - 2] < '9')
				{
					a.pop_back();
					a.back()++;
				}

			}
			else
			{
				a.pop_back();
			}
		}

	}

	a = Trim(a);
	return a;
}

bool hasPrecedence(char op1, char op2) 
{
	if (op2 == '(' || op2 == ')')
		return false;
	else
		return true;
}

string applyOp(char op, string b, string a) 
{
	switch (op) {
	case '+':
		return Add(a, b);
		break;
	case '|': 
		return Parallel(a,b);
		break;
	}
	return "0";
}

string Bodmash(string expression)
{
	if (expression.length() == 0) return "";


	stack<string> values;
	stack<char> ops;

	for (int i = 0; i < expression.length(); i++)
	{
		if(expression[i]==' ') continue;
		if ((expression[i] >= '0' && expression[i] <= '9') || expression[i] == '.') {
			string num = "";
			while (i < expression.length() && (expression[i] >= '0' && expression[i] <= '9' || expression[i] == '.'))
				num += expression[i++];
			i--;
			values.push(num);
		}
		else if (expression[i] == '(') ops.push(expression[i]);

		else if (expression[i] == ')') {
			while (ops.top() != '(') {
				string value1, value2;
				if (!values.empty()) {
					value1 = values.top();
					values.pop();
				}
				else value1 = "0";
				if (!values.empty()) {
					value2 = values.top();
					values.pop();
				} else value2 = "0";
				values.push(applyOp(ops.top(), value1, value2));
				ops.pop();
			}
			ops.pop();
		}

		else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '%' || expression[i] == '^' ||expression[i] == 'p' ||expression[i] == 'c' ||expression[i] == 'g' ||expression[i] == 'l' ||expression[i] == '&' ||expression[i] == '|'  )
		 {
			while (!ops.empty() && hasPrecedence(expression[i], ops.top())) {
				string value1, value2;
				if (!values.empty()) {
					value1 = values.top();
					values.pop();
				}
				else value1 = "0";
				if (!values.empty()) {
					value2 = values.top();
					values.pop();
				} else value2 = "0";
				values.push(applyOp(ops.top(), value1, value2));
				ops.pop();
			}
			ops.push(expression[i]);
		}

		else if (expression[i] == '!')
		{
			while (!ops.empty() && hasPrecedence(expression[i], ops.top()))
			{
				string value = values.top();
				values.pop();
				values.push(applyOp(ops.top(), value, value));
				ops.pop();
			}
			ops.push(expression[i]);
		}
	}

	while (!ops.empty()) {
		string value1, value2;
		if (!values.empty()) {
			value1 = values.top();
			values.pop();
		}
		else value1 = "0";
		if (!values.empty()) {
			value2 = values.top();
			values.pop();
		} else
			value2 = "0";
		values.push(applyOp(ops.top(), value1, value2));
		ops.pop();
	}
	string Decimal = values.top();
	values.pop();
	// System.out.println(FromDecimal(Decimal,To));
	return Decimal;
}

string DivDigit(string a, string b)
{
	a = Trim(a);
	b = Trim(b);
	if (Compare(b, "0") == 0) return "∞";
	string i, j = "0";
	for (i = "0"; Compare(j, a) < 1;)
	{
		j = Add(j, b);
		i = Add(i, "1");
	}
	return Sub(i, "1");
}

string Mod(string Number, string Mod)
{
	if (Number.length() == 0) return Number;
	bool Negative = false;
	Number = Trim(Number);
	Mod = Trim(Mod);
	if (Compare(Mod, "0") < 1) return "∞";


	if (Number[0] == '-')
	{
		Number.erase(Number.begin());
		Negative = true;
	}
	string temp1 = DivDigit(Number, Mod);
	//cout<<temp1<<endl;
	string temp2 = Mul(Mod, temp1);
	string temp4 = Sub(Number, temp2);
	//cout<<Number<<" "<<Mod<<" "<<temp1<<" "<<temp2<<" "<<temp4<<endl;
	return (Negative ? "-" : "") + temp4;
}

string Div(string a, string b)
{
	// cout<<a<<" "<<b<<endl;
	a = Trim(a);
	b = Trim(b);

	if (Compare(b, "0") == 0) return "∞";
	//cout<<a<<" "<<b<<endl;
	bool Negative = false;


	if (a[0] == '-' && b[0] == '-')
	{
		a.erase(a.begin());
		b.erase(b.begin());
	}
	else if (a[0] == '-')
	{
		a = a.substr(1, a.length());
		Negative = true;
	}
	else if (b[0] == '-')
	{
		b = b.substr(1, b.length());
		Negative = true;
	}

	string Div;
	string Num1, Num2;

	int i, p = 0, q = 0;

	for (i = 0; i < a.length(); i++)
	{
		if (a[i] == '.')
		{
			p = a.length() - 1 - i;
		}
		else
		{
			Num1 += a[i];
		}
	}

	for (i = 0; i < b.length(); i++)
	{
		if (b[i] == '.')
		{
			q = b.length() - 1 - i;
		}
		else
		{
			Num2 += b[i];
		}
	}

	// cout<<Num1<<" "<<Num2<<endl;

	if (p > q)
	{
		for (i = 0; i < p - q; i++)
		{
			Num2 += '0';
		}
	}

	else if (p < q)
	{
		for (i = 0; i < q - p; i++)
		{
			Num1 += '0';
		}
	}

	// cout<<Num1<<" "<<Num2<<" "<<endl;

	string temp;

	if (Compare(Num2, Num1) == 1)
	{
		// cout<<"######"<<endl;
		temp = Num1 + "0";
		Div = ".";


		// cout<<Div<<" "<<temp<<endl;

		for (i = 0; i < 15 && Compare(temp, "0") == 1; i++)
		{
			Div += DivDigit(temp, Num2);
			temp = Mod(temp, Num2);
			temp += '0';
			// cout<<"-"<<Div<<endl;
		}

		return (Negative ? "-" : "") + Div;
	}


	for (i = -1; Compare(Num2, temp) == 1;)
	{
		temp += Num1[++i];
	}



	for (; (i < Num1.length());)
	{
		Div += DivDigit(temp, Num2);
		//cout<<" -"<<Div<<endl;
		temp = Mod(temp, Num2);

		if (++i < Num1.length())
			temp += Num1[i];
	}

	//cout<<Div<<" "<<temp<<endl;


	Div += (Compare(temp, "0") == 1) ? "." : "";

	for (; (i - Num1.length() < 11 && Compare(temp, "0") == 1); i++)
	{
		temp += '0';
		Div += DivDigit(temp, Num2);
		temp = Mod(temp, Num2);
	}

	if (i - Num1.length() == 11)
	{
		if (Div.back() == Div[Div.length() - 2] && Div.back() > '4')
			Div.back()++;
	}

	return (Negative ? "-" : "") + Div;
}

string Sub_Int(string a, string b)
{
	string Subion;
	int i, n = a.length(), m = b.length();

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());


	int p = max(m, n);

	for (i = 0; i < p; i++)
	{
		int temp, temp1, temp2;

		if (i > n - 1)
		{
			temp1 = 0;
		}
		else
		{
			temp1 = a[i] - 48;
		}

		if (i > m - 1)
		{
			temp2 = 0;
		}
		else
		{
			temp2 = b[i] - 48;
		}

		temp = temp1 - temp2 + 10 * (SubCarry + temp2 > temp1) - SubCarry;
		SubCarry = (SubCarry + temp2 > temp1);

		Subion += temp + 48;
	}

	reverse(Subion.begin(), Subion.end());
	return Subion;
}

string Sub_Frac(string a, string b)
{
	string Subion;
	int i, n = a.length(), m = b.length();

	int p = max(m, n);

	for (i = p - 1; i > -1; i--)
	{
		int temp, temp1, temp2;
		if (i > n - 1)
		{
			temp1 = 0;
		}
		else
		{
			temp1 = a[i] - 48;
		}

		if (i > m - 1)
		{
			temp2 = 0;
		}
		else
		{
			temp2 = b[i] - 48;
		}

		temp = temp1 - temp2 + 10 * (SubCarry + temp2 > temp1) - SubCarry;
		SubCarry = (SubCarry + temp2 > temp1);

		Subion += temp + 48;
	}

	reverse(Subion.begin(), Subion.end());

	return (Subion.length() > 0 ? "." : "") + Subion;
}

string Sub(string Num1, string Num2)
{
	Num1 = Trim(Num1);
	Num2 = Trim(Num2);
	if (Num1[0] == '-' && Num2[0] == '-')
	{
		swap(Num1, Num2);

	}
	else if (Num1[0] == '-')
	{
		return Add(Num1, "-" + Num2);
	}
	else if (Num2[0] == '-') return Add(Num1, Num2.substr(1, Num2.length() - 1));
	string Num1Int, Num1Frac, Num2Int, Num2Frac;
	int i, n = Num1.length(), m = Num2.length();
	bool Negative = false;

	for (i = 0; i < n & Num1[i] != '.'; i++)
	{
		Num1Int += Num1[i];
	}

	for (i++; i < n; i++)
	{
		Num1Frac += Num1[i];
	}

	for (i = 0; i < m & Num2[i] != '.'; i++)
	{
		Num2Int += Num2[i];
	}

	for (i++; i < m; i++)
	{
		Num2Frac += Num2[i];
	}

	if (Num1Int.length() == 0) Num1Int = "0";
	if (Num2Int.length() == 0) Num2Int = "0";

	string SubFrac, SubInt;

	if (Compare(Num1, Num2) < 0)
	{
		SubFrac = Sub_Frac(Num2Frac, Num1Frac);
		SubInt = Sub_Int(Num2Int, Num1Int);
		Negative = true;
	}
	else
	{
		SubFrac = Sub_Frac(Num1Frac, Num2Frac);
		SubInt = Sub_Int(Num1Int, Num2Int);
	}

	if (SubInt.length())
		while (SubInt[0] == '0')
		{
			SubInt = SubInt.substr(1, SubInt.length());
		}

	if (SubFrac.length())
	{
		while (SubFrac.back() == '0')
		{
			SubFrac.pop_back();
		}
		if (SubFrac.back() == '.')
		{
			SubFrac.pop_back();
		}
	}
	SubCarry = 0;
	string Subion = (Negative ? "-" : "") + SubInt + SubFrac;
	if (Subion.length()) return Subion;
	return "0";
}

string Mul(string a, string b)
{
	// cout<<a<<" "<<b<<endl;
	a = Trim(a);
	b = Trim(b);
	if (Compare(a, "0") == 0 || Compare(b, "0") == 0) return "0";
	bool Negative = false;
	if (a[0] == '-' && b[0] == '-')
	{
		a.erase(a.begin());
		b.erase(b.begin());
	}

	else if (a[0] == '-')
	{
		Negative = true;
		a.erase(a.begin());
	}

	else if (b[0] == '-')
	{
		Negative = true;
		b.erase(b.begin());
	}

	string Num1, Num2, Mul;
	if (a.length() == 0) a = "0";
	if (b.length() == 0) b = "0";
	int i, j, n = a.length(), m = b.length(), p = 0, q = 0;

	for (i = 0; i < n; i++)
	{
		if (a[i] != '.')
		{
			Num1 += a[i];
		}
		else
		{
			p = n - 1 - i;
		}
	}

	for (i = 0; i < m; i++)
	{
		if (b[i] != '.')
		{
			Num2 += b[i];
		}
		else
		{
			q = m - 1 - i;
		}
	}

	reverse(Num1.begin(), Num1.end());
	reverse(Num2.begin(), Num2.end());

	n = Num1.length();
	m = Num2.length();

	for (i = 0; i < n + m; i++)
	{
		Mul += '0';
	}

	//cout<<Num1<<" "<<Num2<<endl;

	for (i = 0; i < n; i++)
	{
		int Carry = 0;
		int temp1 = Num1[i] - '0';

		for (j = 0; j < m; j++)
		{
			// cout<<".";
			int temp2 = Num2[j] - '0';

			int temp = temp1 * temp2 + Mul[i + j] + Carry - 48;

			Mul[i + j] = (temp % 10) + 48;

			Carry = temp / 10;

			// cout<<Num1[i]<<" "<<Num2[j]<<" "<<temp<<" "<<Carry<<" "<<Mul[i+j]<<endl;
		}

		if (Carry) Mul[i + j] += Carry;
	}


	while (Mul.length() > 0 && Mul.back() == '0') Mul.pop_back();

	n = Mul.length();

	if (p + q > 0)
	{
		if (p + q > n)
		{
			for (i = n; i < p + q; i++)
			{
				Mul += '0';
			}
		}

		Mul.insert(Mul.begin() + p + q, '.');
		reverse(Mul.begin(), Mul.end());
		while (Mul.back() == '0') Mul.pop_back();
		if (Mul.back() == '.') Mul.pop_back();
	}

	else
	{
		reverse(Mul.begin(), Mul.end());
	}

	// cout<<Mul<<endl;
	if (Mul.length() > 0) return (Negative ? "-" : "") + Mul;
	return "0";
}

string Add_Int(string a, string b)
{
	string Addition;
	int i, n = a.length(), m = b.length();

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	if (m > n) { swap(a, b); swap(n, m);}

	int p = max(m, n);

	for (i = 0; i < p; i++)
	{
		int temp, temp1, temp2;

		if (i > n - 1)
		{
			temp1 = 0;
		}
		else
		{
			temp1 = a[i] - 48;
		}

		if (i > m - 1)
		{
			temp2 = 0;
		}
		else
		{
			temp2 = b[i] - 48;
		}

		temp = temp1 + temp2 + AddCarry;
		AddCarry = temp / 10;
		Addition += (temp % 10) + 48;
	}

	if (AddCarry) Addition += AddCarry + '0';

	reverse(Addition.begin(), Addition.end());

	return Addition;
}

string Add_Frac(string a, string b)
{
	string Addition;
	int i, n = a.length(), m = b.length();

	if (m > n) { swap(a, b); swap(n, m); }

	int p = max(m, n);

	for (i = p - 1; i > -1; i--)
	{
		int temp, temp1, temp2;

		if (i > n - 1)
		{
			temp1 = 0;
		}
		else
		{
			temp1 = a[i] - 48;
		}

		if (i > m - 1)
		{
			temp2 = 0;
		}
		else
		{
			temp2 = b[i] - 48;
		}

		temp = temp1 + temp2 + AddCarry;

		AddCarry = temp / 10;

		Addition += (temp % 10) + 48;
	}

	reverse(Addition.begin(), Addition.end());
	return (Addition.length() > 0 ? "." : "") + Addition;
}

string Add(string Num1, string Num2)
{
	Num1 = Trim(Num1);
	Num2 = Trim(Num2);
	bool Negative = false;
	if (Num1[0] == '-' && Num2[0] == '-')
	{
		Negative = true;
		Num1.erase(Num1.begin());
		Num2.erase(Num2.begin());
	}
	else if (Num1[0] == '-') return Sub(Num2, Num1.substr(1, Num1.length() - 1));
	else if (Num2[0] == '-') return Sub(Num1, Num2.substr(1, Num2.length() - 1));
	string Num1Int, Num1Frac, Num2Int, Num2Frac;

	int i, n = Num1.length(), m = Num2.length();

	for (i = 0; i < n & Num1[i] != '.'; i++)
	{
		Num1Int += Num1[i];
	}

	for (i++; i < n; i++)
	{
		Num1Frac += Num1[i];
	}

	for (i = 0; i < m & Num2[i] != '.'; i++)
	{
		Num2Int += Num2[i];
	}

	for (i++; i < m; i++)
	{
		Num2Frac += Num2[i];
	}

	string SumFrac = Add_Frac((Num1Frac > "" ? Num1Frac : "0"), (Num2Frac > "" ? Num2Frac : "0"));
	string SumInt = Add_Int((Num1Int > "" ? Num1Int : "0"), (Num2Int > "" ? Num2Int : "0"));

	while (SumInt[0] == '0') SumInt = SumInt.substr(1, SumInt.length());
	while (SumFrac.back() == '0') SumFrac.pop_back();
	if (SumFrac.back() == '.') SumFrac.pop_back();

	AddCarry = 0;
	return (Negative ? "-" : "") + (SumInt > "" ? SumInt : "0") + (SumFrac > "" ? SumFrac : "");
}

string Parallel(string a,string b)
{
	a=Div("1",a);
	b=Div("1",b);
	a=Add(a,b);
	a=Div("1",a);
	return Trim(a);
}
	