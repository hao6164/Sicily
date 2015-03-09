#include<iostream>
using namespace std;
void find_solutions(int,int);
int out_counts = 0;
int queue_mark[2][9];
bool check(int row, int col);
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < 9; i++)
		{
			queue_mark[0][i] = -1;
			queue_mark[1][i] = -1;
		}

		find_solutions(n,0);
		cout<<out_counts<<endl;
		out_counts=0;
		
	}
	return 0;
}
void find_solutions(int n,int col)
{
	if (col==n)
	{
		out_counts++;
			return;
	}
	for (int i = 0; i < n; i++)
	{
		if (check(i, col))
			continue;
		else
		{
			queue_mark[0][col] =i;
			queue_mark[1][col] = col;
			find_solutions(n, col + 1);
		}
	}
	return;
}
bool check(int row, int col)
{
	for (int i = 0; i < col; i++)
	{
		if (queue_mark[0][i] == row || queue_mark[1][i] == col || (abs(queue_mark[0][i] - row) == abs(queue_mark[1][i]-col)))
			return true;
	}
	return false;
}