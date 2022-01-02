// Backtracking_HanoiTower.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace  std;

void moveDisk(int colA, int colB)
{
	cout << colA << " " << colB << endl;
}
void Tower(int n,int col1,int col2,int col3)
{
	if (n > 0)
	{
		Tower(n - 1, col1, col3, col2);
		moveDisk(col1, col3);
		Tower(n - 1, col2, col1, col3);
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int diskNum;
	cin >> diskNum;
	Tower(diskNum, 1, 2, 3);
	return 0;
}

