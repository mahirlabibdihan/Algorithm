#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

void floatLeft(vector<int> &a, const int &from, const int &to)
{
    int tmp = a[from];
    for (int i = from; i > to; i--)
    {
        a[i] = a[i - 1];
    }
    a[to] = tmp;
}

// O(n)
void floatRight(vector<int> &a, const int &from, const int &to)
{
    int tmp = a[from];
    for (int i = from; i < to; i++)
    {
        a[i] = a[i + 1];
    }
    a[to] = tmp;
}

// O(n^2)
int countFixedRows(vector<int> &rows, vector<int> &cols, const int &n_fixed_rows, const int &n_fixed_cols)
{
    int max_count = 0;
    // Count along rows
    for (int i = 0; i < n_fixed_rows; i++)
    {
        int count_f_u = 0;
        // Topmost non zero element in fixed area
        for (int j = 0; j <= i; j++)
        {
            if (s_matrix[rows[i]][cols[j]] == 'X')
            {
                count_f_u = i - j + 1;
                break;
            }
        }

        int count_f_d = 0;
        // Bottommost non zero element in fixed area
        for (int j = n_fixed_cols - 1; j >= i; j--)
        {
            if (s_matrix[rows[i]][cols[j]] == 'X')
            {
                count_f_d = j - i + 1;
                break;
            }
        }
        int count_u = n_fixed_cols - i;
        // Bottommost non zero element in unfixed area
        for (int j = n_fixed_cols; j < n; j++)
        {
            if (s_matrix[rows[i]][cols[j]] == 'X')
            {
                count_u++;
            }
        }

        // If there are X's in unfixed part
        if (count_u > n_fixed_cols - i)
        {
            max_count = max(count_u, max_count);
        }
        max_count = max(count_f_d, max_count);
        max_count = max(count_f_u, max_count);
    }
    return max_count;
}
int countFixedCols(vector<int> &rows, vector<int> &cols, const int &n_fixed_rows, const int &n_fixed_cols)
{
    int max_count = 0;
    for (int i = 0; i < n_fixed_cols; i++)
    {
        int count_f_l = 0;
        // Leftmost non zero element in fixed area
        for (int j = 0; j < n_fixed_rows; j++)
        {
            if (s_matrix[rows[j]][cols[i]] == 'X')
            {
                count_f_l = i - j + 1;
                break;
            }
        }

        int count_f_r = 0;
        // Rightmost non zero element in fixed area
        for (int j = n_fixed_rows - 1; j >= i; j--)
        {
            if (s_matrix[rows[j]][cols[i]] == 'X')
            {
                count_f_r = j - i + 1;
                break;
            }
        }
        int count_u = n_fixed_rows - i;
        // Rightmost non zero element in unfixed area
        for (int j = n_fixed_rows; j < n; j++)
        {
            if (s_matrix[rows[j]][cols[i]] == 'X')
            {
                count_u++;
            }
        }
        if (count_u > n_fixed_rows - i)
        {
            max_count = max(count_u, max_count);
        }
        max_count = max(count_f_l, max_count);
        max_count = max(count_f_r, max_count);
    }
    return max_count;
}

int countUnfixedRows(vector<int> &rows, vector<int> &cols, const int &n_fixed_rows, const int &n_fixed_cols)
{
    int max_count = 0;

    // Count along rows
    for (int i = n_fixed_rows; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (s_matrix[rows[i]][cols[j]] == 'X')
            {
                count++;
            }
        }
        max_count = max(count, max_count);
    }
    return (max_count + 1) / 2;
}
int countUnfixedCols(vector<int> &rows, vector<int> &cols, const int &n_fixed_rows, const int &n_fixed_cols)
{
    int max_count = 0;

    // Count along cols
    for (int i = n_fixed_cols; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (s_matrix[rows[j]][cols[i]] == 'X')
            {
                count++;
            }
        }
        max_count = max(count, max_count);
    }
    return (max_count + 1) / 2;
}

// O(n^2)
int countFixed(vector<int> &rows, vector<int> &cols, const int &n_fixed_rows, const int &n_fixed_cols)
{
    int cfr = countFixedRows(rows, cols, n_fixed_rows, n_fixed_cols);
    int cfc = countFixedCols(rows, cols, n_fixed_rows, n_fixed_cols);
    return max(cfr, cfc);
}

// O(n^2)
int countUnfixed(vector<int> &rows, vector<int> &cols, const int &n_fixed_rows, const int &n_fixed_cols)
{
    int cur = countUnfixedRows(rows, cols, n_fixed_rows, n_fixed_cols);
    int cuc = countUnfixedCols(rows, cols, n_fixed_rows, n_fixed_cols);
    return max(cur, cuc);
}

// O(n^2)
int calcBound(vector<int> &rows, vector<int> &cols, const int &n_fixed_rows, const int &n_fixed_cols)
{

    int cf = countFixed(rows, cols, n_fixed_rows, n_fixed_cols);
    int cu = countUnfixed(rows, cols, n_fixed_rows, n_fixed_cols);
    return max(cf, cu);
}

// O(n^2)
int calcBand(vector<int> &rows, vector<int> &cols)
{
    int band = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (s_matrix[rows[i]][cols[j]] == 'X')
            {
                band = max(band, 1 + abs(j - i));
            }
        }
    }
    return band;
}