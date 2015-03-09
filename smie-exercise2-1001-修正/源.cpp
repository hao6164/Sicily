#include<queue>
#include<math.h>
#include<iostream>
#include<algorithm>
#include <vector>
#include<iomanip>
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
	/*while (scanf("%d%d", &n, &k) != EOF){
		int* x = new int[n];
		int* y = new int[n];
		for (int i = 0; i<n; i++){
			scanf("%d%d", &(x[i]), &(y[i]));
		}*/
	while (cin >> n >> k)
	{



		
		int* x = new int[n];
		int* y = new int[n];
		for (int i = 0; i < n; i++)
		{
		cin >> x[i] >> y[i];
		}
		cout << setiosflags(ios::fixed) << setprecision(2) << output(n, k, x, y) << endl;
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
	//vector<node> node_vector;
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = i + 1; j < n; j++)
	//	{
	//		node temp;
	//		temp.distance = (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]);
	//		temp.point1 = i;
	//		temp.point2 = j;
	//		node_vector.push_back(temp);
	//	}
	//}
	//sort(node_vector.begin(), node_vector.end(), cmp);



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
int find_forbears(int* point_group, int self)
{
	if (self != point_group[self])
		point_group[self] = find_forbears(point_group,point_group[self]);
	return point_group[self];
	/*if (point_group[self] == self)
	{
		return self;
	}
	return find_forbears(point_group, point_group[self]);*/
}
bool cmp(node a, node b)
{
	return a.distance < b.distance; //结构体中，x小的优先级高
}