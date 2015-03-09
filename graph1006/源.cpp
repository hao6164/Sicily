#include<iostream>
#include<vector>

using namespace std;
vector<int> adj[101];
bool visited[101];
bool visiting[101];
bool dag = true;
void dfs(int i)
{
	if (!dag)
	{
		return;
	}
	visiting[i] = true;
	visited[i] = true;
	for (int j = 0; j < adj[i].size(); j++)
	{
		if (visiting[adj[i][j]])
		{
			dag = false;
			return;
		}
		else
		{
			dfs(adj[i][j]);
		}
		
	}
	visiting[i] = false;
	return;
}
int main()
{
	int n, m;
	while (cin>>n>>m)
	{
		fill(visited, visited + 101, 0);
		fill(visiting, visiting + 101, 0);
		for (int i = 0; i < 101; i++)
		{
			adj[i].clear();
		}
		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		for (int i = 1; i <=n; i++)
		{
			if (!visited[i]&&dag)
			{
				visited[i] = true;
				dfs(i);
			}
		}
		if (dag)
		{
			cout << 1<<endl;
		}
		else
		{
			cout << 0<<endl;
			dag = true;
		}
		
	}
	return 0;
}