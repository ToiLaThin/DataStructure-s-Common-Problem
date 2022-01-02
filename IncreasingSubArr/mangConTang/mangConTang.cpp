// mangConTang.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"basic.h"
#define MIN_VALUE -1000000000

void outputArr(int Arr[], int start, int end)
{
	for (int i = start; i <= end; i++)
		cout << Arr[i] << " ";
	cout << endl;
}
void listSubArray(int Arr[], int n)
{
	//O(n^2) ko la O(n^3)
	cout << "Here 's the list of subArray: " << endl;
	for (int start = 0; start < n; start++)
		for (int end = start; end < n; end++)
			outputArr(Arr, start, end);
}

void listIncreasingSubArray(int Arr[], int n)
{
	cout << "Here 's the list of increasing subArray: " << endl;
	int idx = 0, start = 0;
	while (idx < n){
		if (Arr[idx + 1]>Arr[idx])
			idx++;
		else
		{
			if (idx != start)
				outputArr(Arr, start, idx);
			start = idx + 1;
			idx++;
			//NOTICE THE SEQUENCE OF INCREMENT OF start and idx;
		}

	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int nA; int A[100];
	inputArr(A, nA); A[nA] = MIN_VALUE;
	//listSubArray(A, nA);
	listIncreasingSubArray(A, nA);
	return 0;
	
}

