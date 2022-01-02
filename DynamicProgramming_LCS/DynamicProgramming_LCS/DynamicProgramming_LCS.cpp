// DynamicProgramming_LCS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void initL(int L[256][256], string S1, string S2)
{
	//O(2*n+n^2)
	//lech chi so giua L, S1 va S2
	int c = S1.length(), r = S2.length();
	for (int col = 0; col <= c; col++)
		L[0][col] = 0;
	for (int row = 0; row <= r; row++)
		L[row][0] = 0;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			if (S2[i - 1] == S1[j - 1])
				L[i][j] = L[i - 1][j - 1] + 1;
			else{
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
			}
}

void createLCS(int L[256][256], int x, int y, string &LCS, string S1, string S2)
{
	if (x < 1 || y < 1)
		return;
	else{
		if (S1[x - 1] == S2[y - 1])
		{
			createLCS(L, x - 1, y - 1, LCS, S1, S2);
			LCS.push_back(S1[x - 1]);
		}
		else{
			if (L[x - 1][y] == max(L[x - 1][y], L[x][y - 1]))
				createLCS(L, x - 1, y, LCS, S1, S2);
			else if (L[x][y - 1] == max(L[x - 1][y], L[x][y - 1]))
				createLCS(L, x, y - 1 , LCS, S1, S2);
		}
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	string S1, S2;
	getline(cin,S1); getline(cin,S2); int l1 = S1.length(), l2 = S2.length();
	int L[256][256]; initL(L, S1, S2);

	string LCS = "";
	createLCS(L, l1, l2, LCS, S1, S2);
	cout << LCS << endl;
	return 0;
}

