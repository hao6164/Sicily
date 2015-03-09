//2015年1月15日 19:50:30
#include<iostream>
#include<algorithm>
using namespace std;
int map_dis[510][510];
int mapsize;
//边的集合 可以看作是set
struct MyStruct
{
	int u, v,w;
	friend bool operator< (MyStruct a, MyStruct b)
	{
		return a.x < b.x; //结构体中，x小的优先级高
	}
};
MyStruct E[1000000];
bool cmp(MyStruct a, MyStruct b)
{
		return a.w< b.w;
}
int getfarther(int* father,int x)
{
	return x == father[x] ? x : father[x] = getfarther(father, father[x]);
}
void kruskal(int E_size)
{
	int* father=new int[mapsize+1];
	for (int i = 0; i < mapsize+1; i++)
	{
		father[i] = i;
	}
	sort(E, E + E_size);
	int max_e = 0;
	for (int i = 0; i < E_size; i++)
	{
		if (getfarther(father, E[i].u) != getfarther(father, E[i].v))
		{
			max_e = E[i].w;
			father[getfarther(father, E[i].u)] = father[getfarther(father, E[i].v)];
         }
	}
	cout << max_e << endl;
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
		cin >> mapsize;
		for (int i = 0; i < mapsize; i++)
		{
			for (int j = 0; j < mapsize; j++)
			{
				cin>>map_dis[i][j];
			}
		}
		
		int E_size=0;
		for (int i = 0; i <mapsize; i++)
		{
			for (int j = i+1; j < mapsize; j++)
			{
				E[E_size].u = i;
				E[E_size].v = j;
				E[E_size].w = map_dis[i][j];
				E_size++;
			}
		}
		kruskal(E_size);
		if (n!=0)
		{
			cout << endl;
		}
	}
	return 0;
}