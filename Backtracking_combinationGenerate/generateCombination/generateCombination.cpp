// generateCombination.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "basic.h"
void  kCombinationGenerate(int preValue, int pos, int combination[], int maxValue, int k)
{
	if (pos == k)
		outputArr(combination, k);
	else
	{
		for (int val = preValue + 1; val <= maxValue; val++)
		{
			combination[pos] = val;
			kCombinationGenerate(val, pos + 1, combination, maxValue, k);
		}
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int maxValue,k; int Com[1000];
	cout << "Input the number of elements and the k: ";
	cin >> maxValue >> k;
	for (int k = 0; k <= maxValue; k++)
		kCombinationGenerate(0, 0, Com, maxValue, k);
	return 0;
}

