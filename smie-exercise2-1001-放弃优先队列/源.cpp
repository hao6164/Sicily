#include<math.h>
#include<iostream>
#include <vector>
#include<algorithm>
#include <stdio.h>
#include<iomanip>
using namespace std;
struct node
{
	int point1;
	int point2;
	double distance;
	node(int a, int b, double c)
	{
		point1 = a; point2 = b; distance = c;
	}
};
bool cmp(node a, node b);
bool cmpp(double a, double b){
	return a>b;
}
double output(int n, int k, int* x, int* y);
int find_forbears(int self);
int point_group[1000];
vector<double> ans;
vector<node> node_vector;
int main()
{
	int n, k;
	/*while (scanf("%d%d", &n, &k) != EOF){
		int i;
		for (i = 0; i<n; i++){
			bing[i] = i;
		}
		v.clear();
		ans.clear();
		double x[n];
		double y[n];
		for (i = 0; i<n; i++){
			scanf("%lf%lf", &x[i], &y[i]);
		}*/
	while (scanf("%d%d", &n, &k) != EOF){
		int* x = new int[n];
		int* y = new int[n];
		for (int i = 0; i<n; i++){
			scanf("%d%d", &(x[i]), &(y[i]));
		}
		//for (int i = 0; i < n; i++)
		//{
		//cin >> x[i] >> y[i];
		//}
		/*
		n = 100; k = 2;
		int* x = new int[n];
		int* y = new int[n];
		for (int i = 0; i < n; i++)
		{
			x[i] = n-i;
			y[i] = n+100-i;
		}*/
		//printf("%.2lf\n", output(n, k, x, y));
		cout << setiosflags(ios::fixed) << setprecision(2) << output(n, k, x, y) << endl;
		delete x, y;
	}
	return 0;
}
double output(int n, int k, int* x, int* y)
{
	
	//point_group = new int[n];

	for (int i = 0; i < n; i++)
	{
		point_group[i] = i;
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			double xx = x[i] - x[j];
			double yy = y[i] - y[j];
			node temp(i, j, xx*xx + yy*yy);
			node_vector.push_back(temp);
		}
	}
	sort(node_vector.begin(), node_vector.end(), cmp);

	/*int count = 0;
	int iterator = 0;
	while (true)
	{

		node temp;
		temp = node_vector[iterator];
		iterator++;
		int forbears_point1 = find_forbears(point_group, temp.point1);
		int forbears_point2 = find_forbears(point_group, temp.point2);
		if (forbears_point1 != forbears_point2)
		{
			point_group[forbears_point2] = forbears_point1;
			count++;
			if (count >= n - k + 1)
			{
				node_vector.clear();
				delete point_group;
				return sqrt(temp.distance);

			}
		}
	}
		*/
	
	int size = node_vector.size();
	int cnt = 0;
	for (int i = 0; i<size; i++){
		int xx = find_forbears(node_vector[i].point1);
		int yy = find_forbears(node_vector[i].point2);
		if (xx == yy)
			continue;
		point_group[xx] = yy;
		ans.push_back(node_vector[i].distance);
		cnt++;
		if (cnt == n - 1)
			break;
	}
	sort(ans.begin(), ans.end(), cmpp);
	
	double res = ans[k - 2];
       ans.clear();
	   node_vector.clear();
	   return sqrt(res);;


	
	return 0;//应该不会出现到这里

}
int find_forbears(int self)
{
	/*if (self != point_group[self])
		point_group[self] = find_forbears(point_group[self]);
	return point_group[self];*/
	if (point_group[self] == self)
	{
		return self;
	}
	return find_forbears(point_group[self]);
}
bool cmp(node a, node b)
{
	return a.distance < b.distance; //结构体中，x小的优先级高
}