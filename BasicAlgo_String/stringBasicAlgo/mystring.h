#ifndef MY_STRING
#define MY_STRING

#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

void inputArrayString(int &nS, string S[])
{
	cin >> nS;
	cin.ignore();
	for (int i = 0; i < nS; i++)
		getline(cin, S[i]);
}
void outputArrayString(int nS, string S[])
{
	for (int i = 0; i < nS; i++)
		cout << S[i] << endl;
}
int myStringLength(string S)
{
	int i = 0;
	S = S.c_str();
	while (S[i] != '\0')
		i++;
	return i;
}
int countToken(string S)
{
	bool meetedToken = false;
	int result = 0;
	char c;
	for (int idx = 0; idx < S.length(); idx++)
	{
		c = S[idx];
		if (c != ' '){//chuyen tu false sang true thi tang khi gap 1 ki tu chu
			if (!meetedToken)
			{
				meetedToken = true;
				result++;
			}
		}
		else if (c == ' '){
			if (meetedToken)
				meetedToken = false;
		}
	}
	return result;
}
int compareString(string S1, string S2)
{
	int l1 = S1.length(); int l2 = S2.length(); 
	int n = min(l1, l2);

	for (int i = 0; i < n; i++)
		if (S1[i] < S2[i])
			return -1;
		else if (S1[i]>S2[i])
			return 1;

	//den duoc day ma chua thoat co nghia: hai chuoi co cung chuoi con chieu dai n
	//1 la S1> S2 -1 la be hon 0 la bang nhau
	if (l1 == l2)
		return 0;
	else
	{
		if (l1 > l2)
			return 1;
		else
			return -1;
	}
}
void swapString(string& S1, string& S2)
{
	string temp = S1;
	S1 = S2;
	S2 = temp;
}
void swapChar(char &a, char &b)
{
	char temp = a;
	a = b;
	b = temp;
}
void sortStringArray(int nS, string S[])
{
	for (int i = 0; i < nS - 1; i++)
		for (int j = i + 1; j < nS; j++)
			//if (compareString(S[i], S[j]) == 1)
			if (S[i]>S[j])
				swap(S[i], S[j]);
}
int cToI(char c)
{
	return (c - 48);
}
char iToC(int x)//xem lai ham nay ki tu sang so -48 so ra ki tu +48
{
	return (char(x) + 48);
}

/*char charUpper(char c)
{
	return c - 32;
}*/
void upperChar(char &c)
{
	c = c - 32;
}
/*char charLower(char c)
{
	return c + ('a' - 'A');//c+32
}*/
void lowerChar(char &c)
{
	c = c + ('a' - 'A');
}
int sumStringNumber(string S)
{
	int sum = 0,k;
	bool meetedNum = false;
	char temp[16];
	for (int idx = 0; idx < S.length(); idx++)
	{
		if (S[idx] >= '0' && S[idx] <= '9')
		{
			if (!meetedNum){
				meetedNum = true;
				k = 0;
			}
			temp[k++] = S[idx];
		}
		else{
			if (meetedNum)
			{
				temp[k] = '\0';
				meetedNum = false;
				sum += atoi(temp);
			}
		}
	}
	//xu ly TH co so o cuoi
	if (meetedNum)
	{
		temp[k] = '\0';
		sum += atoi(temp);
	}

	return sum;
}

string& myReverseString(string &S)
{
	int l = myStringLength(S);
	int n = S.length() / 2;
	for (int i = 0; i < n; i++)
		swapChar(S[i], S[l - 1 - i]);
	return S;
}
void delWhiteSpace(char* S,int pos)
{
	int l = strlen(S);
	for (int i = pos; i < l - 1; i++)
		S[i] = S[i + 1];
	S[l - 1] = '\0';
}
void normalizeCharArray(char* S)
{
	//xoa khoang rang thua
	int idx = 0, l = strlen(S);
	while (idx < l)
	{
		if (S[idx] == ' ')
			while (S[idx + 1] == ' ')		
				delWhiteSpace(S, idx + 1);	
		idx++;
		l = strlen(S);
	}
	
	//kiem tra de chuan hoa
	if (S[0] >= 'a' && S[0] <= 'z')
		upperChar(S[0]);
	for (int i = 0; i < l; i++)
		if (S[i] == ' ' && (S[i + 1] >= 'a' && S[i + 1] <= 'z'))
			upperChar(S[i + 1]);
		else if ((S[i] >= 'A' && S[i] <= 'Z') && S[i - 1] != ' ')
			lowerChar(S[i]);
}

void CopySubString(string& dest,string source, int starPos,int numChars)
{
	//method substr lay ra 1 phan chuoi co numChars ki tu bat dau tu startPos 
	//dest va source co the la cung 1 chuoi de thuc hien thao tac  chen xoa 1 chuoi 
	dest = source.substr(starPos, numChars);
}
void GetLeftSubString(string& dest, string source, int numChars){
	int length = source.length();
	if (numChars > length)
		numChars = length;
	CopySubString(dest, source, 0, numChars);
}
void GetRightSubString(string& dest, string source, int numChars){
	int length = source.length();
	if (numChars > length)
		numChars = length;
	CopySubString(dest, source, length - numChars, numChars);
}
void GetSubString(string& dest, string source, int StartPos, int numChars){
	int length = source.length();
	if (StartPos < length)
	{
		if (StartPos > length - numChars)
			numChars = length - StartPos;//doi lai so ki tu can lay
		CopySubString(dest, source, StartPos, numChars);
	}
	else
		dest = "";
}

int CountWord(string S)
{
	string sep = " ,.;:\n\t";
	int nWords = 0;
	int firstPosNotSep = S.find_first_not_of(sep, 0);
	int firstPosSep = S.find_first_of(sep, firstPosNotSep);
	//Xem ki lai dieu kien
	while (firstPosNotSep != string::npos || firstPosSep != string::npos){
		nWords++;
		firstPosNotSep = S.find_first_not_of(sep, firstPosSep);
		firstPosSep = S.find_first_of(sep, firstPosNotSep);
	}
	return nWords;
}
int GetToken(string& token,string source,int& startPos)
{
	string sep = " ,.;:\n\t";
	int fromPos, toPos, length = source.length(), tokenLength = 0;

	fromPos = source.find_first_not_of(sep, startPos);//tim tu startPos
	if (fromPos == string::npos)
		return tokenLength;
	toPos = source.find_first_of(sep, fromPos);
	if (toPos == string::npos)
		toPos = length;

	tokenLength = toPos - fromPos;
	token = source.substr(fromPos, tokenLength);
	startPos = toPos;
	return tokenLength;
}
//tach cac token va cho vao 1 mang
int ParseString(vector<string>& arrToken, string source){
	string token = "";
	int startPos = 0, nTokens = 0;
	while (GetToken(token, source, startPos) > 0)
	{
		nTokens++;
		arrToken.push_back(token);
	}
	return nTokens;
}
//iStart la lay merge cac token tu iStart
void MergeToken(string& dest, vector<string> arrToken, int iStart, int nTokens)
{
	if (nTokens == 0)
		dest = "";
	else{
		//nen nho dest da dc khai bao ben ngoai roi
		dest = arrToken[iStart];//de cong voi khoang trang ngay sau token dau tien
		for (int i = iStart + 1; i < arrToken.size(); i++){
			dest += " ";
			dest += arrToken[i];
		}
	}
}
#endif