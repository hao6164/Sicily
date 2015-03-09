#include<iostream>
#include<algorithm>

using namespace std;

int calculate(int last_result, int new_num, int operator_choice);
void approximation_dfs(int* p, int num, int* app_result, int target_num);
int main()
{
	int runs_num;
	cin >> runs_num;
	for (int i = 0; i < runs_num; i++)
	{
		int raw_datas[5];
		int target_num;
		cin >> raw_datas[0] >> raw_datas[1] >> raw_datas[2] >> raw_datas[3] >> raw_datas[4];
		cin >> target_num;
		int app_out=-60000;
		if (raw_datas[0] == target_num || raw_datas[1] == target_num || raw_datas[2] == target_num || raw_datas[3] == target_num || raw_datas[4] == target_num)
		{
			app_out = target_num;
		}
		else
		{
		
		approximation_dfs(raw_datas, 5, &app_out,target_num );
		}
		cout << app_out << endl;
	}
	return 0;
}

int calculate(int last_result, int new_num, int operator_choice)
{


	switch (operator_choice)
	{
	case 0:
	{
			  return last_result + new_num;
			  break;
	}
	case 1:
	{
			  return last_result - new_num;
			  break;
	}
	case 2:
	{
			  return last_result * new_num;
			  break;
	}
	case 3:
	{
			  if (new_num!=0)
			  {

			 
			  if (last_result%new_num == 0)
			  {
				  return last_result / new_num;
			  }
			  else
			  {
				  return -65500;
			  }
			  }
			  else
			  {
				  return -65500;
			  }

			  break;
	}
	case 4:
	{
			  return  new_num - last_result;
			  break;
	}
	case 5:
	{
			  if (last_result == 0)
			  {
				  return -65500;
			  }
			  else
			  {

				  if (new_num%last_result == 0)
				  {
					  return   new_num / last_result;
				  }
				  else
				  {
					  return -65500;
				  }
			  }
			  break;
	}
	default:
	{
			   return -65500;
			   break;
	}
	}
}


void approximation_dfs(int* p,int num,int* app_result ,int target_num)
{
	
		
		if ((target_num - *app_result)>(target_num - *p) && (target_num - *p) >= 0)
		{
			*app_result = *p;
		}
		
	
	if (num==1)
	{
		if ((target_num - *app_result)>(target_num - *p) && (target_num - *p)>=0)
		{
			*app_result = *p;
		}
		
		return;
	}
	for (size_t i = 0; i < num - 1; i++)
	{
		for (size_t j = i+1; j < num ; j++)
		{
			for (size_t k = 0; k < 6; k++)
			{
				int* p1 = new int[num-1];
				p1[0] = calculate(*(p + i), *(p + j), k);
				if (p1[0] == -65500)
				{
					delete[]p1;
					continue;

				}
				if (p1[0]==target_num)
				{
					*app_result = p1[0];
					delete[]p1;
					return;
				}
				int m = 1;
				for (size_t l = 0;l < num; l++)
				{
					if (l!= i && l != j)
					{
						p1[m] = *(p +l);
						m++;
					}

				}
			
				approximation_dfs(p1, num - 1, app_result, target_num);

				delete []p1;
			}

		}
	}
}