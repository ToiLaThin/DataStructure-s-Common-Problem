#ifndef AB_H
#define AB_H
#include<string>
#include<iostream>
using namespace std;
void delString(string S[], int &lenS, int pos)
{
	for (int i = pos; i < lenS - 1; i++)
	{
		S[i] = S[i + 1];
	}
	lenS--;
}
void inputArrayString(int &nS, string S[])
{
	cin >> nS;
	cin.ignore();
	for (int i = 0; i < nS; i++)
		getline(cin, S[i]);
}
void outputArrayString(int nS, string S[])
{
	for (int i = 0; i < nS; i++)
		cout << S[i] << endl;
}
#endif