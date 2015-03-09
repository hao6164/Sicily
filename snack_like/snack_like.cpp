// snack_like.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include <iomanip>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	cin >> n;
	while (n)
	{
	int **snack_matrix;
	
	int num = 1;
	
	snack_matrix = new int*[n + 1];
	for (size_t j = 1; j <= n; j++)
	{
		snack_matrix[j] = new int[n + 1];
	}
	for (size_t i = 1; i <= n / 2; i++)
	{
		for (size_t k = 0; k < n - i - i + 1; k++)
		{
			snack_matrix[i + k][n - i + 1] = num;
			num++;

		}
		for (size_t k = 0; k < n - i - i + 1; k++)
		{
			snack_matrix[n - i + 1][n - i + 1 - k] = num;
			num++;

		}
		for (size_t k = 0; k < n - i - i + 1; k++)
		{
			snack_matrix[n - i + 1 - k][i] = num;
			num++;

		}
		for (size_t k = 0; k < n - i - i + 1; k++)
		{
			snack_matrix[i][i + k] = num;
			num++;

		}

	}
	if (n%2==1)
	snack_matrix[n / 2 + 1][n / 2 + 1] = num;
	cout << setiosflags(ios::right);
	for (size_t i = 1; i <= n; i++)
	{
		for (size_t j = 1; j <= n; j++)
		{
			cout << setw(4) << snack_matrix[i][j];

		}
		cout << endl;
	}
	delete snack_matrix;
	cin >> n;
}
	system("pause");
	return 0;
}

