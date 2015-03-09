//2015年1月16日 10:36:22
//finish 2015年1月16日 11:13:52
#include<iostream>
#include<vector>
using namespace std;
struct MyStruct
{
	int a;
};
vector<int> haov[10004];
int se[10004][2];
int time_mark[104][2];
int times;
bool visted[104];
void dfs_mark_time(int start)
{
	visted[start] = true;
	time_mark[start][0] = times ;
	times++;
	for (int i = 0; i < haov[start].size(); i++)
	{
		
		if (!visted[haov[start][i]])
		{
//cout << haov[start][i]<<endl;
dfs_mark_time(haov[start][i]);
		}
		
		
	}
	time_mark[start][1] = times;
	times++;
}
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		for (int i = 0; i < 10004; i++)
		{
			haov[i].clear();
		}
		fill(visted, visted + 104, false);
		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			haov[u].push_back(v);
		}
		int k;
		cin >> k;
		for (int i = 0; i < k; i++)
		{
			cin >> se[i][0] >> se[i][1];
		}
		times = 0;
		dfs_mark_time(1);
		for (int i = 0; i < k; i++)
		{
			if (time_mark[se[i][0]][0] + 1 == time_mark[se[i][1]][0]) printf("edge (%d,%d) is Tree Edge\n", se[i][0], se[i][1]);
			else if (time_mark[se[i][0]][0]<time_mark[se[i][1]][0] && time_mark[se[i][0]][1]>time_mark[se[i][1]][1]) printf("edge (%d,%d) is Down Edge\n", se[i][0], se[i][1]);
			else if (time_mark[se[i][0]][0]>time_mark[se[i][1]][0] && time_mark[se[i][0]][1] < time_mark[se[i][1]][1]) printf("edge (%d,%d) is Back Edge\n", se[i][0], se[i][1]);
			else printf("edge (%d,%d) is Cross Edge\n", se[i][0], se[i][1]);
		}
	}
	return 0;
}