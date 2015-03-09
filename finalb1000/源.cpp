#include<iostream>
#include<queue>
#include<math.h>
using namespace std;
bool mark[400000];
int  fac[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 }; //i的阶乘为fac[i]
/*  康托展开.
{1...n}的全排列由小到大有序，s[]为第几个数  */
int KT(int n, int s[])
{
	int i, j, t, sum;
	sum = 0;
	for (i = 0; i<n; i++)
	{
		t = 0;
		for (j = i + 1; j<n; j++)
		if (s[j] < s[i])
			t++;
		sum += t*fac[n - i - 1];
	}
	return sum + 1;
}
int markpos(int newnow){
	int s[9];
	for (int i = 0; i <9; i++)
	{
		s[i] = newnow % 10;
		newnow=newnow / 10;
	}
	return KT(9, s);
}
//int fac[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };//...
long cantor(int s[], int n){
	int i, j, temp, num;
	num = 0;
	for (i = 1; i<n; i++){//n为位数
		temp = 0;
		for (int j = i + 1; j <= n; j++){
			if (s[j]<s[i]) temp++;
		}
		num += fac[n - i] * temp;
	}
	return (num + 1);
}
int src=0;
int swap(int now,int posa, int posb)
{
	int temp = now;
	int num = 0;
	for (int i = 1; i < posa; i++)
	{
		 temp= temp / 10;
	}
	num = temp % 10;
	now = now + (9 - num)*pow(10, posa - 1) + (num - 9)*pow(10, posb - 1);
	return now;
}
int find9(int temp)
{
	for (int i = 1; i < 10; i++)
	{
		if(temp % 10 == 9)
			return i;
		temp = temp / 10;
	}
}
int bfs()
{	
	queue<int> haoint;
    queue<int> haoblock;
	int now = 123456789;
	int block = 0;
	int newnow = 0;
	if (src==now)
	{
		return 0;
	}
	mark[markpos(now)] = true;
	haoint.push(now);
	haoblock.push(0);
	while (!haoint.empty())
	{
		now = haoint.front();
		block = haoblock.front();
		haoint.pop();
		haoblock.pop();
		//cout << "out" << " " << now<<"  "<<block << endl;
		for (int j = 1; j <5 ; j++)
		{
			if (j == block%10)
				continue;
			int where9=find9(now);
			if (j==1)
			{
				if (where9 + 3 <= 9)
				{
				
					newnow = swap(now,where9 + 3, where9);
					if (newnow==src)
					{
						return block/10+1;
					}
					else
					{
						if (!mark[markpos(newnow)])
						{

							mark[markpos(newnow)] = true;
						haoint.push(newnow);
						haoblock.push(block/10*10+10+2);
						//cout << newnow << " " << block % 10 + 1 + 20 << endl;
						}
					}
				}
			}
			else if (j == 2)
			{
				if (where9 - 3 >=1)
				{

					newnow = swap(now, where9 - 3, where9);
					if (newnow == src)
					{
						return block / 10 + 1;
					}
					else
					{
						if (!mark[markpos(newnow)])
						{
							mark[markpos(newnow)] = true;
							haoint.push(newnow);
							haoblock.push(block / 10 * 10 + 10 + 1);
							//cout << newnow << " " << block % 10 + 1 + 10 << endl;
						}
					}
				}
			}
			else if (j == 3)
			{
				if (where9 %3!=0)
				{

					newnow = swap(now, where9 +1, where9);
					if (newnow == src)
					{
						return block / 10 + 1;
					}
					else
					{
						if (!mark[markpos(newnow)])
						{
							mark[markpos(newnow)] = true;
							haoint.push(newnow);
							haoblock.push(block / 10 * 10 + 10 + 4);
							//cout << newnow << " " << block % 10 + 1 + 40 << endl;
						}
					}
				}
			}
			else
			{
				if (where9 % 3 != 1)
				{

					newnow = swap(now, where9 - 1, where9);
					if (newnow == src)
					{
						return block / 10 + 1;
					}
					else
					{
						if (!mark[markpos(newnow)])
						{
							mark[markpos(newnow)] = true;
							haoint.push(newnow);
							haoblock.push(block / 10 * 10 + 10 + 3);
						//	cout << newnow << " " << block % 10 + 1 + 30 << endl;
						}
					}
				}
			}
		}

	}
	return -1;
}

int main()
{
	//int s[9] = { 1,2, 3, 4,5,6,7,8,9 };
	//cout << KT(9, s);
	int n;
	cin >> n;
	while (true)
	{
		if (n<=0)
		{
			break;
		}
		n--;
		int temp=0;
		fill(mark, mark + 400000, false);
		src = 0;
		for (int i = 0; i < 9; i++)
		{
			
			cin >> temp;
			if (temp==0)
			{
				temp = 9;
			}
			src = src * 10 + temp;

		}
		cout << bfs()<<endl;
	}
	return 0;
}