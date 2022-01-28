#include <iostream>
using namespace std;

/*
1: Select any 1 
2: Horizontally Nearest 0
3: Vertically Nearest 1
4: Diagonally nearest 0
5: Down or Right nearest 1
*/

int main()
{
    int r = 0, c = 0;
    int n = 4, m = 4;
    int A[4][4] =
        {{0, 1, 1, 1},
         {1, 0, 0, 0},
         {1, 0, 1, 1},
         {1, 0, 0, 0}};

    // 1
    while (!A[r][c])
    {
        cout << "Select a green square: ";
        cin >> r >> c;
    }
    // 2
    for (int i = 0;; i++)
    {
        if (c + i < m && !A[r][c + i])
        {
            c += i;
            break;
        }
        if (c - i > -1 && !A[r][c - i])
        {
            c -= i;
            break;
        }
    }
    // 3
    for (int i = 0;; i++)
    {
        if (r + i < n && A[r + i][c])
        {
            r += i;
            break;
        }
        if (r - i > -1 && A[r - i][c])
        {
            r -= i;
            break;
        }
    }
    // 4
    for (int i = 0;; i++)
    {
        if (r + i < n && c + i < m && !A[r + i][c + i])
        {
            r += i;
            c += i;
            break;
        }
        if (r - i > -1 && c - i > -1 && !A[r - i][c - i])
        {
            r -= i;
            c -= i;
            break;
        }
        if (r + i < n && c - i > -1 && !A[r + i][c - i])
        {
            r += i;
            c -= i;
            break;
        }
        if (r - i > -1 && c + i < m && !A[r - i][c + i])
        {
            r -= i;
            c += i;
            break;
        }
    }
    // 5
    for (int i = 0;; i++)
    {
        // Down
        if (r + i < n && A[r + i][c])
        {
            r += i;
            break;
        }
        // Right
        if (c + i < m && A[r][c + i])
        {
            c += i;
            break;
        }
    }
    cout << "Destination: " << r << " " << c << endl;
}