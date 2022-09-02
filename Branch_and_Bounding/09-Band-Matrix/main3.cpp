#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

// Space complexity: n^2 + 2n + 2n
vector<int> b_rows, b_cols;    // row,column permutation for minimal band matrix
vector<vector<char>> s_matrix; // Original sparse matrix
int min_band = INT_MAX;        // Minimum band found so far
int n;                         // Dimension of matrix
// int c = 0;

// For same lowerbounds with multiple indices, prioritize the rightmost one
bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.first < b.first)
    {
        return true;
    }
    else if (a.first == b.first)
    {
        if (a.second > b.second)
        {
            return true;
        }
    }
    return false;
}

// O(n)
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
int countFixedRows(vector<int> &row_perm, vector<int> &col_perm, const int &n_fixed_rows, const int &n_fixed_cols)
{
    int max_count = 0;
    // Count along row_perm
    for (int i = 0; i < n_fixed_rows; i++)
    {
        int count_f_u = 0;
        // Topmost non zero element in fixed area
        for (int j = 0; j <= i; j++)
        {
            if (s_matrix[row_perm[i]][col_perm[j]] == 'X')
            {
                count_f_u = i - j + 1;
                break;
            }
        }

        int count_f_d = 0;
        // Bottommost non zero element in fixed area
        for (int j = n_fixed_cols - 1; j >= i; j--)
        {
            if (s_matrix[row_perm[i]][col_perm[j]] == 'X')
            {
                count_f_d = j - i + 1;
                break;
            }
        }
        int count_u = n_fixed_cols - i;
        // Bottommost non zero element in unfixed area
        for (int j = n_fixed_cols; j < n; j++)
        {
            if (s_matrix[row_perm[i]][col_perm[j]] == 'X')
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
int countFixedCols(vector<int> &row_perm, vector<int> &col_perm, const int &n_fixed_rows, const int &n_fixed_cols)
{
    int max_count = 0;
    for (int i = 0; i < n_fixed_cols; i++)
    {
        int count_f_l = 0;
        // Leftmost non zero element in fixed area
        for (int j = 0; j < n_fixed_rows; j++)
        {
            if (s_matrix[row_perm[j]][col_perm[i]] == 'X')
            {
                count_f_l = i - j + 1;
                break;
            }
        }

        int count_f_r = 0;
        // Rightmost non zero element in fixed area
        for (int j = n_fixed_rows - 1; j >= i; j--)
        {
            if (s_matrix[row_perm[j]][col_perm[i]] == 'X')
            {
                count_f_r = j - i + 1;
                break;
            }
        }
        int count_u = n_fixed_rows - i;
        // Rightmost non zero element in unfixed area
        for (int j = n_fixed_rows; j < n; j++)
        {
            if (s_matrix[row_perm[j]][col_perm[i]] == 'X')
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

int countUnfixedRows(vector<int> &row_perm, vector<int> &col_perm, const int &n_fixed_rows, const int &n_fixed_cols)
{
    int max_count = 0;

    // Count along row_perm
    for (int i = n_fixed_rows; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (s_matrix[row_perm[i]][col_perm[j]] == 'X')
            {
                count++;
            }
        }
        max_count = max(count, max_count);
    }
    return (max_count + 1) / 2;
}
int countUnfixedCols(vector<int> &row_perm, vector<int> &col_perm, const int &n_fixed_rows, const int &n_fixed_cols)
{
    int max_count = 0;

    // Count along col_perm
    for (int i = n_fixed_cols; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (s_matrix[row_perm[j]][col_perm[i]] == 'X')
            {
                count++;
            }
        }
        max_count = max(count, max_count);
    }
    return (max_count + 1) / 2;
}

// O(n^2)
int countFixed(vector<int> &row_perm, vector<int> &col_perm, const int &n_fixed_rows, const int &n_fixed_cols)
{
    int cfr = countFixedRows(row_perm, col_perm, n_fixed_rows, n_fixed_cols);
    int cfc = countFixedCols(row_perm, col_perm, n_fixed_rows, n_fixed_cols);
    return max(cfr, cfc);
}

// O(n^2)
int countUnfixed(vector<int> &row_perm, vector<int> &col_perm, const int &n_fixed_rows, const int &n_fixed_cols)
{
    int cur = countUnfixedRows(row_perm, col_perm, n_fixed_rows, n_fixed_cols);
    int cuc = countUnfixedCols(row_perm, col_perm, n_fixed_rows, n_fixed_cols);
    return max(cur, cuc);
}

// O(n^2)
int calcBound(vector<int> &row_perm, vector<int> &col_perm, const int &n_fixed_rows, const int &n_fixed_cols)
{

    int cf = countFixed(row_perm, col_perm, n_fixed_rows, n_fixed_cols);
    int cu = countUnfixed(row_perm, col_perm, n_fixed_rows, n_fixed_cols);
    return max(cf, cu);
}

// O(n^2)
int calcBand(vector<int> &row_perm, vector<int> &col_perm)
{
    int band = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (s_matrix[row_perm[i]][col_perm[j]] == 'X')
            {
                band = max(band, 1 + abs(j - i));
            }
        }
    }
    return band;
}
void toBandMatrix(vector<int> &row_perm, vector<int> &col_perm, int &n_fixed_rows, int &n_fixed_cols)
{
    /*
    Faster maybe?
    int actual_band = calcBand(row_perm, col_perm); // n^2
    int lower_bound = calcBound(row_perm, col_perm, n_fixed_rows, n_fixed_cols); // n^2
    if (lower_bound == actual_band)
    {
        if (actual_band < min_band)
        {
            min_band = actual_band;
            b_rows = row_perm;
            b_cols = col_perm;
        }
        return;
    }
    */
    // c++;
    // Stop branching
    if (n_fixed_rows == n - 1 && n_fixed_cols == n - 1)
    {
        int band = calcBand(row_perm, col_perm);
        if (band < min_band)
        {
            min_band = band;
            b_rows = row_perm;
            b_cols = col_perm;
        }
        return;
    }

    if (n_fixed_rows == n_fixed_cols) // Fix column
    {
        int min_lb = n;
        vector<pair<int, int>> lb_map;
        for (int i = n_fixed_cols; i < n; i++)
        {
            floatLeft(col_perm, i, n_fixed_cols);
            n_fixed_cols++;
            {
                int lb = calcBound(row_perm, col_perm, n_fixed_rows, n_fixed_cols);
                lb_map.push_back({lb, i});
            }
            n_fixed_cols--;
            floatRight(col_perm, n_fixed_cols, i);
        }

        sort(lb_map.begin(), lb_map.end(), comp);

        for (int i = 0; i < n - n_fixed_cols && lb_map[i].first < min_band; i++)
        {
            floatLeft(col_perm, lb_map[i].second, n_fixed_cols);
            n_fixed_cols++;
            {
                toBandMatrix(row_perm, col_perm, n_fixed_rows, n_fixed_cols);
            }
            n_fixed_cols--;
            floatRight(col_perm, n_fixed_cols, lb_map[i].second);
        }
    }
    else // Fix row
    {
        int min_band = n;
        vector<pair<int, int>> lb_map;
        for (int i = n_fixed_rows; i < n; i++)
        {
            floatLeft(row_perm, i, n_fixed_rows);
            n_fixed_rows++;
            {
                int lb = calcBound(row_perm, col_perm, n_fixed_rows, n_fixed_cols);
                lb_map.push_back({lb, i});
            }
            n_fixed_rows--;
            floatRight(row_perm, n_fixed_rows, i);
        }
        sort(lb_map.begin(), lb_map.end(), comp);
        for (int i = 0; i < n - n_fixed_rows && lb_map[i].first < min_band; i++)
        {
            floatLeft(row_perm, lb_map[i].second, n_fixed_rows);
            n_fixed_rows++;
            {
                toBandMatrix(row_perm, col_perm, n_fixed_rows, n_fixed_cols);
            }
            n_fixed_rows--;
            floatRight(row_perm, n_fixed_rows, lb_map[i].second);
        }
    }
}
int main()
{
    // freopen("input.in", "r", stdin);
    cin >> n;
    s_matrix = vector<vector<char>>(n, vector<char>(n));

    // Sparse matrix input
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> s_matrix[i][j];
        }
    }

    // Arrays to store permutation of row and column
    vector<int> row_perm(n), col_perm(n);
    for (int i = 0; i < n; i++)
    {
        row_perm[i] = col_perm[i] = i;
    }

    int n_fixed_rows = 0, n_fixed_cols = 0;
    toBandMatrix(row_perm, col_perm, n_fixed_rows, n_fixed_cols);
    // cout << c << endl;

    // Minimal band matrix form
    cout << min_band << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << s_matrix[b_rows[i]][b_cols[j]] << " ";
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

If we just use the info of which row/col is fixed at each level, we don't need to change s_matrix each time.

Add two parameters: new_rows[], new_cols[]
Each time change this arrays instead of whole s_matrix.
Make the whole s_matrix from this two arrays while calculating bound.
*/