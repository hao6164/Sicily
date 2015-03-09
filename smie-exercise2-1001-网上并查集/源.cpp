#include<queue>
#include<math.h>
#include<windows.h>
#include<iostream>
#include <vector>
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
bool cmp(node a, node b);
struct bing
{
	int top;
	int last;
};
double output(int n, int k, int* x, int* y);
int find_forbears(int* point_group, int self);
int main()
{
	int n, k;

	while (true)
	{

	
	
	/*cin >> n >> k;
	int* x = new int[n];
	int* y = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
	}*/
	n = 100; k=2;
	int* x = new int[n];
	int* y = new int[n];
	for (int i = 0; i < n; i++)
	{
		x[i] = i;
		y[i] = i;
	}/**/
	cout << round(output(n, k, x, y) * 100) / 100 << endl;
    }
	return 0;
}
double output(int n, int k, int* x, int* y)
{
	int* point_group = new int[n];
	
	for (int i = 0; i < n; i++)
	{
		point_group[i] = i;
	}
	priority_queue<node>pr_queue;
	vector<node> node_vector;
	DWORD dwStart22 = GetTickCount();
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			node temp;
			temp.distance = (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]);
			temp.point1 = i;
			temp.point2 = j;
			node_vector.push_back(temp);
		}
	}
	sort(node_vector.begin(),node_vector.end(), cmp);
	DWORD dwEnd22 = GetTickCount();
	cout << dwEnd22 - dwStart22<< endl;
	DWORD dwStart = GetTickCount();
	//这里运行你的程序代码

	
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
	DWORD dwEnd = GetTickCount();
	cout << dwEnd - dwStart<<endl;
	
	int count = 0;
	while (true)
	{

		node temp;
		temp = pr_queue.top();
		int forbears_point1 = find_forbears(point_group, temp.point1);
		int forbears_point2 = find_forbears(point_group, temp.point2);
		if (forbears_point1 != forbears_point2)
		{
			point_group[forbears_point2] = forbears_point1;
			count++;
			if (count >= n - k + 1)
			{DWORD dwEnd2 = GetTickCount();
				cout << dwEnd2 - dwStart << endl;
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
int find_forbears(int* point_group, int self)
{
	if (point_group[self]==self)
	{
		return self;
	}
	return find_forbears(point_group, point_group[self]);
}
bool cmp(node a, node b)
{
	return a.distance < b.distance; //结构体中，x小的优先级高
}