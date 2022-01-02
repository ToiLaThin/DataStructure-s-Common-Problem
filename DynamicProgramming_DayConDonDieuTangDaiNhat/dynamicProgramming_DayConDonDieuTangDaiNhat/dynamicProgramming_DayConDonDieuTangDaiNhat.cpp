// dynamicProgramming_DayConDonDieuTangDaiNhat.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"basic.h"

int indexOfMaxValueInArray(int Arr[], int n)
{
	int re = NULL;
	int max = -1000000;
	for (int i = 0; i < n; i++)
		if (Arr[i]>max)
		{
			re = i;
			max = Arr[i];
		}
	return re;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int n, A[1000];
	inputArr(A, n);

	int L[1000],Before[1000];
	//KHOI TAO, Before[i] have the previus value of A[i] in the result array
	for (int i = 0; i < n; i++)
	{
		L[i] = 1;
		Before[i] = NULL;
	}
	//O(n^2)
	for (int now = 1; now < n; now++){
		for (int pre = 0; pre < now; pre++)
			if (A[pre]<A[now])
				if (L[pre] + 1>L[now])
				{
					L[now] = L[pre] + 1;
					Before[now] = pre;
				}
	}
	
	outputArr(L, n);
	
	return 0;
}

