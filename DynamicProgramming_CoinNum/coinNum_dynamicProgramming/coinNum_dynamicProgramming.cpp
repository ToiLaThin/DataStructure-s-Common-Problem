// coinNum_dynamicProgramming.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"    
#include<iostream>
using  namespace std;

#define LIMIT_VALUE 1000000
int _tmain(int argc, _TCHAR* argv[])
{
	int coinType, expectedValue;
	int coinValues[1000];	
	cout << "Enter the types of coins and the expected value: ";
	cin >> coinType >> expectedValue;
	for (int index = 1; index <= coinType; index++)
		cin >> coinValues[index];

	int minCoinNumForThisValue[200];
	for (int val = 0; val <= expectedValue; val++)
		minCoinNumForThisValue[val] = LIMIT_VALUE;

	minCoinNumForThisValue[0] = 0;
	for (int nowVal = 1; nowVal <= expectedValue; nowVal++)//A-VALUE NEEDED TO BE OPTIMIZED
		for (int preVal = 0; preVal < nowVal; preVal++)
			if (minCoinNumForThisValue[preVal] != LIMIT_VALUE)//B-VALUE BE OPTIMIZED BEFORE A-VALUE,THERE ARE SOME VALUE WE CAN'T HAVE
			{
				for (int index = 1; index <= coinType; index++)
					if ((coinValues[index] + preVal) == nowVal)
						if (minCoinNumForThisValue[preVal] + 1 < minCoinNumForThisValue[nowVal])
							minCoinNumForThisValue[nowVal] = minCoinNumForThisValue[preVal] + 1;
			}

	cout << "Here 's the result: " << minCoinNumForThisValue[expectedValue] << endl;
	return 0;
}

