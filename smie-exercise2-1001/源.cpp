#include<iostream>
#include<queue>
#include<math.h>
using namespace std;
struct node
{
	int point1;
	int point2;
	double distance;
	friend bool operator< (node a, node b)
	{
		return a.distance > b.distance; //结构体中，x小的优先级高
	}
};
double output(int n, int k, int* x, int* y);
int main()
{
	int n, k;

	while (cin >> n >> k)
	{
	
	int* x = new int[n];
	int* y = new int[n];
    for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
	}
	
	cout << round(output(n, k, x, y)*100)/100 << endl;
	}
	return 0;
}
double output(int n, int k, int* x, int* y)
{
	int* point_group=new int[n];
	for (int i = 0; i < n; i++)
	{
		point_group[i] = i;
	}
	priority_queue<node>pr_queue;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			node temp;
			temp.distance = (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]);
			temp.point1 = i;
			temp.point2 = j;
			pr_queue.push(temp);
		}
	}
	int count=0;
		while (true)
		{
			
			node temp;
			temp=pr_queue.top();
			if (point_group[temp.point1]!=point_group[temp.point2])
			{
				for (int i = 0; i <n; i++)
				{
					if (point_group[temp.point2]==point_group[i])
					{
						point_group[i] = point_group[temp.point1];
					}
				}			
				count++;
				if (count>=n-k+1)
				{
					return sqrt(temp.distance);
				}
			}
			if (pr_queue.empty())
			{
				return 0;
			}
			pr_queue.pop();

		}
		return 0;//应该不会出现到这里
}