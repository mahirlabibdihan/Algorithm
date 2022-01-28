#include <vector>
#include <string>
#include <iostream>
using namespace std;
vector<int> LPS(string pat)
{
	int n = pat.length();
	vector<int> lps(n);
	for (int i = 1, j = 0; i < n; i++)
	{
		while (j > 0 && pat[j] != pat[i])
		{
			j = lps[j - 1];
		}
		// j==0 or pat[j] == pat[i]
		if (pat[j] == pat[i])
		{
			j++;
		}
		lps[i] = j;
	}
	return lps;
}

void KMP(string pat, string txt)
{
	int m = pat.size(), n = txt.size(); //int c=0;
	vector<int> lps = LPS(pat);
	for (int i = 0, j = 0; i < n; i++)
	{
		while (j > 0 && pat[j] != txt[i])
		{
			j = lps[j - 1];
		}
		// j==0 or pat[j] == txt[i]
		if (pat[j] == txt[i])
		{
			j++;
		}
		if (j == m)
		{
			printf("Found pattern at index %d\n", i - j + 1);
			j = lps[j - 1];
		}
	}
}