#include<iostream>
//#include<string>
using namespace std;
int main()
{
	
	while (1)
	{
		int colunms=0;
		int rows = 0;
		char letters[202];
		char** datamatrix;
		int pointer = 0;
		cin >> colunms;
		if (!colunms)
			break;
		cin >> letters;
		rows=strlen(letters)/colunms;
		datamatrix = new char*[rows];
		for (int j = 0; j < rows; j++)
		{
			datamatrix[j] = new char[colunms];
		}
		for (int i = 0; i < rows; i++)
		{
			for (int k = 0; k < colunms; k++)
			{
				if (i%2==0)
				{
					datamatrix[i][k] = letters[pointer];
					pointer++;
				}
				else
				{
					datamatrix[i][colunms-k-1] = letters[pointer];
					pointer++;
				}
			}
		}
		for (int l = 0; l < colunms; l++)
		{
			for (int m = 0; m < rows; m++)
			{
				cout << datamatrix[m][l];
			}
			
		}
		cout << endl;
		delete datamatrix;
	//	letters[0] = '\0';
	}
	return 0;
}