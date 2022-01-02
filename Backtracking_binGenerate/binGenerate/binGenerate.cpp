// binGenerate.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "basic.h"

void binGenerate(int pos, int Arr[], int n)
{
	//n cay nhi phan
	if (pos == n)
		outputArr(Arr, n);
	else
	{
		for (int val = 0; val <= 1; val++)
		{
			Arr[pos] = val;
			binGenerate(pos + 1, Arr, n);
		}
	}

}
void pertumationGernerate(int pos, int Arr[], int n, bool isDisplayed[])
{
	//n cay n phan 
	//phan biet pos va val
	if (pos == n)
		outputArr(Arr, n);
	else
	{
		for (int val = 1; val <= n; val++)
			if (!isDisplayed[val])
			{
				Arr[pos] = val;
				isDisplayed[val] = true;
				pertumationGernerate(pos + 1, Arr, n, isDisplayed);
				isDisplayed[val] = false;
		    }
	}

}
int _tmain(int argc, _TCHAR* argv[])
{
	int A[100],n; 
	cin >> n;
	//binGenerate(0, A, n);
	bool isDisplayed[10000];
	for (int val = 1; val <= n; val++)
		isDisplayed[val] = false;

	pertumationGernerate(0, A, n, isDisplayed);

	return 0;
}

