#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> note[1001];
char note_color[1001];
queue<int> haoqueue;

int main()
{
	int m, n;
	int v, u;
	while (cin >> n >> m)
	{
		for (int i = 1; i < 1001; i++)
		{
			note[i].clear();
		}
		fill(note_color, note_color + sizeof(note_color), 0);
		for (int i = 1; i <= m; i++)
		{
			cin >> u >> v;
			note[u].push_back(v);
			note[v].push_back(u);
		}
		haoqueue.push(1);
		note_color[1] = 1;
		while (1)
		{
			bool flag = false;
			if (haoqueue.empty())
			{
				cout << "Yes" << endl;
				break;
			}
			int farnote;
			farnote=haoqueue.front();
			haoqueue.pop();
			for (int j = 0; j <note[farnote].size(); j++)
			{
				int childnote = note[farnote][j];
				if (!note_color[childnote])
				{
					haoqueue.push(childnote);
					if (note_color[farnote] == 1)
					{
						note_color[childnote] = 2;
					}
					else
					{
						note_color[childnote] = 1;
					}
				}
				else
				{
					if (note_color[childnote] == note_color[farnote])
					{
						cout << "No" << endl;
						flag = true;
						break;
					}
						

				}
			}
			if (flag)
			{
				flag = false;
				break;
			}
		}
	}
	return 0;
}