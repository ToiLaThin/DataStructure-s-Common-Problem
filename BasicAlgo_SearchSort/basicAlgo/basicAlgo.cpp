// basicAlgo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Basic.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int nA;
	int A[100];
	inputArr(A, nA);
	//bubbleSort(A, nA);
	//insertionSort(A, nA);
	outputArr(A, nA);

	int x;
	cout << "Please  input the value you 'd like to find: ";
	cin >> x;
	cout << "Here 's the index of the value which you 'd like to find: " << binSearch(A, nA, x) << endl;
	
	return 0;
}

