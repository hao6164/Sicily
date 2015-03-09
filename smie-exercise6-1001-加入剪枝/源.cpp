//#include<bits/stdc++.h>
#include<iostream>
#include<queue>
struct puzzle_cell{
	int x, y, branches;

};
using namespace std;

void deep_possess(int row, int col);
void deep_possess2();
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
		deep_possess2();
		if (solutions_count > 1)
			cout << "Puzzle " << i + 1 << " has " << solutions_count << " solutions" << endl;
		else if (solutions_count == 0)
			cout << "Puzzle " << i + 1 << " has no solution" ;
		else
		{
			//puzzles_out.pop();
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
		cout << endl;
		solutions_count = 0;
	}
	return 0;
}
void deep_possess2()
{
	int minx = -1;
	int miny = -1;
	bool mark2[10];
	int bian2 = 20;
	
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			if (puzzle[row][col]==0)
			{		
				bool mark[10];//mark【0】没用
				memset(mark, false, sizeof(mark));
				int bian = 0;
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
					if (mark[i] == false)
						bian++;
				}
				if (bian<bian2)
				{
					bian2 = bian;
					minx = row;
					miny = col;
					memcpy(mark2, mark, sizeof(mark));
				}

			}
		}
	}
	if (minx<0)
	{
		solutions_count++;
		memcpy(puzzles_outtemp, puzzle, sizeof(puzzle));
		return;
	}
	for (int i = 1; i < 10; i++)
	{
		if (!mark2[i])
		{
			puzzle[minx][miny] = i;
			deep_possess2();//next

			puzzle[minx][miny] = 0;//调回来恢复现场
		}
	}
	
}
