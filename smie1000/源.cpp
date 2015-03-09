#include<iostream>
using namespace std;
int main()
{
int n=0;
	while (true)
	{


		long long Out_n = 1;
		
		n++;
		if (n==101)
		{
			break;
		}
		//cin >> n;

		if (n == 1 || n == 2)
		{
			Out_n = 1;
		}
		else if (n == 0)
		{
			Out_n = 0;
		}
		else
		{
			long long Out_n_old = 1;
			long long temp = 0;
			for (int i = 2; i < n; i++)
			{
				temp = Out_n;
				Out_n = (Out_n + Out_n_old);
				Out_n_old = temp;
				if (Out_n >= 1000000007)
				Out_n = Out_n % 1000000007;
			}
			
		}
		cout << Out_n % 1000000007 << endl;
	}
	system("pause");
	return 0;
}