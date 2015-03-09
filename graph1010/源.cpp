#include<iostream>
#include<vector>
#include<queue>

using namespace std;
vector<int> hao[10001];
int in[10001];
bool visiting[10001];
int level[10001];
struct point{
	int id;
	int level;
	point(int a, int b){ id = a; level = b; }
}; queue<point> haoqueue;
//bool flag = true;
void dfs(int node,int farlevel)
{
	for (int i = 0; i <hao[node].size() ; i++)
	{
		int newnode = hao[node][i];
		in[newnode]--;
		level[newnode] = level[newnode] < farlevel + 1 ? farlevel + 1 : level[newnode];
		if (in[newnode]==0)
		{
			dfs(newnode, level[newnode]);
			//cout << newnode << " " << level[newnode] << endl;
		}
	}
}
int main()
{
	int n, m;
	while (cin>>n>>m)
	{
		fill(level, level + 10001, -1);
		fill(visiting, visiting + 10001, false);
		fill(in, in + 10001, 0);
		//flag = true;
		for (int j = 0; j <10001; j++)
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
		queue<int> temp;
		for (int i = 1; i <= n; i++)
		{
			if (in[i] == 0)
			{
				//visited[i] = true;
				temp.push(i);
				//haoqueue.push(point(i, 0));
			}
		}
		while (!temp.empty())
		{
			int i = temp.front();
			temp.pop();
        level[i] = 0;
		dfs(i, level[i]);
		}
		
		//while (!haoqueue.empty())
		//{
		//	point temp = haoqueue.front();
		//	haoqueue.pop();
		//	for (int i = 0; i < hao[temp.id].size(); i++)
		//	{
		//		int newid = hao[temp.id][i];
		//		level[newid] = level[newid] < temp.level + 1 ? temp.level + 1 : level[newid];
		//		in[newid]--;
		//		if (in[newid] == 0)
		//		{
		//			//	visited[newid] = true;
		//			haoqueue.push(point(newid, temp.level + 1));
		//		}
		//	}
		//}
		bool flag = true;
		int sum = 100 * n;
		for (int i = 1; i <= n; i++)
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