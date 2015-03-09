#include<iostream>
using namespace std;
long myabs(long a)
{
	if (a >= 0)
		return a;
	else
		return -a;
};
struct dataset
{
	int left;
	int right;
	long Ascore;
	long Bscore;
	dataset()
	{
		left = 0;
		right = 0;
		Ascore = 0;
		Bscore = 0;
	};
	void set(int i, int j, long k, long l)
	{
		left = i;
		right = j;
		Ascore = k;
		Bscore = l;
	};
};
void choosefrom(int* databuf, int left, int right, int Ascore, int Bscore);
long maxdifference = 0;

long sumdata = 0;
bool check(long ep, dataset* setsbuf,int left,int right);
int main()
{
	int n, k = 0;


	while (1)
	{
		k++;
		n = 12;/*cin >> n;*/
		if (n == 0)
		{

			break;
		}
		sumdata = 0;
		int* databuf = new int[n];
		for (size_t i = 0; i < n; i++)
		{
			databuf[i] =0;/*cin >> databuf[i];*/
			//sumdata += databuf[i];
		}
		dataset* setsbuf = new dataset[n*n/4];
		setsbuf[0].set(0, n-1, 0, 0);
		long fp=0;
		long ep = 1;
		while (1)
		{
			if (setsbuf[fp].right == 0)//队列里面没有了就跳出循环
			{
				break;
			}
			if (setsbuf[fp].right - setsbuf[fp].left<=1)
			{
				if (maxdifference<setsbuf[fp].Ascore - setsbuf[fp].Bscore + myabs(databuf[setsbuf[fp].right] - databuf[setsbuf[fp].left]))
				maxdifference=setsbuf[fp].Ascore - setsbuf[fp].Bscore + myabs(databuf[setsbuf[fp].right] - databuf[setsbuf[fp].left]);
			}
			else
			{
			
				if (databuf[setsbuf[fp].right]>databuf[setsbuf[fp].left+1])
				{	
					if (!check(ep, setsbuf, setsbuf[fp].left + 1, setsbuf[fp].right - 1))
					{

				
		     		setsbuf[ep].set(setsbuf[fp].left + 1, setsbuf[fp].right - 1, setsbuf[fp].Ascore + databuf[setsbuf[fp].left], setsbuf[fp].Bscore + databuf[setsbuf[fp].right]);
		    		ep++;
					}
				}
				else
				{
					if (!check(ep, setsbuf, setsbuf[fp].left + 2, setsbuf[fp].right ))
					{
						setsbuf[ep].set(setsbuf[fp].left + 2, setsbuf[fp].right, setsbuf[fp].Ascore + databuf[setsbuf[fp].left], setsbuf[fp].Bscore + databuf[setsbuf[fp].left + 1]);
						ep++;
					}
				}
				if (databuf[setsbuf[fp].right-1]>databuf[setsbuf[fp].left])
				{
					if (!check(ep, setsbuf, setsbuf[fp].left , setsbuf[fp].right - 2))
					{
						setsbuf[ep].set(setsbuf[fp].left, setsbuf[fp].right - 2, setsbuf[fp].Ascore + databuf[setsbuf[fp].right], setsbuf[fp].Bscore + databuf[setsbuf[fp].right - 1]);
						ep++;
					}
				}
				else
				{
					if (!check(ep, setsbuf, setsbuf[fp].left + 1, setsbuf[fp].right - 1))
					{
						setsbuf[ep].set(setsbuf[fp].left+ 1, setsbuf[fp].right - 1, setsbuf[fp].Ascore + databuf[setsbuf[fp].right], setsbuf[fp].Bscore + databuf[setsbuf[fp].left]);
						ep++;
					}
				}
			}
			fp++;
		}
		
		
		
		
		
		
		
		
		
		
		delete databuf;

		cout << "In game " << k << ", the greedy strategy might lose by as many as " << maxdifference << " points." << endl;

		maxdifference = 0;

	}
	return 0;
}
bool check(long ep, dataset* setsbuf, int left, int right)
{
	/*for (long i = 0; i < ep; i++)
	{
		if ((setsbuf[i].left == left)&&(setsbuf[i].right ==right ))
		{
			return true;
		}
	}*/
	return false;
}