#include <iostream>
#include <string.h>
#define M 100
#define N 100
using namespace std;
void LCS_length(string x, string y, int B[M][N], int C[M][N]) /* Dynamic programming */
{
    for (int i = 1; i <= x.length() - 1; i++)
        C[i][0] = 0;
    for (int j = 0; j <= y.length() - 1; j++)
        C[0][j] = 0;
    for (int i = 1; i <= x.length() - 1; i++)
    {
        for (int j = 1; j <= y.length() - 1; j++)
        {
            if (x[i] == y[j])
            {
                C[i][j] = C[i - 1][j - 1] + 1;
                B[i][j] = 0 /* Up&Left */;
            }
            else if (C[i - 1][j] > C[i][j - 1])
            {
                C[i][j] = C[i - 1][j];
                B[i][j] = 1 /* Up */;
            }
            else if (C[i - 1][j] < C[i][j - 1])
            {
                C[i][j] = C[i][j - 1];
                B[i][j] = 2 /* Left */;
            }
            else
            {
                if (C[i - 1][j - 1] < C[i][j - 1])
                {
                    C[i][j] = C[i][j - 1];
                    B[i][j] = 3 /* Up+Left */;
                }
                else
                {
                    C[i][j] = C[i][j - 1];
                    B[i][j] = 2 /* Left */;
                }
            }
        }
    }
}
void Print_LCS(string x, int B[M][N], int i, int j) /* Output LCS */
{
    if (!i || !j)
        return;
    if (B[i][j] == 0)
    {
        Print_LCS(x, B, i - 1, j - 1);
        cout << x[i];
    }
    else if (B[i][j] == 1)
        Print_LCS(x, B, i - 1, j);
    else if (B[i][j] == 2)
        Print_LCS(x, B, i, j - 1);
    else
    {
        cout << '(';
        Print_LCS(x, B, i - 1, j);
        cout << '+';
        Print_LCS(x, B, i, j - 1);
        cout << ')';
    }
}
int main()
{
    string x, y;
    cin >> x;
    cin >> y;
    x = ' ' + x;
    y = ' ' + y;
    int B[M][N], C[M][N];
    LCS_length(x, y, B, C);
    Print_LCS(x, B, x.length(), y.length());
}