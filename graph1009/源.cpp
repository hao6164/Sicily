#include<iostream>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
vector<int> haoto[100001];
int haofrom[100001];
priority_queue<int, vector<int>, greater<int> >zero;


int main()
{
	int T;
	cin >> T;
	while (1)
	{
		fill(haofrom, haofrom + 100001, 0);
		if (T <= 0)
			break;
		T--;
		int n, m;
		cin >> n >> m;
		int i, j;
		for (int k = 0; k < m; k++)
		{
			
			cin >> i >> j;
			haoto[i].push_back(j);
			haofrom[j]++;
		
		}
		for (int k2 = 1; k2 <=n; k2++)
		{
			if (haofrom[k2] == 0)
			{
				zero.push(k2);
			}
		}
		int count=0;
		while (true)
		{
			/*if (count >= n)
				break;*/
			int h;
			if (zero.empty())
			{
				break;
			}
			h = zero.top();
			zero.pop();
			haofrom[h] = -1;
			cout << h << " ";
          /* for (h = 1; h <=n; h++)
		  {
			   if (haofrom[h] == 0)
			   {
				   haofrom[h] = -1;
				   cout << h << " ";
				   count++;
				   break;
			   }
				   
		  }*/
		   for (int l = 0; l < haoto[h].size(); l++)
		   {
			   haofrom[haoto[h][l]] = haofrom[haoto[h][l]] -1 ;
			   if (haofrom[haoto[h][l]]==0)
			   {
				   zero.push(haoto[h][l]);
			   }
			   
		   }
		   
		}
		cout << endl;
		for (int k3 = 1; k3 < n; k3++)
		{
			haoto[k3].clear();
		}
		//clear

	}
	return 0;
}