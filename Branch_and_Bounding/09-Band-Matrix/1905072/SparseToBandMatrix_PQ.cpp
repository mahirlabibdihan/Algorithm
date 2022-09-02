#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
#include <queue>
#include <chrono>
using namespace std;
using namespace chrono;

// int8_t c = 0;
// For same lowerbounds with multiple indices, prioritize the rightmost one

// O(n)
vector<int8_t> floatLeft(vector<int8_t> a, const int8_t &from, const int8_t &to)
{
    int8_t tmp = a[from];
    for (int8_t i = from; i > to; i--)
    {
        a[i] = a[i - 1];
    }
    a[to] = tmp;
    return a;
}

/********************************************************************************/
/***************** B O U N D   C A L C U L A T I O N  S T A R T *****************/
/********************************************************************************/
// O(n^2)
int8_t countFixedRows(vector<int8_t> &row_perm, vector<int8_t> &col_perm, const int8_t &level, vector<vector<bool>> &s_matrix, const int8_t &n)
{
    int8_t max_count = 0;
    int8_t n_fixed_rows = floor(level / 2.0);
    int8_t n_fixed_cols = ceil(level / 2.0);
    // Count along row_perm
    for (int8_t i = 0; i < n_fixed_rows; i++)
    {
        int8_t count_f_u = 0;
        // Topmost non zero element in fixed area
        for (int8_t j = 0; j <= i; j++)
        {
            if (s_matrix[row_perm[i]][col_perm[j]])
            {
                count_f_u = i - j + 1;
                break;
            }
        }

        int8_t count_f_d = 0;
        // Bottommost non zero element in fixed area
        for (int8_t j = n_fixed_cols - 1; j >= i; j--)
        {
            if (s_matrix[row_perm[i]][col_perm[j]])
            {
                count_f_d = j - i + 1;
                break;
            }
        }
        int8_t count_u = n_fixed_cols - i;
        // Bottommost non zero element in unfixed area
        for (int8_t j = n_fixed_cols; j < n; j++)
        {
            if (s_matrix[row_perm[i]][col_perm[j]])
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
int8_t countFixedCols(vector<int8_t> &row_perm, vector<int8_t> &col_perm, const int8_t &level, vector<vector<bool>> &s_matrix, const int8_t &n)
{
    int8_t max_count = 0;
    int8_t n_fixed_rows = floor(level / 2.0);
    int8_t n_fixed_cols = ceil(level / 2.0);
    for (int8_t i = 0; i < n_fixed_cols; i++)
    {
        int8_t count_f_l = 0;
        // Leftmost non zero element in fixed area
        for (int8_t j = 0; j < n_fixed_rows; j++)
        {
            if (s_matrix[row_perm[j]][col_perm[i]])
            {
                count_f_l = i - j + 1;
                break;
            }
        }

        int8_t count_f_r = 0;
        // Rightmost non zero element in fixed area
        for (int8_t j = n_fixed_rows - 1; j >= i; j--)
        {
            if (s_matrix[row_perm[j]][col_perm[i]])
            {
                count_f_r = j - i + 1;
                break;
            }
        }
        int8_t count_u = n_fixed_rows - i;
        // Rightmost non zero element in unfixed area
        for (int8_t j = n_fixed_rows; j < n; j++)
        {
            if (s_matrix[row_perm[j]][col_perm[i]])
            {
                count_u++;
            }
        }
        // If there are X's in unfixed part
        if (count_u > n_fixed_rows - i)
        {
            max_count = max(count_u, max_count);
        }
        max_count = max(count_f_l, max_count);
        max_count = max(count_f_r, max_count);
    }
    return max_count;
}
int8_t countUnfixedRows(vector<int8_t> &row_perm, vector<int8_t> &col_perm, const int8_t &level, vector<vector<bool>> &s_matrix, const int8_t &n)
{
    int8_t max_count = 0;
    int8_t n_fixed_rows = floor(level / 2.0);
    // Count along row_perm
    for (int8_t i = n_fixed_rows; i < n; i++)
    {
        int8_t count = 0;
        for (int8_t j = 0; j < n; j++)
        {
            if (s_matrix[row_perm[i]][col_perm[j]])
            {
                count++;
            }
        }
        max_count = max(count, max_count);
    }
    return (max_count + 1) / 2;
}
int8_t countUnfixedCols(vector<int8_t> &row_perm, vector<int8_t> &col_perm, const int8_t &level, vector<vector<bool>> &s_matrix, const int8_t &n)
{
    int8_t max_count = 0;
    int8_t n_fixed_cols = ceil(level / 2.0);
    // Count along col_perm
    for (int8_t i = n_fixed_cols; i < n; i++)
    {
        int8_t count = 0;
        for (int8_t j = 0; j < n; j++)
        {
            if (s_matrix[row_perm[j]][col_perm[i]])
            {
                count++;
            }
        }
        max_count = max(count, max_count);
    }
    return (max_count + 1) / 2;
}

// O(n^2)
int8_t countFixed(vector<int8_t> &row_perm, vector<int8_t> &col_perm, const int8_t &level, vector<vector<bool>> &s_matrix, const int8_t &n)
{
    int8_t cfr = countFixedRows(row_perm, col_perm, level, s_matrix, n);
    int8_t cfc = countFixedCols(row_perm, col_perm, level, s_matrix, n);
    return max(cfr, cfc);
}

// O(n^2)
int8_t countUnfixed(vector<int8_t> &row_perm, vector<int8_t> &col_perm, const int8_t &level, vector<vector<bool>> &s_matrix, const int8_t &n)
{
    int8_t cur = countUnfixedRows(row_perm, col_perm, level, s_matrix, n);
    int8_t cuc = countUnfixedCols(row_perm, col_perm, level, s_matrix, n);
    return max(cur, cuc);
}

// O(n^2)
int8_t calcBound(vector<int8_t> &row_perm, vector<int8_t> &col_perm, const int8_t &level, vector<vector<bool>> &s_matrix, const int8_t &n)
{

    int8_t cf = countFixed(row_perm, col_perm, level, s_matrix, n);
    int8_t cu = countUnfixed(row_perm, col_perm, level, s_matrix, n);
    return max(cf, cu);
}
/********************************************************************************/
/******************* B O U N D   C A L C U L A T I O N  E N D *******************/
/********************************************************************************/

struct Node
{
    vector<int8_t> row_perm;
    vector<int8_t> col_perm;
    int8_t bound;
    int8_t level;
    int8_t order;
    Node(vector<int8_t> row_perm, vector<int8_t> col_perm, int8_t level, int8_t bound, int8_t order)
    {
        this->row_perm = row_perm;
        this->col_perm = col_perm;
        this->bound = bound;
        this->level = level;
        this->order = order;
    }
    bool operator<(const Node &next) const
    {
        if (next.bound <= this->bound)
        {
            if (next.bound < this->bound)
            {
                return true;
            }
            else if (next.level >= this->level)
            {
                if (next.level > this->level)
                {
                    return true;
                }
                else if (next.order > this->order)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

void toBandMatrix(vector<int8_t> &row_perm, vector<int8_t> &col_perm, vector<vector<bool>> &s_matrix, const int8_t &n)
{
    priority_queue<Node> pq;
    int8_t n_fixed_rows = 0, n_fixed_cols = 0;
    for (int8_t i = 0; i < n; i++)
    {
        row_perm[i] = col_perm[i] = i;
    }
    pq.push(Node(row_perm, col_perm, 0, calcBound(row_perm, col_perm, 0, s_matrix, n), 0));
    while (true)
    {
        // c++;
        Node curr = pq.top();
        pq.pop();
        if (curr.level == 2 * (n - 1))
        {
            // cout << pq.size() << endl;
            row_perm = curr.row_perm;
            col_perm = curr.col_perm;

            break;
        }
        if (curr.level % 2 == 0) // Need to fix column
        {
            int8_t n_fixed_cols = curr.level / 2;
            for (int8_t i = n_fixed_cols; i < n; i++)
            {
                vector<int8_t> new_col_perm = floatLeft(curr.col_perm, i, n_fixed_cols);
                int8_t lb = calcBound(curr.row_perm, new_col_perm, curr.level + 1, s_matrix, n);
                pq.push(Node(curr.row_perm, new_col_perm, curr.level + 1, lb, i));
            }
        }
        else // Need to fix row
        {
            int8_t n_fixed_rows = curr.level / 2;
            for (int8_t i = n_fixed_rows; i < n; i++)
            {
                vector<int8_t> new_row_perm = floatLeft(curr.row_perm, i, n_fixed_rows);
                int8_t lb = calcBound(new_row_perm, curr.col_perm, curr.level + 1, s_matrix, n);
                pq.push(Node(new_row_perm, curr.col_perm, curr.level + 1, lb, i));
            }
        }
    }
}

// O(n^2)
int8_t calcBand(vector<int8_t> &row_perm, vector<int8_t> &col_perm, vector<vector<bool>> &s_matrix, const int8_t &n)
{
    int8_t band = 0;
    for (int8_t i = 0; i < n; i++)
    {
        for (int8_t j = 0; j < n; j++)
        {
            if (s_matrix[row_perm[i]][col_perm[j]])
            {
                band = max(band, int8_t(1 + abs(j - i)));
            }
        }
    }
    return band;
}

int main()
{
    freopen("in_07.txt", "r", stdin);
    // chrono::time_point<system_clock> startTime = chrono::high_resolution_clock::now();
    int16_t n;
    scanf("%d", &n);
    vector<vector<bool>> s_matrix(n, vector<bool>(n, false));
    // s_matrix = vector<vector<bool>>(n, vector<char>(n));

    // Sparse matrix input
    for (int8_t i = 0; i < n; i++)
    {
        for (int8_t j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            if (c == 'X')
            {
                s_matrix[i][j] = true;
            }
            else
            {
                s_matrix[i][j] = false;
            }
        }
    }

    // Arrays to store permutation of row and column
    vector<int8_t> row_perm(n), col_perm(n);
    toBandMatrix(row_perm, col_perm, s_matrix, n);
    // cout << c << endl;

    // Minimal band matrix form
    int16_t band = calcBand(row_perm, col_perm, s_matrix, n);
    cout << band << endl;
    for (int8_t i = 0; i < n; i++)
    {
        for (int8_t j = 0; j < n; j++)
        {
            if (s_matrix[row_perm[i]][col_perm[j]])
            {
                cout << "X ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    // chrono::time_point<system_clock> endTime = chrono::high_resolution_clock::now();
    // printf("%g ms\n", chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count() / (1000000.0));
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