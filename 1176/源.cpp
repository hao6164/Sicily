#include<iostream>
using namespace std;
int myabs(int a)
{
	if (a >= 0)
		return a;
	else
		return -a;
};
void choosefrom(int* databuf, int left, int right, int Ascore, int Bscore);
int maxdifference = 0;
bool used_pos[1000][1000] = {false};
long sumdata = 0;
int main()
{
	int n,k=0;

	
	while (1)
	{
		k++;
		cin >> n;
		if (n==0)
		{

			break;
		}
		sumdata = 0;
		int* databuf=new int[n];
		for (size_t i = 0; i < n; i++)
		{
			cin >> databuf[i];
			sumdata += databuf[i];
		}
		choosefrom(databuf, 0, n - 1, 0, 0);
		delete databuf;

		cout << "In game " << k << ", the greedy strategy might lose by as many as " << maxdifference << " points." << endl;
		
		maxdifference = 0;
		
	}
	return 0;
}
void choosefrom(int* databuf, int left, int right, int Ascore, int Bscore)
{
	if (sumdata < Bscore + Bscore)
		return;
	if (used_pos[left][right])
		return;

	else
	{
		used_pos[left][right] = true;
	}
	if (left >= right-1)
	{
		
		if (maxdifference <  Ascore - Bscore + myabs(databuf[left] - databuf[right]))
			maxdifference = Ascore - Bscore+myabs(databuf[left]-databuf[right]);

		//if (-maxdifference> Ascore - Bscore)
		//	maxdifference = Bscore - Ascore + abs(databuf[left] - databuf[right]);
		used_pos[left][right] = false;
		return;
	}
	if (databuf[left + 1] >= databuf[right])
	{
		choosefrom(databuf, left+2, right, Ascore + databuf[left], Bscore + databuf[left + 1]);
	}
	else 
	{
		choosefrom(databuf, left + 1, right-1, Ascore + databuf[left], Bscore + databuf[right]);
	}
	if (databuf[left ] >= databuf[right-1])
	{
		choosefrom(databuf, left + 1, right-1, Ascore + databuf[right], Bscore + databuf[left]);
	}
	else
	{

		 choosefrom(databuf, left , right - 2, Ascore + databuf[right], Bscore + databuf[right-1]);
	}
	used_pos[left][right] = false;
	return;
}
