#include<iostream>
#include<stack>
using namespace std;
long long Fibonacci_mod(int n);
struct MyStruct
{
	long long x11;
	long long x12;
	long long x21;
	long long x22;
	MyStruct(long long a, long long b, long long c, long long d)
	{
		x11 = a; x12 = b; x21 = c; x22 = d;
	};
};
MyStruct Matrix_calculate(MyStruct a,MyStruct b);
int main()
{
	long long n;
	
	while (cin>>n)
	{
		cout<<Fibonacci_mod(n)<<endl;
		
		
	}
	return 0;
}
long long Fibonacci_mod(int n)
{
	if (n==0)
	{
		return 0;
	}
	if (n==1||n==2)
	{
		return 1;
	}
	if (n == 3)
	{
		return 2;
	}
	n = n - 1;
stack<MyStruct> matrix_left;
	    MyStruct init_matrix = MyStruct(1, 1, 1, 0);
        while (true)
		{
			if (n%2==1)
			{
				matrix_left.push(init_matrix);

			}
			n = n / 2;
			init_matrix=Matrix_calculate(init_matrix, init_matrix);
			if (n == 1)
				break;
			
		}
		while (!matrix_left.empty())
		{
			init_matrix = Matrix_calculate(init_matrix, matrix_left.top());
			matrix_left.pop();
		}
		return init_matrix.x11;
}
MyStruct Matrix_calculate(MyStruct a, MyStruct b)
{
	MyStruct result = MyStruct(0,0,0,0);
	result.x11 = a.x11*b.x11 + a.x12*b.x21;
	result.x12 = a.x11*b.x12 + a.x12*b.x22;
	result.x21 = a.x21*b.x11 + a.x22*b.x21;
	result.x22 = a.x21*b.x12 + a.x22*b.x22;
	if (result.x11>=1000000007)
	{
		result.x11 = result.x11 % 1000000007;
	}
	if (result.x12 >= 1000000007)
	{
		result.x12 = result.x12 % 1000000007;
	}
	if (result.x21 >= 1000000007)
	{
		result.x21 = result.x21 % 1000000007;
	}
	if (result.x22 >= 1000000007)
	{
		result.x22 = result.x22 % 1000000007;
	}
	return result;
}