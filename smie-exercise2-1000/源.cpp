#include<iostream>
#include <queue>
using namespace std;
int BT(int* frequece,int n);
struct node
{
	int* store_data;
	int x;
	friend bool operator< (node a, node b)
	{
		return a.x < b.x; //结构体中，x小的优先级高
	}
};
int main()
{
	int n;
	cin >> n;
	char character;
	int* frequence = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin>>character>>frequence[i];

	}
	cout<<BT(frequence,n)<<endl;
	system("pause");
	return 0;
}
int BT(int* frequece,int n)
{
	node* huffman_node = new node[n];
	
	int** temp2D = new int*[n];
		for (int i = 0; i < n; i++)
		{
			temp2D[i] = new int[n];
			for (int j = 0; j <n; j++)
			{
				temp2D[i][j] = 0;
			}
		}
	priority_queue<node>pr_queue; 
	for (int  i = 0; i < n; i++)
	{
		temp2D[i][i] = 1;
		huffman_node[i].x = frequece[i];
		huffman_node[i].store_data = temp2D[i];
		pr_queue.push(huffman_node[i]);
	}
	for (int i = 0; i < n-1; i++)
	{
		node temp_node1;
		node temp_node2;
		temp_node1 = pr_queue.top();
		pr_queue.pop();
		temp_node2 = pr_queue.top();
		pr_queue.pop();
		temp_node1.x = temp_node1.x + temp_node2.x;
		for (int i = 0; i < n; i++)
		{
			temp_node1.store_data[i] = temp_node1.store_data[i] + temp_node2.store_data[i];
			if (temp_node1.store_data[i]!=0)
			{
				temp_node1.store_data[i]++;
			}
		}
		pr_queue.push(temp_node1);
	}
	node final_node;
	final_node = pr_queue.top();
	
	int output = 0;
	for (int i = 0; i < n; i++)
	{
		output += frequece[i] * (final_node.store_data[i]-1);
	}
	return output;
}