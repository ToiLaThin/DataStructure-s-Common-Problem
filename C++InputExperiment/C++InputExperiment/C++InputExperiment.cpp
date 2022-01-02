// C++InputExperiment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{	
	int n;
	cin >> n;
	//cin.ignore(); bo thi nhap mang van dung
	int Arr[100];
	for (int i = 0; i < n; i++)
		cin >> Arr[i];//CIN doc du lieu tu SAU ' '


	for (int i = 0; i < n; i++)
		cout << Arr[i] << " ";
	cout << endl;
	/*string Str[100];
	for (int i = 0; i < n; i++)
		getline(cin, Str[i]);
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << Str[i] << endl;*/

	
	/*string s1, s2;
	cin >> s1;  cout << s1 << endl;
	cin >> s2;  cout << s2 << endl;*/

	/*string s1;
	getline(cin, s1); cout << s1 << endl;
	getline(cin, s1); cout << s1 << endl;*/

	return 0;
}

