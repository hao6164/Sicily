#include<iostream>
#include<algorithm>
#include <cstdio>
using namespace std;
int myabs(int a)
{
	if (a >= 0)
		return a;
	else
		return -a;
};
long choosefrom(int* databuf, int left, int right);
int maxdifference = 0;
int d[1001][1001] = {-1};
int main()
{
	int n, k = 0;
	
	while (1)
	{
		for (int i = 0; i <= 1000; i++)
	for (int j =0; j <= 1000; j++)
		d[i][j] = 100100;
		k++;
		cin >> n;
		if (n == 0)
		{

			break;
		}
		int* databuf = new int[n];
		for (size_t i = 0; i < n; i++)
		{
			cin >> databuf[i];
		}
		maxdifference=choosefrom(databuf, 0, n - 1);
		delete databuf;

		cout << "In game " << k << ", the greedy strategy might lose by as many as " << maxdifference << " points." << endl;

		maxdifference = 0;

	}
	return 0;
}
long choosefrom(int* databuf, int left, int right)
{
	if (right<left)
	{
		return 0;
	}
	if (d[left][right] != 100100)
		return d[left][right];
	long max1, max2;
	if (databuf[right]>databuf[left+1])//a取left b右
	{
		max1 = choosefrom(databuf, left + 1, right - 1)+databuf[left]-databuf[right];
	}
	else if (databuf[right]<=databuf[left + 1])//a取left b左
	{
		max1 = choosefrom(databuf, left + 2, right) + databuf[left] -databuf[left+1];
	}
	if (databuf[right-1]>databuf[left])//a取right b右
	{
		max2 = choosefrom(databuf, left, right - 2) + databuf[right] - databuf[right-1];
	}
	else if (databuf[right-1] <= databuf[left])//a取right b左
	{
		max2 = choosefrom(databuf, left + 1, right-1) + databuf[right] - databuf[left];
	}
	d[left][right] = max(max1, max2);
		return d[left][right];
	
}