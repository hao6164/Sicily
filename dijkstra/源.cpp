#include<iostream>
#include<map>
#include<string>
#define inf 44444444
using namespace std;
map<string, int> str_num;
map<int, string> num_str;
bool comfirm[610];
int dis_to_src[610];
int map_dis[610][610];
int last_point[610];
int mapsize = 0;
void dijkstra(int init_point)
{
	comfirm[init_point] = true;//原始点为确认点 距离为0
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
		if (min == inf)//没有最小的边了 就是结束了
		{
			break;
		}
		comfirm[min_num] = 1;
		for (int i = 0; i < mapsize; i++)
		{
			if (dis_to_src[i]> map_dis[min_num][i] && !comfirm[i])
			{
				dis_to_src[i] =  map_dis[min_num][i];//更新到src'距离
				last_point[i] = min_num;//记录是谁更新的 用于回溯
			}
			//if (dis_to_src[i]>(dis_to_src[min_num] + map_dis[min_num][i]))
			//{
			//	dis_to_src[i] = dis_to_src[min_num] + map_dis[min_num][i];//更新到src'距离
			//	last_point[i] = min_num;//记录是谁更新的 用于回溯
			//}
		}
	}
}
int main()
{
	int T;
	cin >> T;
	while (true)
	{
		if (T <= 0)
		{
			break;
		}
		T--;

		fill(comfirm, comfirm + 610, false);
		fill(dis_to_src, dis_to_src + 610, inf);
		fill(last_point, last_point + 610, inf);
		for (int i = 0; i < 610; i++)
		{
			for (int j = 0; j < 610; j++)
			{
				map_dis[i][j] = inf;
			}
		}
		int N;
		cin >> N;
		mapsize = N;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> map_dis[i][j];
			}
			
		}


		dijkstra(0);
		int max = 0;
		for (int i = 0; i < N; i++)
		{
			max = max<dis_to_src[i] ? dis_to_src[i]:max;

		}
		cout << max << endl << endl;
	}
	return 0;
}