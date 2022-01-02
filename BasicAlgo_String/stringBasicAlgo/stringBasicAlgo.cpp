// stringBasicAlgo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"mystring.h"

int _tmain(int argc, _TCHAR* argv[])
{
	/*string S;
	getline(cin,S);
	cout << countToken(S) << endl;*/

	/*string S1, S2;
	getline(cin, S1); getline(cin, S2);
	cout << compareString(S1, S2) << endl;*/

	/*string stringArray[1000];
	int nS;
	inputArrayString(nS, stringArray);
	sortStringArray(nS, stringArray);
	outputArrayString(nS, stringArray);*/
	
	/*string S;
	getline(cin, S); 
	//cout << sumStringNumber(S) << endl;
	//int num = stoi(S); HAM CHI CO TAC DUNG VOI CHUOI TOAN SO

	string temp=myReverseString(S);
	cout << S << endl;
	cout << temp << endl;*/

	/*char c;
	cin >> c;
	cout << cToI(c) << endl;
	cout << charLower(c) << endl;
	cout << iToC(cToI(c)) << endl;*/

	/*char S[1000];
	gets_s(S,1000);

	//phai dung kieu char[] hoac char*  roi chuyen qua string 04 09 2021
	normalizeCharArray(S);
	cout << S << endl;*/

	string S;
	getline(cin,S);
	cout << S << endl;

	vector<string> arrToken; int nTokens = 0;
	nTokens = ParseString(arrToken, S);
	for (int i = 0; i < arrToken.size(); i++)
		cout << arrToken[i] << endl;

	string mergeString;
	MergeToken(mergeString, arrToken, 2, nTokens);
	cout << mergeString << endl;
	return 0;
}

