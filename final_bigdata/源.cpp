//2015Äê1ÔÂ15ÈÕ 16:43:24
#include<iostream>
#include<string>
#include<sstream>
#include<memory>
#include<algorithm>
#define BASE 1000
#define DIG 1100
using namespace std;
class BigNumber
{
private:
	int data[DIG];
	int len;
public:
	BigNumber(){};
	BigNumber & Str_BNum(char*);
	BigNumber & Add(const BigNumber &);
	BigNumber & Mul(const BigNumber &);
	string Str();
};
BigNumber & BigNumber::Str_BNum(char* sb)
{
	int t = 0, d = 1, b = 0, slen = strlen(sb), i;
	len = 1; memset(data, 0, sizeof(data));
	data[0] = 1;
	if (sb[00] == '-') data[0] = -1, b = 1;
	for (i=slen-1; i >=b; i--)
	{
		while (t>=BASE||d>BASE)
		{
			data[len++] = t%BASE;
			t /= BASE;
			d = 10;
		}
		t += (sb[i] - '0')*d;
		d *= 10;
	}
	while (t > 0){
		data[len++] = t%BASE;
		t /= BASE;
	}
	return *this;
}
BigNumber  & BigNumber::Mul(const BigNumber & b)
{
	BigNumber bt;
	int j, i, up;
	int temp, temp1;
	bt.data[0] = data[0] * b.data[0];
	for (i = 0; i < len; i++)
	{
		up = 0;
		for (j = 1; j < b.len; j++)
		{
			temp = data[i] * b.data[j] + bt.data[i + j -1] + up;
			if (temp >= BASE)
			{
				temp1 = temp%BASE;
				up = temp / BASE;
				bt.data[i + j -1] = temp1;
			}
			else
			{
				up = 0;
				bt.data[i + j - 1] = temp;
			}
			
		}
		if (up != 0) bt.data[i + j - 1] = up;
	}
	bt.len = i + j;
	while (bt.data[bt.len - 1] == 0) bt.len--;
	*this = bt;
	return *this;
}
string BigNumber::Str()
{
	int i, base_len = 0;
	ostringstream sout;
	if (len == 1) {
		sout << '0';
		//sout << endl;
		return sout.str();
	}
	if (data[0] < 0)     sout << "-";
	sout << data[len - 1];
	i = BASE;
	while (i > 1) {
		base_len++;
		i /= 10;
	}
	for (i = len - 2; i>0; i--) {
		sout.width(base_len);
		sout.fill('0');
		sout << data[i];
	}
	//sout << endl;
	return sout.str();

}

int main()
{
	string a = "2576", b = "979";
	char achar[1000] = "2576", bchar[1000] = "979";
	BigNumber out, anum, bnum;
	anum = anum.Str_BNum(achar);
	bnum = bnum.Str_BNum(bchar);
	out = anum.Mul(bnum);
	string outstr = out.Str();
	return 0;
}