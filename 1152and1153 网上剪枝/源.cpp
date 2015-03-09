#include<iostream>
#include<stack>
#include <vector>
#include<algorithm>
using namespace std;
void horse_run(int x, int y, bool* done, int step_count);
int find_dir(int xtemp, int ytemp, bool* reached);
const int colunms = 8;
const int rows = 8;
bool reached[colunms*rows + 1];
struct MyStruct
{
	int x;
	int y;
	int directions;
	MyStruct(int a, int b, int c)
	{
		x = a;
		y = b;
		directions = c;
	};
};
bool Comp(MyStruct a, MyStruct b);


stack<int> step_queue;
int main()
{
	int startnum = 0;
	cin >> startnum;
	while (startnum != -1)
	{
		bool done = false;
		for (size_t i = 0; i < colunms*rows + 1; i++)
		{
			reached[i] = false;
		}

		horse_run((startnum - 1) / colunms, (startnum - 1) % colunms, &done, 0);
		if (done)
		{

			int output[colunms*rows + 1];
			for (int i = 0; i < colunms*rows; i++)
			{
				output[i] = step_queue.top();
				step_queue.pop();
			}
			for (int i = 0; i < colunms*rows; i++)
			{
				cout << output[colunms*rows - 1 - i] << " ";
			}
			cout << endl;
		}
		else
		{
			cout << "no answer" << endl;
		}

		cin >> startnum;
	}
	return 0;

}
void horse_run(int x, int y, bool* done, int step_count)
{
	std::vector<MyStruct> Container;
	if (step_count == 0)
	{
		step_queue.push(x*colunms + y + 1);
		reached[x*colunms + y + 1] = true;
	}
	if (*done)
	{
		return;
	}
	for (int j = 0; j < 2; j++)
	{


		for (int i = 0; i <4; i++)
		{
			if (x - (i / 2 * 2 - 1) * (2 - j)>-1 && x - (i / 2 * 2 - 1) * (2 - j) < rows&&y - (i % 2 * 2 - 1) * (1 + j) > -1 && y - (i % 2 * 2 - 1) *(1 + j) < colunms)
			{
				int num = (x - (i / 2 * 2 - 1) * (2 - j))*colunms + (y - (i % 2 * 2 - 1) *(1 + j)) + 1;
				int xtemp = x - (i / 2 * 2 - 1) * (2 - j);
				int ytemp = y - (i % 2 * 2 - 1) * (1 + j);
				if (reached[num] == false)
				{
					MyStruct cell = MyStruct(xtemp, ytemp, find_dir(xtemp, ytemp, reached));
					Container.push_back(cell);

					if (step_count == colunms*rows - 2)
					{
						step_queue.push(num);
						reached[num] = true;
						*done = true;
						return;
					}
				}

			}
		}


	}
	if (!Container.empty())
	{
		sort(Container.begin(), Container.end(), Comp);
		for (size_t i = 0; i < Container.size(); i++)
		{
			step_queue.push(Container[i].x*colunms + Container[i].y + 1);
			reached[Container[i].x*colunms + Container[i].y + 1] = true;
			if (*done)
			{
				return;
			}
			horse_run(Container[i].x, Container[i].y, done, step_count + 1);
			if (*done)
			{
				return;
			}
		}

	}

	Container.clear();

	if (*done == false)
	{
		reached[x*colunms + y + 1] = false;
		step_queue.pop();
	}

	return;


}
bool Comp(MyStruct a, MyStruct b)
{

	return a.directions < b.directions;

}
int find_dir(int xtemp, int ytemp, bool* reached)
{
	int directions = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++)
		{


			if (xtemp - (i / 2 * 2 - 1) * (2 - j)>-1 && xtemp - (i / 2 * 2 - 1) * (2 - j) < rows&&ytemp - (i % 2 * 2 - 1) * (1 + j) > -1 && ytemp - (i % 2 * 2 - 1) * (1 + j) < colunms)
			{
				int num = (xtemp - (i / 2 * 2 - 1) * (2 - j))*colunms + (ytemp - (i % 2 * 2 - 1) * (1 + j)) + 1;
				if (reached[num] == false)
				{
					directions++;

				}

			}
		}

	}
	return directions;
}