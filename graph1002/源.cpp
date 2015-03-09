#include<iostream>
#include<vector>
using namespace std;
int a[1010];
vector<int> hao[1010];
int father(int i)
{
	if (a[i] == i)
		return i;
	else
	{
	
	return a[i]=father(a[i]);
	}
}
int main()
{
	int n, m;
	while (cin>>n>>m)
	{
		for (int j = 0; j < 1010; j++)
		{
			a[j] = j;
		}
		int v, y;
		for (int i = 1; i <=m; i++)
		{
			cin >> v >> y;
			a[father(y)] = father(v);
			//cout << y<<a[y]<<endl;
		}
		int count = 0;
		for (int k = 1; k <=n; k++)
		{
			if (k == a[k])
			{
				count++;
			}

		}
		cout << count<<endl;
	}
	return 0;
}