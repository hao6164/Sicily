#include<iostream>
//#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		if (n<0)
			break;
		else
		{

			if (n == 0)
			{
				printf("%d\n",1);
				continue;
			}
			int** matrix = new int*[n];

			for (int i = 0; i<n; i++)
			{
				int* matrix_row = new int[8];
				matrix[i] = matrix_row;
			}
			matrix[0][0] = 0;
			matrix[0][1] = 1;
			matrix[0][2] = 0;
			matrix[0][3] = 0;
			matrix[0][4] = 1;
			matrix[0][5] = 0;
			matrix[0][6] = 0;
			matrix[0][7] = 1;

			for (int i = 1; i<n; i++)    //从第一列开始构建6*n的矩阵表，从buttom向上的动态规划
			{
				matrix[i][0] = matrix[i - 1][1] + matrix[i - 1][4] + matrix[i - 1][7];
				matrix[i][1] = matrix[i - 1][0] + matrix[i - 1][6];
				matrix[i][2] = matrix[i - 1][5];
				matrix[i][3] = matrix[i - 1][4];
				matrix[i][4] = matrix[i - 1][0] + matrix[i - 1][3];
				matrix[i][5] = matrix[i - 1][2];
				matrix[i][6] = matrix[i - 1][1];
				matrix[i][7] = matrix[i - 1][0];
			}
			printf("%d\n", matrix[n - 1][0]);
			delete matrix;
		}
	}
	return 0;
}