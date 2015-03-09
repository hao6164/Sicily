#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int array[17] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59 };
	long long Mersenne[17];
	for (int i =0; i <17 ; i++)
	{
		Mersenne[i] = pow(2,array[i]) - 1;
	}
	system("pause");
	return 0;
}