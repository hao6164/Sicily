#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> hao[10001];
int in[10001];
int level[10001];
bool visited[10001];
struct point{
	int id;
	int level;
	point(int a, int b){ id = a; level = b; }
};
queue<point> haoqueue;
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		fill(level, level + 10001, -1);
		//fill(visited, visited + 10001, false);
		fill(in, in + 10001, 0);
		//flag = true;
		for (int j = 0; j < 10001; j++)
		{
			hao[j].clear();
		}
		int a, b;
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b;
			hao[b].push_back(a);
			in[a]++;
		}
		for (int i = 1; i <=n; i++)
		{
			if (in[i]==0)
			{
				//visited[i] = true;
				level[i] = 0;
				haoqueue.push(point(i, 0));
			}
		}
		while (!haoqueue.empty())
		{
			point temp = haoqueue.front();
			haoqueue.pop();
			for (int i = 0; i < hao[temp.id].size(); i++)
			{
				int newid = hao[temp.id][i];
				level[newid]=level[newid] < temp.level + 1 ? temp.level + 1 : level[newid];
				in[newid]--;
				if (in[newid]==0)
				{
				//	visited[newid] = true;
					haoqueue.push(point(newid, temp.level + 1));
				}
			}
		}
		bool flag = true;
		int sum = 100 * n;
		for (int i = 1; i <=n; i++)
		{
			if (level[i] < 0)
			{
				flag = false; 
				break;
			}
			else
			{
				sum += level[i];
			}
				
		}
		if (flag)
		{
			cout << sum << endl;
		}
		else
		{
			cout << "Poor Xed" << endl;
		}
	}
	return 0;
}