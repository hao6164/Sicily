#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> hao[104];
int deep[104];
int wide[104];
bool mark[104];
bool in[104];
bool forest;
struct point
{
	int id;
	int level;
	point(int id, int level)
	{
		this->id = id;
		this->level = level;
	}
};
queue<point> haoqueue;

int main()
{
	int n, m;
	while (cin>>n)
	{
		fill(mark, mark + 104, false);
		fill(deep, deep + 104, 0);
		fill(wide, wide + 104, 0);
		fill(in, in + 104, false);
		forest = true;
		while (!haoqueue.empty())
		{
			haoqueue.pop();
		}
		for (int i = 0; i <104 ; i++)
		{
			hao[i].clear();
		}
		if (n==0)
		{
			break;
		}
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin>>a>>b;
			hao[a].push_back(b);
			in[b] = true;
		}
		forest = false;
		for (int i = 1; i <= n; i++)
		{
			if (!in[i])
			{
				forest = true;
				haoqueue.push(point(i, 0));
				wide[0]++;
				mark[i] = true;
			}
		}
		if (!forest)
		{
			cout << "INVALID" << endl;
			forest = true;
			continue;
		}
		while (!haoqueue.empty())
		{
			point temp = haoqueue.front();
			haoqueue.pop();
			for (int i = 0; i < hao[temp.id].size(); i++)
			{
				int newid = hao[temp.id][i];
				if (mark[newid])
				{
					forest = false;
					break;
				}
				mark[newid] = true;
				haoqueue.push(point(newid, temp.level + 1));
				wide[temp.level + 1]++;
			}
			if (!forest)
			{
				break;
			}
		}
		for (int i = 1; i <= n;i++)
		{
			if (!mark[i])
			{
			   
				forest = false;
				break;
			}
		}
		if (!forest)
		{
			cout << "INVALID" << endl;
			forest = true;
			continue;
		}
		
		int maxwide = 0;
		int maxdeep = 0;
		for (int i = 0; i < 104; i++)
		{
			if (wide[i] == 0)
				break;
			if (wide[i]>=maxwide)
			{
				maxwide = wide[i];
			}
			maxdeep++;
		}
		cout << maxdeep - 1 <<" "<< maxwide << endl;
	}
	return 0;
}