// Demo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

int UCLN(int a, int b)
{
	if (a == 0 || b == 0)
		exit(0);
	if (a == b)
		return a;
	else
	{
		if (a > b)
			return UCLN(a - b, b);
		else
			return UCLN(a, b - a);
	}
}
int BCNN(int a, int b,int val)
{
	if (a == 0 || b == 0)
		exit(0);
	val++;
	if ((a * val) % b == 0)
		return (a*val);
	else
		return BCNN(a,b,val);
}
int _tmain(int argc, _TCHAR* argv[])
{
	int a, b;
	cin >> a >> b;
	cout << "BCNN cua hai so " << a << " " << b << " la : " << BCNN(a, b, 0) << endl;
	cout << "UCLN cua hai so " << a << " " << b << " la : " << UCLN(a, b) << endl;	
	return 0;
}

