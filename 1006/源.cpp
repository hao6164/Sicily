#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<stdio.h>
using namespace std;
string median_ranking(char* raw_data, int rows);
int calculate_distance(char* first_data,  int rows, char candidata_ranking[6]);
int distance_between_two(char* temp1, char* temp2);
const int max_distance_set = 10000;
int main()
{
	int  rows = 0;
	while (true)
	{
		cin >> rows;
		if (rows == 0)
			break;
		char* raw_data = new char[rows*5];
		for (int i = 0; i < rows*5; i++)
		{
			cin >> raw_data[i];
		}
		cout << median_ranking(raw_data, rows)<<endl;
	}
	
	
	return 0;
}
string median_ranking(char* raw_data, int rows)
{
	char candidate_rankings[6]="ABCDE";
	int min_distance = max_distance_set;//³õÊ¼»¯¾àÀë
	char min_rankings[6] = "ABCDE";

	do {
		/*cout << candidate_rankings << endl;*/

		int distance_temp = calculate_distance(raw_data,rows,candidate_rankings);
		if (distance_temp<min_distance)
		{
			min_distance = distance_temp;
			for (char i = 0; i < 5; i++)
			{
               min_rankings[i] = candidate_rankings[i];
			}
			
		}
		
	} while (next_permutation(candidate_rankings, candidate_rankings+5));

	string output = " is the median ranking with value ";

	char* temp = new char[5];
	sprintf(temp, "%d", min_distance);

	output = min_rankings + output+temp+".";

	return output;
}
int calculate_distance(char* first_data,int rows,char candidata_ranking[6])
{
	int distance=0;
	for (int i = 0; i < rows; i++)
	{
		distance += distance_between_two(first_data+5*i,candidata_ranking);
	}
	return distance;
}
int distance_between_two(char* temp1,char* temp2)
{
	char temp3[6],distance=0;
	for (int i = 0; i < 5; i++)
	{
		
		for (int j = 0; j < 5; j++)
		{
			if (*(temp1 + i) == *(temp2 + j))
			{
				break;
			}
			bool flag = false;
			for (int k = 0; k < i; k++)
			{
				
				if (*(temp2 + j) == temp3[k])
				{
					flag = true;
					break;
				}
			}
			if (!flag)
			{
				distance++;
			}
			
		}
		temp3[i] = temp1[i];
	}
	return distance;
}