// Backtracking_MaDiTuan.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//Chessboard size 's 8x8
int dx[8] = { -2, -1, 1, 2, -2, -1, 2, 1 };
int dy[8] = { -1, -2, -2, -1, 1, 2, 1, 2 };

template <class T>
void setVal(T A[9][9],T x)
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			A[i][j] = x;
}

bool isValid(int a, int b)
{
	if ((a >= 0 && a <= 7) && (b >= 0 && b <= 7))
		return true;
	return false;
}
void printChessboard(int Chess[9][9])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			cout << Chess[i][j] << " ";
		cout << endl;
	}
}
void jumpHorse(int stepCount, int x, int y,bool Checked[9][9], int Chess[9][9])
{
	stepCount++;
	Checked[x][y] = true;
	Chess[x][y] = stepCount;
	
	if (stepCount == 64)
	{
		printChessboard(Chess);
		cout << endl;
		exit(0);
	}

	int nextX, nextY;
	for (int i = 0; i < 8; i++)
	{
		nextX = x + dx[i];
		nextY = y + dy[i];
		if (!Checked[nextX][nextY] && isValid(nextX, nextY))		
			jumpHorse(stepCount, nextX, nextY, Checked, Chess);					
	}
	Checked[x][y] = false;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int Chess[9][9]; bool Checked[9][9]; 	
	int x, y, stepCount = 0;

	setVal(Chess,0);
	setVal(Checked, false);

	cout << "Enter start posiotion x and y: ";
	cin >> x >> y;

	jumpHorse(stepCount, x, y, Checked, Chess);

	return 0;
}

