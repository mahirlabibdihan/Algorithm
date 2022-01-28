#include <vector>
#include <string>
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
        if (pat[j] == pat[i])
        {
            j++;
        }
        lps[i] = j;
    }
    return lps;
}