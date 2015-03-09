#include<iostream>
#include<queue>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
bool bfs(int s, vector<int>* g, int n);
int main()
{
	int n, m;
	int u, v;

	while (cin >> n)
	{


		if (n == 0)
			break;
		vector<int>* g;
		g = new vector<int>[n];
		cin >> m;
		for (int i = 0; i<m; i++)
		{
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if (bfs(n - 1, g, n))
			cout << "I can post the letter" << endl;
		else
			cout << "I can't post the letter" << endl;

	}
	return 0;
}
bool bfs(int s, vector<int>* g, int n)
{
	int* color;
	color = new int[n];
	fill(color, color + n, 0);
	//memset(color, 0, sizeof(color));
	queue<int> haoqueue;
	haoqueue.push(0);
	while (!haoqueue.empty())
	{
		int u = haoqueue.front();
		haoqueue.pop();
		for (int i = 0; i<g[u].size(); i++)
		{
			cout << g[u][i];
			if (g[u][i] == n - 1)
				return true;
			cout << color[g[u][i]];
			if (color[g[u][i]] == 0)
			{
				color[g[u][i]] = 1;
				haoqueue.push(g[u][i]);
			}
		}

	}
	return false;

}