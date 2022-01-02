// Bai_3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"ab.h"
#include<iostream>
#include<string>
using namespace std;


int main()
{
	int nS; 
	string strs[100];
	inputArrayString(nS, strs);

	int index = 0;
	while (index < nS)
	{
		int subIndex = index + 1;
		while (subIndex < nS){
			while (strs[index] == strs[subIndex])
				delString(strs, nS, subIndex);
			subIndex++;
		}
		index++;
	}

	outputArrayString(nS, strs);
	return 0;
}


