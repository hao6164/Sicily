#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main()
{
	int a[20];
	int b = 2;
	float c;
	char d;
	char e[20];
	scanf("%d%d%f %c%s",a,&b,&c,&d,e);
	printf("the input is %d %d %0.2f %c %s\n",a[0],b,c,d,e);
		system("pause");
	return 0;
}