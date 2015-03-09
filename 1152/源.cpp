#include<iostream>
#include<stack>
#include <vector>
using namespace std;
void horse_run(int x,int y,bool* done,int step_count);

const int colunms=6;
const int rows = 5;
bool reached[colunms*rows+1];
struct MyStruct
{
	int x;
	int y;
	int directions;
};
std::vector<MyStruct> Container;

stack<int> step_queue;
int main()
{
	int startnum = 0;
	cin >> startnum;
	while (startnum!=-1)
	{
		bool done = false;
		for (size_t i = 0; i < colunms*rows + 1; i++)
		{
			reached[i] = false;
		}
		
		horse_run((startnum-1) / colunms, (startnum- 1)%colunms ,&done,0);
		if (done)
		{

			int output[colunms*rows + 1];
			for (int i = 0; i < colunms*rows ; i++)
			{
				output[i] = step_queue.top();
				step_queue.pop();
			}
			
			for (int i = 0; i < colunms*rows ; i++)
		{
				cout << output[colunms*rows - 1 - i] << " ";
		} 
		cout<<endl;
		}
		else
		{
			cout << "no answer" << endl;
		}
		
		cin >> startnum;
	}
	return 0;

}
void horse_run(int x, int y,bool* done,int step_count)
{
	if (step_count == 0)
	{
		step_queue.push(x*colunms+y+1);
		reached[x*colunms + y + 1] = true;
	}
	if (*done)
	{
		return;
	}
	
	for (int i = 0; i <4; i++)
	{
		if (x - (i / 2 * 2 - 1) * 2>-1 && x - (i / 2 * 2 - 1) * 2 < rows&&y - (i % 2 * 2 - 1) * 1 > -1 && y - (i % 2 * 2 - 1) * 1 < colunms)
		{
			int num = (x - (i / 2 * 2 - 1) * 2)*colunms + (y - (i % 2 * 2 - 1) * 1) + 1;
			if (reached[num] == false)
			{

				step_queue.push(num);
				reached[num] = true;
				if (step_count == colunms*rows-2)
				{
					*done = true;
					return;
				}
				horse_run(x - (i / 2 * 2 - 1) * 2, y - (i % 2 * 2 - 1) * 1, done, step_count+1);
			}

		}
		if (x - (i / 2 * 2 - 1) * 1>-1 && x - (i / 2 * 2 - 1) * 1 < rows&&y - (i % 2 * 2 - 1) * 2> -1 && y - (i % 2 * 2 - 1) * 2 < colunms)
		{
		
			int num = (x - (i / 2 * 2 - 1) * 1)*colunms + (y - (i % 2 * 2 - 1) * 2) + 1;
			if (reached[num] == false)
			{

				step_queue.push(num);
				reached[num] = true;
				if (step_count == colunms*rows - 2)
				{
					*done = true;
					return;
				}
				horse_run(x - (i / 2 * 2 - 1) * 1, y - (i % 2 * 2 - 1) * 2, done, step_count+1);
			}
		}
		
	}
	
	if (*done==false)
	{
	   reached[x*colunms + y + 1] = false;
       step_queue.pop();
	}
	
	return;
	
	
}