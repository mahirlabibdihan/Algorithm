#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main()
{
	int Possible[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<vector<set<int>>> Solve(9, vector<set<int>>(9, set<int>(Possible, Possible + 9)));
	int i, j, a, b, c, d, e;
	bool Found = true;
	int Sudoku[9][9];
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			cin>>Sudoku[i][j];
		}
	}
	
	while (Found)
	{
		Found = false;
		for (i = 0; i < 9; i += 3)
		{
			for (j = 0; j < 9; j += 3)
			{
				for (a = i; a < i + 3; a++)
				{
					for (b = j; b < j + 3; b++)
					{
						for (c = i; c < i + 3; c++)
						{
							for (d = j; d < j + 3; d++)
							{
								if (Sudoku[c][d] == 0)
								{
									Solve[c][d].erase(Sudoku[a][b]);
									for (e = 0; e < 9; e++)
									{
										Solve[c][d].erase(Sudoku[c][e]);
										Solve[c][d].erase(Sudoku[e][d]);
									}
									if (Solve[c][d].size() == 1)
									{
										Found = true;
										Sudoku[c][d] = *Solve[c][d].begin();
									}
								}
							}
						}
					}
				}
			}
		}
	}

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if((j+1)%3==0&&j+1<9)
				cout << Sudoku[i][j] << " | ";
			else
			cout << Sudoku[i][j] << "\t";
		}
		cout << endl;
		// if((i+1)%3==0&&i+1<9)
		// {
		// 	cout<<"——————————|———————————|———————————";
		// }
		if((i+1)%3==0&&i+1<9)
		{
			cout<<"----------|-----------|-----------";
		}
		else if(i+1<9)
		{
			cout<<"          |           |           ";
		}
		cout<<endl;
	}
}