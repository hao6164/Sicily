#include<iostream>
#include<set>
#include<vector>

using namespace std;
set<int> hao;
set<int>::iterator ihao;
set<int>::difference_type dis;
vector<int> hao2;
vector<int>::iterator ihao2;
vector<int>::difference_type dis2;
int cs[4] = { 1, 2, 4, 6 };
int input[100002];
int main()
{
	int n;
	while (cin>>n)
	{
		for (int i = 0; i <n; i++)
		{
			cin >> input[i];
		}
		int count=0;
		for (int i = n-1; i >=0; i--)
		{
			int tesp=find(cs, cs + 4, 6)-cs;
			hao2.push_back(2);
			find(hao.begin(), hao.end(), 2)-hao.begin();
			ihao=hao.insert(hao.begin(),input[i]);
			dis=ihao - hao.begin();
			hao.insert(input[i]);
			hao.find(input[i]);

		}
	}
	return 0;
}