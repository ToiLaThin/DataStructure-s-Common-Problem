// qSortWithoutRecursion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
#define MAX 100

struct AStack
{
	int Arr[MAX];
	int top;
};
//ham xu ly cho AStack

void init(AStack &st)
{
	st.top = -1;
}
bool isEmpty(AStack st)
{
	return (st.top == -1);
}
bool isFull(AStack st)
{
	return (st.top == MAX - 1);
}
void push(AStack &st, int x)
{
	if (!isFull(st)){
		st.top++;
		st.Arr[st.top] = x;
	}
	return;
}
int pop(AStack &st)
{
	if (!isEmpty(st))
		st.top--;
	return st.Arr[st.top + 1];
}
int Top(AStack st)
{
	return st.Arr[st.top];
}
void display(AStack st)
{
	if (isEmpty(st)){
		cout << "Empty Stack!!!" << endl;
		return;
	}
	cout << "Stack: ";
	for (int i = 0; i <= st.top; i++)
		cout << st.Arr[i] << " ";
	cout << endl;
}

void display(int Arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << Arr[i] << " ";
	cout << endl;
}
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
int partion(int A[], int l, int r)
{

	int Pivot = A[r];
	int pole = l - 1, index = pole + 1;
	while (index < r)
	{
		if (A[index] < Pivot){
			pole++;
			swap(A[pole], A[index]);
		};
		index++;
	}
	swap(A[pole + 1], A[r]);
	return pole + 1;
}
void quickSortWithStack(int A[],int n)
{
	/*Init Stack 
	Stack chua indexes la pham vi se xet trong mang*/
	AStack st; init(st); int l = 0, r = n - 1; 
	push(st, l); push(st, r);

	while (!isEmpty(st))
	{
		int r = pop(st); int l = pop(st);//LIFO 
		if (l != r)//mang dang xet nhieu hon 1 phan tu
		{
			int p = partion(A, l, r);//partion() thuc hien chia mang A tu l toi r lam 3 phan va tra ve vi tri moc
			if (p>l)//neu p==l thi (p-1) la right lai < l la left SAI
				push(st, l); push(st, p - 1);
			if (p<r)//neu p==r thi (p+1) la left lai > l la right SAI 
				push(st, p + 1); push(st, r);
		}
	}

}

int _tmain(int argc, _TCHAR* argv[])
{
	int A[10] = { 5, 2, 3, 7, 1, 6, 11, 2, 8 };
	display(A, 9);
	quickSortWithStack(A, 9);
	display(A, 9);
	return 0;
}

