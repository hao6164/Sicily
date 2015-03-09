#include<iostream>
#include<algorithm>

using namespace std;

int approximation(int* raw_datas,int target_num);
long calculate(long last_result, int new_num, int operator_choice);
const int approximation_distance = 10000000;
int main()
{
	int runs_num;
	cin >> runs_num;
	for (int i=0; i < runs_num; i++)
	{
		int raw_datas[5];
		int target_num;
		cin >> raw_datas[0] >> raw_datas[1] >> raw_datas[2] >> raw_datas[3] >> raw_datas[4];
		cin >> target_num;
		cout << approximation(raw_datas,target_num) << endl;
	}
	system("pause");
	return 0;
}
int approximation(int* raw_datas, int target_num)
{
	long approximation_num;
	long approximation_num_distance = approximation_distance -target_num;
	sort(raw_datas, raw_datas + 5);
	do
	{
		for (int i = 0; i < 6; i++)
		{
			long temp1 =raw_datas[0] ; 
			temp1 = calculate(temp1,raw_datas[1],i);
			if (temp1==-65500)
			{
				continue;
			}
			for (int j = 0; j < 6; j++)
			{
				long temp2 = calculate(temp1, raw_datas[2], j);
				if (temp2 == -65500)
				{
					continue;
				}
				for (int k = 0; k < 6; k++)
				{
					long temp3 = calculate(temp2, raw_datas[3], k);
					if (temp3 == -65500)
					{
						continue;
					}
					for (int l = 0; l < 6; l++)
					{
						long temp4 = calculate(temp3, raw_datas[4], l);
						if (temp4 == -65500)
						{
							continue;
						}

						long approximation_temp_distance= abs(temp4 - target_num);
						if (approximation_num_distance>approximation_temp_distance)
						{
							 approximation_num_distance=approximation_temp_distance ;
							 approximation_num = temp4;
						}
					}
				}
			}
		}
		
	} while (next_permutation(raw_datas, raw_datas + 5));
	return approximation_num;
}
long calculate(long last_result,int new_num,int operator_choice)
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
			  if (last_result%new_num==0)
			  {
				  return last_result / new_num;
			  }
			  else
			  {
				  return -65500;
			  }
			  
			  break;
	}
	case 4:
	{
			  return  new_num-last_result ;
			  break;
	}
	case 5:
	{
			  if (last_result==0)
			  {
				  return -65500;
			  }
			  else
			  {
			 
				  if (new_num%last_result == 0)
				  {
					  return   new_num/last_result;
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