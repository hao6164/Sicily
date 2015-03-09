#include <iostream>       
#include<stdio.h>
#include<math.h>
#include<algorithm>
//#include<iomanip>

using namespace std;




#define N 20
#define INF 100000000.0



double dp[1 << 20][20];
int n;
double ans, _min;


struct point{
	double x, y;
}point[N];
double dis[N][N];

double distant(int i, int j)
{
	return sqrt((point[i].x - point[j].x)*(point[i].x - point[j].x) + (point[i].y - point[j].y)*(point[i].y - point[j].y));
}

int main()
{
	int cases;
	int m;
	int i, j;
	cin >> cases;

	while (cases--)
	{
		cin >> m;

		for (i = 0; i<m; i++)
		{
			cin >> point[i].x;
			cin >> point[i].y;
		}


		for (i = 0; i<m; i++)
		for (j = i + 1; j< m; j++){
			dis[i][j] = distant(i, j);
			dis[j][i] = dis[i][j];
		}

		if (m == 1)  {
			ans = 0;
			printf("%.2f\n", ans);
			//cout<<fixed<<setprecision(2)<<ans<<endl;

			continue;
		}
		if (m == 2)  {
			ans = dis[0][1];
			printf("%.2f\n", ans);
			//cout<<fixed<<setprecision(2)<<ans<<endl;
			continue;
		}

		n = m - 2;
		for (int S = 0; S <= (1 << n) - 1; ++S)//枚举所有状态，用位运算表示
		for (int i = 1; i <= n; ++i)
		{

			if (S & (1 << (i - 1)))//状态S中已经过城市i
			{

				if (S == (1 << (i - 1))) dp[S][i] = dis[0][i];
				else//如果S有经过多个城市
				{
					dp[S][i] = INF;
					for (int j = 1; j <= n; ++j)
					{
						if (S & (1 << (j - 1)) && j != i)//枚举不是城市I的其他城市
							dp[S][i] = min(dp[S ^ (1 << (i - 1))][j] + dis[j][i], dp[S][i]);

					}
				}
			}
		}
		ans = dp[(1 << n) - 1][1] + dis[1][n + 1];
		for (int i = 2; i <= n; ++i)
		if (dp[(1 << n) - 1][i] + dis[i][n + 1] < ans)
			ans = dp[(1 << n) - 1][i] + dis[i][n + 1];
		printf("%.2f\n", ans);
		//cout<<fixed<<setprecision(2)<<ans<<endl;
		//system("pause");
		//  cout<<ans<<endl;



	}
	return 0;
}