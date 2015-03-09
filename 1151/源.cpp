/*
* yuan.cpp
*
*  Created on: 2014年9月14日
*      Author: hao
*/
#include<iostream>
#include<cstdlib>
#include<queue>
#include<string>
#include<stdio.h>
using namespace std;
int factorial_num[8] = {1,1,2,6,24,120,720,5040};

struct map_cell
{
	int x;
	int y;
	bool appear;
	int last_pointer_in_map;
	int pointer_in_map;
	char operator_type;
	map_cell(){ x = 0; y = 0; appear = false; last_pointer_in_map = -1; pointer_in_map = -1; operator_type = 'F'; };
	map_cell(int a, int b, bool c, int d, int e){ x = a; y = b; appear = false; last_pointer_in_map = -1; pointer_in_map = -1; operator_type = 'F'; };
	void set(int a, int b, bool c, int d, int e,char f){ x = a; y = b; appear = c; last_pointer_in_map = d; pointer_in_map = e; operator_type = f; };
};
int sign(int x);
void single_step(map_cell* tempdata, char operator_cmd,int);
bool check(map_cell tempdata, map_cell* route_map,int used_length);
string find_route(int step_max);
int Cantor_pos(map_cell tempdata);
int destiny_x, destiny_y;
int main()
{
	int step_max = 0;
	while (1)
	{
		destiny_x = 0;
		destiny_y = 0;
		cin >> step_max;
		if (step_max <= -1)       //输入为-1时结束
			break;
		for (int i = 0; i < 4; i++)
		{
			int temp;
			cin >> temp;
			destiny_x=temp + destiny_x * 10;
		}
		for (int i = 0; i < 4; i++)
		{
			int temp;
			cin >> temp;
			destiny_y = temp + destiny_y * 10;
		}
		cout << find_route(step_max)<<endl;

	}
	return 0;
}
void single_step(map_cell* tempdata, char operator_cmd)
{
	switch (operator_cmd)
	{
	case 'A':
	{
				int temp;
				temp = tempdata->x; 
				tempdata->x = tempdata->y; 
				tempdata->y = temp;
				break; 
	}
	case 'B':
	{
				tempdata->x = tempdata->x / 10 + tempdata->x % 10 * 1000;
				tempdata->y = tempdata->y / 10 + tempdata->y % 10 * 1000;
				break; 
	}
	case 'C':
	{
				int temp = tempdata->x;
				tempdata->x = tempdata->x % 10 + tempdata->x / 1000 * 1000 + tempdata->y % 1000 / 100 * 100 + tempdata->x % 1000 / 100 * 10;
				tempdata->y = tempdata->y % 10 + tempdata->y / 1000 * 1000 + temp % 100 / 10 * 10 + tempdata->y % 100 / 10 * 100;
				break;
	}
	default:
		break;
	}
	
}

string find_route(int step_max)
{

	map_cell route_map[40320];
	int used_length = 0;
	queue<map_cell> step_queue;//构造搜索的队列
	map_cell tempdata(1234,8765,true,-1,-1);
	map_cell tempdata2;
	if (destiny_x==1234&&destiny_y==8765)
	{
		return "0";
	}
	step_queue.push(tempdata);
	int temp3 = Cantor_pos(tempdata);
	route_map[temp3].set(tempdata.x, tempdata.y, true, tempdata.pointer_in_map, temp3, 'F');
	//used_length++;
	while (true)
	{
		tempdata2 = step_queue.front();
		if (step_queue.size()==0)
		{
			return "-1";
		}
		step_queue.pop();
		for (char i = 'A'; i < 'D'; i++)
		{
			tempdata = tempdata2;
          single_step(&tempdata, i);

		 /* if (!check(tempdata, route_map,used_length))
		  {
			  route_map[used_length].set(tempdata.x,tempdata.y,true,tempdata.pointer_in_map,used_length,i);
			  step_queue.push(route_map[used_length]);
			  used_length++;
		  }*/
		  int temp2 = Cantor_pos(tempdata);
		  if (!route_map[temp2].appear)
		  {
			  route_map[temp2].set(tempdata.x, tempdata.y, true, tempdata.pointer_in_map, temp2, i);
			  step_queue.push(route_map[temp2]);
		  }

		
		  if (tempdata.x == destiny_x&&tempdata.y == destiny_y)
		  {
			  string output="";
			  int abc_pointer=temp2;
			  int step_total = 0;
			  do
			  {
				  step_total++;
				  output=route_map[abc_pointer].operator_type + output;
				  abc_pointer = route_map[abc_pointer].last_pointer_in_map;
			  }
			  while (abc_pointer!=-1);
 
			  if (step_max <step_total)
				  return "-1";
			  char* temp = new char[5];
			  
			  sprintf(temp, "%d", step_total);
			  output = " " + output;
			 output=temp+ output ;
			 return  output;
		  }
		 
	     
		}

	}

}
int Cantor_pos(map_cell tempdata)
{
	int temp[8];
	int Cantor = 0;
	int Weight = 0;
	temp[0] = tempdata.x / 1000;
	temp[1] = tempdata.x % 1000 / 100;
	temp[2] = tempdata.x % 100 / 10;
	temp[3] = tempdata.x % 10;
	temp[4] = tempdata.y / 1000;
	temp[5] = tempdata.y % 1000 / 100;
	temp[6] = tempdata.y % 100 / 10;
	temp[7] = tempdata.y % 10;
	for (int i = 0; i < 8; i++)
	{ 
		Weight = temp[i] - 1;
		for (int j = 0; j < i; j++)
		{
			Weight = Weight - sign(temp[i] - temp[j]);
		}
		
		Cantor += Weight*factorial_num[7 - i];
	}
	return Cantor;
}
int sign(int x)
{
	if (x > 0)
		return 1;
	else
		return 0;
}
bool check(map_cell tempdata, map_cell* route_map,int used_length)
{
	for (int i = 0; i < used_length; i++)
	{
		if ((tempdata.x == route_map[i].x) && (tempdata.y == route_map[i].y))
		{
			return true;
			
		     
		}
	}
	return false;
}
