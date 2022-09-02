#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

vector<vector<char>> ans;
vector<vector<char>> tmp;
int min_band_g = INT_MAX;
int n;
int c = 0;
vector<vector<char>> floatRowLeft(vector<vector<char>> m, int from, int to)
{
    for (int i = 0; i < n; i++)
    {
        int tmp = m[from][i];
        for (int j = from; j > to; j--)
        {
            m[j][i] = m[j - 1][i];
        }
        m[to][i] = tmp;
    }
    return m;
}
vector<vector<char>> floatColLeft(vector<vector<char>> m, int from, int to)
{
    for (int i = 0; i < n; i++)
    {
        int tmp = m[i][from];
        for (int j = from; j > to; j--)
        {
            m[i][j] = m[i][j - 1];
        }
        m[i][to] = tmp;
    }
    return m;
}
// even - column
// odd - row
int countI(vector<vector<char>> m, int n_fixed_rows, int n_fixed_cols)
{
    int max_count = 0;
    for (int i = 0; i < n_fixed_cols; i++)
    {
        int count = 0;
        for (int j = n_fixed_rows; j < n; j++)
        {
            if (m[j][i] == 'X')
            {
                count++;
            }
        }
        max_count = max(n_fixed_cols - i + count, max_count);
    }
    for (int i = 0; i < n_fixed_rows; i++)
    {
        int count = 0;
        for (int j = n_fixed_cols; j < n; j++)
        {
            if (m[i][j] == 'X')
            {
                count++;
            }
        }
        max_count = max(n_fixed_rows - i + count, max_count);
    }
    return max_count;
}

int countII(vector<vector<char>> m, int n_fixed_rows, int n_fixed_cols)
{
    int max_count = 0;
    for (int i = n_fixed_rows; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (m[i][j] == 'X')
            {
                count++;
            }
        }
        max_count = max(count, max_count);
    }
    for (int i = n_fixed_cols; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (m[j][i] == 'X')
            {
                count++;
            }
        }
        max_count = max(count, max_count);
    }
    return (max_count + 1) / 2;
}

int calcBound(vector<vector<char>> m, int n_fixed_rows, int n_fixed_cols)
{
    return max(countI(m, n_fixed_rows, n_fixed_cols), countII(tmp, n_fixed_rows, n_fixed_cols));
}

void toBandMatrix(vector<vector<char>> m, int n_fixed_rows, int n_fixed_cols)
{
    if (n_fixed_rows == n - 1 && n_fixed_cols == n - 1)
    {
        int band = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (m[i][j] == 'X')
                {
                    band = max(band, 1 + abs(j - i));
                }
            }
        }
        if (band < min_band_g)
        {
            min_band_g = band;
            ans = m;
        }
        return;
    }

    if (n_fixed_rows == n_fixed_cols)
    {
        // if (n_fixed_cols == n)
        //     return;
        int min_band = n;
        for (int i = n_fixed_cols; i < n; i++)
        {
            tmp = floatColLeft(m, i, n_fixed_cols);
            int band = calcBound(tmp, n_fixed_rows, n_fixed_cols + 1);
            min_band = min(band, min_band);
        }
        for (int i = n_fixed_cols; i < n; i++)
        {
            tmp = floatColLeft(m, i, n_fixed_cols);
            int band = calcBound(tmp, n_fixed_rows, n_fixed_cols + 1);
            if (band == min_band)
            {
                toBandMatrix(tmp, n_fixed_rows, n_fixed_cols + 1);
            }
        }
    }
    else
    {
        // if (n_fixed_rows == n)
        //     return;
        int min_band = n;
        for (int i = n_fixed_rows; i < n; i++)
        {
            tmp = floatRowLeft(m, i, n_fixed_rows);
            int band = calcBound(tmp, n_fixed_rows + 1, n_fixed_cols);
            min_band = min(band, min_band);
        }
        for (int i = n_fixed_rows; i < n; i++)
        {
            tmp = floatRowLeft(m, i, n_fixed_rows);
            int band = calcBound(tmp, n_fixed_rows + 1, n_fixed_cols);
            if (band == min_band)
            {
                toBandMatrix(tmp, n_fixed_rows + 1, n_fixed_cols);
            }
        }
    }
}
int main()
{
    cin >> n;
    vector<vector<char>> m(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }
    toBandMatrix(m, 0, 0, 0);
    cout << min_band_g << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
/*
  1 2 3 4         3 2 4 1
1 X O O X       2 X O O O
2 O O X O   =>  4 X X X O
3 X O O X       3 O O X X
4 O X X X       1 O O X X

(n!) row x (n!) col = (n!)^2 permutations

If we just use the info of which row/col is fixed at each level, we don't need to change matrix each time.

Add two parameters: new_rows[], new_cols[]
Each time change this arrays instead of whole matrix.
Make the whole matrix from this two arrays while calculating bound.
*/