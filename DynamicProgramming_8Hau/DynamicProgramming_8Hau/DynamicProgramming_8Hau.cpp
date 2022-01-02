// DynamicProgramming_8Hau.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

void  printResult(int Re[])
{
	//O(n^2)
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
			if (Re[row] == col)
				cout << "1 ";
			else
				cout << "0 ";
		cout << endl;
	}
	cout << endl;
}
void tryHau(int Re[], int row,bool daXetCol[],bool daXetCheoChinh[],bool daXetCheoPhu[])
{
	if (row >= 8)
		printResult(Re);
	for (int col = 0; col < 8; col++)
		if (!daXetCol[col] && !daXetCheoChinh[row - col + 7] && !daXetCheoPhu[col + row]){
			daXetCol[col] = true; daXetCheoChinh[row - col + 7] = true; daXetCheoPhu[col + row] = true; Re[row] = col;
			tryHau(Re, row + 1,daXetCol,daXetCheoChinh,daXetCheoPhu);
			daXetCol[col] = false; daXetCheoChinh[row - col + 7] = false; daXetCheoPhu[col + row] = false; Re[row] = 0;
		}		
}
int _tmain(int argc, _TCHAR* argv[])
{
	//CHESSBOARD SIZE 'S 8X8	
	int Re[9]; bool daXetCol[9], daXetCheoChinh[16], daXetCheoPhu[16];
	for (int i = 0; i < 8; i++)
		daXetCol[i] = false;
	for (int j = (-7+7); j < (7+7); j++)//tai sao j khong the chay tu -7 HAY TIM HIEU
		daXetCheoChinh[j] = false;
	for (int k = 0; k < 15; k++)
		daXetCheoPhu[k] = false;
	for (int row = 0; row < 8; row++)
		Re[row] = 0;
	tryHau(Re, 0,daXetCol,daXetCheoChinh,daXetCheoPhu);
	return 0;
}

