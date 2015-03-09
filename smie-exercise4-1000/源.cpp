#include<iostream>
using namespace std;
int city[2][20];
int city_have_gone[20];
float distanceij[20][20];
float go_over=100000000;
void find_path(int n,int col,int last_city,int city_num,float path_dis);
bool check(int, int);
int main()
{
	int T;
	cin >> T;
	for(int i = 0; i < T;i++)
	{
		int n;
		cin >> n;
		for (int i = 0; i <n; i++)
		{
			cin >> city[0][i] >> city[1][i];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = i+1; j < n; j++)
			{
				distanceij[i][j] = sqrt((city[0][i] - city[0][j])*(city[0][i] - city[0][j]) + (city[1][i] - city[1][j])*(city[1][i] - city[1][j]));
				distanceij[j][i] = distanceij[i][j];
			}
		}
		find_path(n, 0, 0, 0, 0);
		printf("%.2lf\n", go_over);
		/*cout << go_over << endl;*/
			go_over = 100000000;
		
	}
	return 0;
}
void find_path(int n, int col, int last_city,int city_num ,float path_dis)
{
	if (city_num==n-2)
	{
		float temp_dis = path_dis + distanceij[last_city][n - 1];
		if (temp_dis<go_over)
		{
			go_over = temp_dis;
			return;
		}
	}
	for (int i = 1; i < n-1; i++)
	{
		if (check(i, city_num))
		{
			continue;
		}
		else
		{
			
			float temp_dis = path_dis + distanceij[last_city][i];
			if (temp_dis>=go_over)
			{
				continue;
			}
			city_have_gone[city_num] = i;
			find_path(n, 0, i, city_num + 1, temp_dis);
		}
	}
}
bool check(int i, int city_num)
{
	for (int j=0; j < city_num; j++)
	{
		if (city_have_gone[j] == i)
			return true;
	}
	return false;
}