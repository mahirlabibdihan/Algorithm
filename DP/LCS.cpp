#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
/*string maxStr(string s1, string s2)
{
    return s1.length() > s2.length() ? s1 : s2;
}
string LCS(string s1, string s2)
{
    int s1_size = s1.length();
    int s2_size = s2.length();
    string dp[51][51];
    for (int i = 0; i <= s1_size; i++)
    {
        for (int j = 0; j <= s2_size; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = "";
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + s1[i - 1];
            }
            else
            {
                dp[i][j] = maxStr(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    for (int i = 0; i <= s1_size; i++)
    {
        for (int j = 0; j <= s2_size; j++)
        {
            cout << dp[i][j] << ",";
        }
        cout << endl;
    }
    return dp[s1_size][s2_size];
}*/
string backtrack(vector<vector<int>> dp, string s1, int s1_size, int s2_size)
{
    string lcs(dp[s1_size][s2_size], '\0');
    int k = dp[s1_size][s2_size]; // Iterator for lcs
    int i = s1_size;              // Iterator for string 1
    int j = s2_size;              // Iterator for string 2
    // O(s1_size+s2_size)
    while (k > 0)
    {
        if (dp[i][j] > dp[i][j - 1] && dp[i][j] > dp[i - 1][j])
        {
            lcs[--k] = s1[i - 1];
            i--;
            j--;
        }
        else
        {
            if (dp[i][j] == dp[i - 1][j])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    return lcs;
}
string LCS(string s1, string s2)
{
    int s1_size = s1.length();
    int s2_size = s2.length();
    vector<vector<int>> dp(s1_size + 1, vector<int>(s2_size + 1));
    // O(s1_size*s2_size)
    for (int i = 0; i <= s1_size; i++)
    {
        for (int j = 0; j <= s2_size; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    // for (int i = 0; i <= s1_size; i++)
    // {
    //     for (int j = 0; j <= s2_size; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // O(s1_size+s2_size)
    return backtrack(dp, s1, s1_size, s2_size);
}
int main()
{
    ifstream f1("original.txt"); // taking file as inputstream
    ostringstream ss1;
    ss1 << f1.rdbuf(); // reading data
    string s1 = ss1.str();
    f1.close();

    ifstream f2("copied.txt"); // taking file as inputstream
    ostringstream ss2;
    ss2 << f2.rdbuf(); // reading data
    string s2 = ss2.str();
    f2.close();

    cout << s1.length() << " " << s2.length() << endl;
    string lcs = LCS(s1, s2);
    cout << lcs.length() << endl;
    cout << (100.0 * lcs.length() / s2.length()) << endl;
}