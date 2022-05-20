#include <iostream>
#include <vector>
#include <climits>
using namespace std;
bool rowCheck(vector<vector<char>> table, char c)
{
    int n = table.size();
    int m = table[0].size();
    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        for (int j = 0; j < m; j++)
        {
            if (table[i][j] != c)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            return true;
        }
    }
    return false;
}
bool columnCheck(vector<vector<char>> table, char c)
{
    int n = table.size();
    int m = table[0].size();
    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        for (int j = 0; j < m; j++)
        {
            if (table[j][i] != c)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            return true;
        }
    }
    return false;
}
bool diagonalCheck(vector<vector<char>> table, char c)
{
    int n = table.size();
    int m = table[0].size();
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (table[i][i] != c)
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        return flag;
    }
    flag = true;
    for (int i = 0; i < n; i++)
    {
        if (table[i][m - i - 1] != c)
        {
            flag = false;
            break;
        }
    }
    return flag;
}
bool isUserWon(vector<vector<char>> table)
{
    if (rowCheck(table, 'x'))
    {
        return true;
    }
    if (columnCheck(table, 'x'))
    {
        return true;
    }
    if (diagonalCheck(table, 'x'))
    {
        return true;
    }
    return false;
}
bool isComputerWon(vector<vector<char>> table)
{
    if (rowCheck(table, 'o'))
    {
        return true;
    }
    if (columnCheck(table, 'o'))
    {
        return true;
    }
    if (diagonalCheck(table, 'o'))
    {
        return true;
    }
    return false;
}
struct Move
{
    int x, y, depth;
};
// We will choose the move that lasts long
Move TicTacToe(vector<vector<char>> table, int depth)
{
    // cout << depth << endl;
    int n = table.size();
    int m = table[0].size();
    Move computerBestMove = {-1, -1, -1};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (table[i][j] == '-')
            {
                table[i][j] = 'o';
                Move userBestMove = {-1, -1, INT_MAX};
                for (int p = 0; p < n; p++)
                {
                    for (int q = 0; q < m; q++)
                    {
                        if (table[p][q] == '-')
                        {
                            table[p][q] = 'x';
                            if (isUserWon(table))
                            {
                                if (depth < userBestMove.depth)
                                {
                                    userBestMove = {p, q, depth};
                                }
                            }
                            else
                            {
                                Move temp = TicTacToe(table, depth + 1);
                                if (temp.depth < userBestMove.depth)
                                {
                                    userBestMove = {p, q, temp.depth};
                                }
                            }
                            table[p][q] = '-';
                        }
                    }
                }
                if (userBestMove.depth > computerBestMove.depth)
                {
                    computerBestMove = {i, j, userBestMove.depth};
                }
                table[i][j] = '-';
            }
        }
    }
    if (computerBestMove.x == -1)
    {
        return {-1, -1, INT_MAX};
    }
    return computerBestMove;
}
void printTable(vector<vector<char>> table)
{
    for (auto i : table)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<vector<char>> table = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}};
    printTable(table);
    int slots = 9;
    while (true)
    {
        Move bestMove = TicTacToe(table, 0);
        if (bestMove.x == -1)
        {
            cout << "ERROR!" << endl;
            return -1;
        }
        table[bestMove.x][bestMove.y] = 'o';
        // cout << bestMove.depth << endl;
        cout << "COMPUTER:" << endl;
        printTable(table);
        if (isComputerWon(table))
        {
            cout << "You lose:)" << endl;
            return 0;
        }
        slots--;
        if (!slots)
        {
            break;
        }
        int x, y;
        cout << "Choose row and column: ";
        cin >> x >> y;
        table[x - 1][y - 1] = 'x';
        cout << "USER:" << endl;
        printTable(table);
        if (isUserWon(table))
        {
            cout << "You won!" << endl;
            return 0;
        }
        slots--;
        if (!slots)
        {
            break;
        }
    }
    cout << "Match Draw" << endl;
}