// Bai_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;


void inputArray(int Arr[], int &n)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> Arr[i];
}
void outputArray(int Arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << Arr[i]<<" ";
	cout << endl;
}
void dichTrai(int Arr[], int n, int d)
{
	for (int time = 1; time <= d; time++)
	{
		int x = Arr[0];
		for (int i = 0; i < n - 1; i++)
			Arr[i] = Arr[i + 1];
		Arr[n - 1] = x;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int nA;
	int A[100];
	inputArray(A, nA);
	
	int d;
	cout << "Nhap d lan dich trai ban muon: "; cin >> d;
	dichTrai(A, nA, d);

	outputArray(A, nA);
	return 0;
}

