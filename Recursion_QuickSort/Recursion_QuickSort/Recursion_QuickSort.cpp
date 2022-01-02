// Recursion_QuickSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

void inputArr(int Arr[], int &n)
{
	cout << "Please input the number of elements first: ";
	cin >> n;
	//cin.ignore(); bo thi nhap mang van dung
	cout << "Now input the elements: ";
	for (int i = 0; i < n; i++)
		cin >> Arr[i];
	//CIN doc du lieu tu SAU ' '	
}
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void outputArr(int Arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << Arr[i] << " ";
	cout << endl;
}
int partion(int A[], int l, int r)
{
	//O(n)
	int Pivot = A[r];
	//pole luon la chi so 1 phan tu > Pivot de swap khi A[index] la phan tu nho hon
	//index luon phai la chi so phan tu < Pivot nen bo qua phan tu lon hon
	int pole = l - 1, index = pole + 1;
	while (index < r)
	{		
		if (A[index] < Pivot){
			pole++;
			swap(A[pole], A[index]);
		};		
		index++;
	}
	swap(A[pole+1], A[r]);
	outputArr(A, r + 1);
	return pole + 1;
	//(pole+1) is the pivotIndex
}
void quickSort(int A[], int l, int r)
{	//cay nhi phan
	if (l == r)
		return;
	else if (l < r)
	{
		int piIndex = partion(A, l, r);
		quickSort(A, l, piIndex-1);
		quickSort(A, piIndex + 1, r);
	}
}
void quickSortMidPar(int A[], int l, int r)
{
	int i = l, j = r, x = A[(l + r) / 2];
	while(i<=j)
	{
		while (A[i] < x) i++;
		while (A[j] > x) j--;
		if (i <= j){
			swap(A[i], A[j]);
			i++; j--;
		}
	}
	if (i < r)
		quickSortMidPar(A, i, r);
	if (j > l)
		quickSortMidPar(A, l, j);
}
int _tmain(int argc, _TCHAR* argv[])
{
	int A[100]; int n;
	inputArr(A, n);
	quickSort(A, 0, n - 1);
	outputArr(A, n);
	return 0;
}

