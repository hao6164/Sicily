#include<iostream>
#include<queue>
using namespace std;
bool chess[9][9];
queue<int> hao;
int find(int a1, int b1, int c1, int d1)
{
	if (a1 == c1&&b1==d1)
		return 0;

	hao.push(a1 * 10 + b1);
	chess[a1][b1] = true;
	int pos;
	int count = 0;
	bool reached=false;
	while(!hao.empty())
	{
		pos=hao.front();
		hao.pop();
		for (int i = -1; i < 2; i=i+2)
		{
			for (int j = -1; j < 2; j=j + 2)
			{
				for (int k = -1; k < 2; k=k + 2)
				{
					int newx = pos %100/ 10 + (-1)*i*(1.5 + 0.5*k);
					int newy = pos % 10 + (-1)*j*(1.5 - 0.5*k);
					if (newx == c1&&newy == d1)
					{
						count = pos / 100 + 1;
						reached = true;
					}
					if (newx>0 && newx<9 && newy>0 && newy<9 &&!chess[newx][newy] )
					{
						chess[newx][newy] = true;
						hao.push((pos/100+1)*100+newx * 10 + newy);
					//	cout << newx << " " << newy << endl;
					}
				}
			}
		}
		if (reached)
		{
			return count;
		}

	}
	
}
int main()
{
	int T;
	cin >> T;
	while(true)
	{
		while (!hao.empty())
		{
			hao.pop();
		}
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				chess[i][j] = false;
			}
		}
		if (T <= 0)
			break;
		T--;
		char a, c;
		int b, d;
		cin >> a;
		cin >> b;
		cin >> c;
		cin>> d;
		cout << "To get from " << a << b << " to " << c << d << " takes " << find(a - 'a'+1, b, c - 'a'+1, d) << " knight moves." << endl;
	}
	return 0;
}