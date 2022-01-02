

#include "stdafx.h";
#include<iostream>
#include<string>
using namespace std;

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

int _tmain(int argc, _TCHAR* argv[])
{
	/*string strs[] = { "ab", "ab", "abcd" };
	string queriString[]{ "ab", "abc", "a" };
	string strs[100], queriString[100];
	int nstrs= 5,nque=3;
	for (int i = 0; i < nstrs; i++)
	{
		cout << "String " << i << " is: ";
		getline(cin,strs[i]);
		cin.ignore();
	}
	for (int j = 0; j < nque; j++)
	{
		cout << "queriString" << j << "is:";
		getline(cin,queriString[j]);
		cin.ignore();
	}
	for (int i = 0; i < nque; i++)
	{
		int fre = 0;
		for (int j = 0; j < nstrs; j++)
			if (queriString[i] == strs[j])
				fre++;
		cout << fre <<" ";
	}
	cout << "\n";
	return 0; */



	string strs[100], queriString[100];
	int nstrs,nque;
	inputArrayString(nstrs, strs);
	inputArrayString(nque,queriString);

	for (int i = 0; i < nque; i++)
	{
		int fre = 0;
		for (int j = 0; j < nstrs; j++)
			if (queriString[i] == strs[j])
				fre++;
		cout << fre << " ";
	}
	cout << "\n";
	return 0;


}

