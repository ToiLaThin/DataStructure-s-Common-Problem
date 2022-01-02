// MergeSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

void inputArr(int A[], int &n)
{
	cout << "Nhap so phan tu mang: ";
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> A[i];
}

void outputArr(int A[], int n)
{
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << endl;
}

void merge(int A[], int fIdx,int mIdx,int lIdx)
{
	int i = fIdx; int j = mIdx + 1; int k = fIdx;
	int tempA[10];

	while (k <= lIdx)
	{
		//bo phan con lai cua mang vao
		if (i == mIdx + 1)
		{
			for (int temp = j; temp <= lIdx; temp++)
			{
				tempA[k] = A[temp];
				k++;
			}
			break;
		}
		else if (j == lIdx + 1)
		{
			for (int temp = i; temp <= mIdx; temp++)
			{
				tempA[k] = A[temp];
				k++;
			}
			break;
		}

		if (A[i] < A[j])
		{
			tempA[k] = A[i];
			i++;
		}
		else if (A[j] <= A[i])
		{
			tempA[k] = A[j];
			j++;
		}
		k++;
	}

	//sau khi tempA la mang tang dang tu fIdx toi lIdx
	//gan lai cho A de tiep tuc mergeSort
	for (int t = fIdx; t <= lIdx; t++)
		A[t] = tempA[t];
}

void mergeSort(int A[],int f,int l)
{
	if (f == l)
		return;


	int mid = (f + l) / 2;
	mergeSort(A, f, mid);
	mergeSort(A, mid + 1, l);

	merge(A, f, mid, l);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int A[10]; int nA;
	inputArr(A, nA);
	mergeSort(A, 0, nA - 1);
	outputArr(A, nA);
}

