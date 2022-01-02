#ifndef BASIC_H
#define BASIC_H
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
void bubbleSort(int Arr[], int n)
{
	for (int times = 1; times < n - 1; times++)
		for (int index = 0; index < n - times; index++)
			if (Arr[index]>Arr[index + 1])
				swap(Arr[index], Arr[index+1]);
}
void insertionSort(int Arr[], int n)
{
	for (int pos = 1; pos < n; pos++)
	{
		int nowValue = Arr[pos];
		int index = pos - 1;
		while ( (index >= 0) && (Arr[index] > nowValue) )
		{
			Arr[index + 1] = Arr[index];
			index--;
		}
		Arr[index+1] = nowValue;
	}
}
int binSearch(int Arr[], int n, int x)
{
	int startPoint = 0, endPoint = n - 1, midPoint;
	while (startPoint <= endPoint)
	{
		midPoint = (startPoint + endPoint) / 2;
		if (Arr[midPoint] == x)
			return midPoint;
		else{
			if (Arr[midPoint] > x)
				endPoint = midPoint - 1;
			else if (Arr[midPoint] < x)
				startPoint = midPoint + 1;
		}
	}
	return -1;
}
void outputArr(int Arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << Arr[i] << " ";
	cout << endl;
}
#endif