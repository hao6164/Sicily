//#include<bits/stdc++.h>
#include<iostream>
#include<queue>
struct puzzle_cell{
	int x, y, branches;

};
using namespace std;

void deep_possess(int row, int col);
int puzzle[9][9];
int puzzles_outtemp[9][9];
int solutions_count = 0;
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 81; j++)
		{
			memset(puzzle, 0, sizeof(puzzle));
		}
		for (int j = 0; j < 81; j++)
		{
			char temp;
			cin >> temp;
			if (temp == 95)
				puzzle[j / 9][j % 9] = 0;
			else
				puzzle[j / 9][j % 9] = temp - 48;

		}


		deep_possess(0, 0);



		if (solutions_count > 1)
			cout << "Puzzle " << i + 1 << " has " << solutions_count << " solutions"<<endl;
		else if (solutions_count == 0)
			cout << "Puzzle " << i + 1 << " has no solution" << endl;
		else
		{
			cout << "Puzzle " << i + 1 << " solution is" << endl;
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					cout << puzzles_outtemp[i][j];
				}
				cout << endl;
			}
		}
		solutions_count = 0;
		cout<<endl;
	}
	return 0;
}
void deep_possess(int row, int col)
{
	if (col == 9)
	{
		solutions_count++;
		memcpy(puzzles_outtemp, puzzle, sizeof(puzzle));
		//cout << "done"<<endl;
		return;
	}
	if (puzzle[row][col] != 0)
	{
		if (row == 8)
			deep_possess(0, col + 1);//next
		else
			deep_possess(row + 1, col);//next
	}
	else
	{

		bool mark[10];//mark【0】没用
		memset(mark, false, sizeof(mark));
		for (int i = 0; i < 9; i++)
		{
			if (puzzle[row][i] != 0)
			{
				mark[puzzle[row][i]] = true;
			}
			if (puzzle[i][col] != 0)
			{
				mark[puzzle[i][col]] = true;
			}
			if (puzzle[row / 3 * 3 + i / 3][col / 3 * 3 + i % 3] != 0)
			{
				mark[puzzle[row / 3 * 3 + i / 3][col / 3 * 3 + i % 3]] = true;
			}
		}
		for (int i = 1; i < 10; i++)
		{
			if (!mark[i])
			{
				puzzle[row][col] = i;
				if (row == 8)
					deep_possess(0, col + 1);//next
				else
					deep_possess(row + 1, col);//next

				puzzle[row][col] = 0;//调回来恢复现场
			}
		}
	}
}
