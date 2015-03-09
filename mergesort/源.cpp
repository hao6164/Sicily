//2015Äê1ÔÂ16ÈÕ 23:37:37
#include<iostream>
using namespace std;
int p[100001];
int temp[100001];
unsigned int count12 = 0;
void merge_sort(int start, int end)
{
	//cout << start << endl << end << endl;
	if (start==end)
	{
		return;
	}
	merge_sort(start, (start + end) / 2);
	merge_sort((start + end) / 2+1,end);
	
	int pointer = 0, p_left = start, p_right=(start + end) / 2 + 1;

	for (int i = 0; i < end-start+1; i++)
	{
		if (p_left>(start + end) / 2)
		{
			temp[i] = p[p_right];
			p_right++;
			continue;
		}
		if (p_right>end)
		{
			temp[i] = p[p_left];
			p_left++;
			continue;
		}
		if (p[p_left]<=p[p_right])
		{
			temp[i] = p[p_left];
			p_left++;
			continue;
		}
		else
		{
			temp[i] = p[p_right];
			count12 += p_right - start - i;
			p_right++;
			
			continue;
		}
	}
	int po = start;
	for (int i = 0; i < end - start + 1; i++)
	{
		p[po] = temp[i];
			po++;
	}
}
int main()
{
	int n;
	while (cin>>n)
	{
		count12 = 0;
		fill(p, p + 100001, 0);
		fill(temp, temp + 100001, 0);
		if (n==0)
		{
			cout << 0 << endl;
			continue;
		}
		for (int i = 0; i < n; i++)
		{
			 p[i]=100000-i;
		}
		merge_sort(0, n-1);
	/*	for (int i = 0; i < n; i++)
		{
			cout<< p[i]<<endl;
		}*/
		cout << count12 << endl;
		
	}
	
	return 0;
}