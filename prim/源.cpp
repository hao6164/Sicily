//2015Äê1ÔÂ15ÈÕ 18:58:19
#include<iostream>
#include<map>
#include<string>
#define inf 44444444
using namespace std;
bool comfirm[510];
int dis_to_src[510];
int map_dis[510][510];
int last_point[210];
int mapsize = 0;
void dijkstra(int init_point)
{
	comfirm[init_point] = true;
	dis_to_src[init_point] = 0;
	for (int i = 0; i < mapsize; i++)
	{
		dis_to_src[i] = dis_to_src[i] < map_dis[init_point][i] ? dis_to_src[i] : map_dis[init_point][i];
		last_point[i] = init_point;
	}
	while (true)
	{
		int min = inf;
		int min_num = inf;
		
		for (int i = 0; i < mapsize; i++)
		{
			if (!comfirm[i])
			{
				if (min>dis_to_src[i])
				{
					min = dis_to_src[i];
					min_num = i;
				}
			}
		}
		if (min == inf)
		{
			break;
		}
		comfirm[min_num] = 1;
		for (int i = 0; i < mapsize; i++)
		{
			if (dis_to_src[i]>map_dis[min_num][i]&&!comfirm[i])
			{
				dis_to_src[i] = map_dis[min_num][i];
				last_point[i] = min_num;
			}
		}
	}
}
int main()
{
	int n;
	cin >> n;
	while (true)
	{
		if (n <= 0)
			break;
		n--;
		fill(dis_to_src, dis_to_src + 510, inf);
		fill(comfirm, comfirm + 510, false);
		fill(last_point, last_point + 510, inf);
		for (int i = 0; i < 510; i++)
		{
			for (int j = 0; j < 510; j++)
			{
				map_dis[j][i] = inf;
			}
		}
		cin >> mapsize;
		for (int i = 0; i < mapsize; i++)
		{
			for (int j = 0; j < mapsize; j++)
			{
				cin >> map_dis[i][j];
			}
		}
		dijkstra(0);
		int max = 0;
		for (int i = 0; i < mapsize; i++)
		{
			max = max>dis_to_src[i] ? max : dis_to_src[i];
		}
		cout << max << endl;
	}
	return 0;
}