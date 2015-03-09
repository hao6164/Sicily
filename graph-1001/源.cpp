#include<iostream>
#include<queue>
using namespace std;
int adjmatrix[100][100];
int sx, sy, tx, ty;
bool visited[100][100];
int n, m;
void bfs();
struct pos
{
	int x, y;
	pos(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};
int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		
		memset(visited, 0,sizeof(visited));
		memset(adjmatrix, 0, sizeof(adjmatrix));
	//	fill(adjmatrix, adjmatrix + 100 * 100, 0);//initial the matrix
		cin >> n >> m;
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				cin >> adjmatrix[j][k];
			}

		}
		cin >> sx >> sy >> tx >> ty;
		sx--;
		sy--;
		tx--;
		ty--;
		bfs();
	}
	//system("pause");
	return 0;
}
void bfs()
{
	queue<pos> haoqueue;
	haoqueue.push(pos(sx, sy));
	while (!haoqueue.empty())
	{
		pos temp = haoqueue.front();
		//cout << temp.x << temp.y << endl;
		haoqueue.pop();
		if (temp.x==tx&&temp.y==ty)
		{
			cout <<1<<endl;
			return;
		}
		if (temp.x-1>=0)
		{
			if (!visited[temp.x - 1][temp.y] && adjmatrix[temp.x - 1][temp.y]==1)
			{
				visited[temp.x - 1][temp.y] = true;
				haoqueue.push(pos(temp.x-1,temp.y));
			}
		}
		if (temp.x + 1 <m)
		{
			if (!visited[temp.x + 1][temp.y] && adjmatrix[temp.x + 1][temp.y]==1)
			{
				visited[temp.x + 1][temp.y] = true;
				haoqueue.push(pos(temp.x + 1, temp.y));
			}
		}
		if (temp.y - 1 >= 0)
		{
			if (!visited[temp.x][temp.y - 1] && adjmatrix[temp.x][temp.y - 1]==1)
			{
				visited[temp.x][temp.y-1] = true;
				haoqueue.push(pos(temp.x , temp.y-1));
			}
		}
		if (temp.y + 1 <n)
		{
			if (!visited[temp.x][temp.y + 1] && adjmatrix[temp.x][temp.y + 1]==1)
			{
				visited[temp.x ][temp.y+1] = true;
				haoqueue.push(pos(temp.x , temp.y+1));
			}
		}
	}
	cout << 0 << endl;
	return;
}