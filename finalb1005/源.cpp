#include<iostream>
using namespace std;
int matrix[16][16];
bool ban[16];
int N;
int totalsum = 0;
void dfs(int sum,int rows)
{
	if (rows>=N)
	{
		totalsum = totalsum < sum ? sum : totalsum;
		return;
	}
	for (int i = 0; i <N ; i++)
	{
		if (!ban[i])
		{
			ban[i] = true;
			//cout << matrix[rows][i] << " ";
			dfs(sum +matrix[rows][i], rows + 1);
			ban[i] = false;
		}
	}
}
int main()
{
	int T;
	cin>>T;
	while (true)
	{
		fill(ban, ban + 16, false);
		totalsum = 0;
		if (T <= 0)
			break;
		T--;
		
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> matrix[i][j];
			}
		}
		dfs(0, 0);
		cout << totalsum << endl;
	}
	return 0;
}