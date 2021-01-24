
int main()
{	
	string In;
	while (1)
	{
		cout<<": ";
		getline(cin, In);
		if(In=="exit") exit(0);
		cout << "-> "<<Bodmash(In) << endl<<endl;
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



string Parallel(string a,string b)
{
	a=Div("1",a);
	b=Div("1",b);
	a=Add(a,b);
	a=Div("1",a);
	return a;
}
	