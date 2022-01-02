// BalanPolishNotation.cpp : Defines the entry point for the console application.
// 20110729 Nguyen Duc Thinh 
// In comparision with v.1, these function can calculate a multi- digit number
// Nguon tham khao: https://www.tutorialspoint.com/Convert-Infix-to-Postfix-Expression
#include "stdafx.h"
#include<iostream>	
#include<string>
using namespace std;
#define MAX 100

struct AStack
{
	int Arr[MAX];
	int top;
};
//ham xu ly cho AStack

void init(AStack &st)
{
	st.top = -1;
}
bool isEmpty(AStack st)
{
	return (st.top == -1);
}
bool isFull(AStack st)
{
	return (st.top == MAX - 1);
}
void push(AStack &st, int x)
{
	if (!isFull(st)){
		st.top++;
		st.Arr[st.top] = x;
	}
	return;
}
int pop(AStack &st)
{
	if (!isEmpty(st))
		st.top--;
	return st.Arr[st.top + 1];
}
int Top(AStack st)
{
	return st.Arr[st.top];
}
void display(AStack st)
{
	if (isEmpty(st)){
		cout << "Empty Stack!!!" << endl;
		return;
	}
	cout << "Stack: ";
	for (int i = 0; i <= st.top; i++)
		cout << st.Arr[i] << " ";
	cout << endl;
}
//ham xu ly ky phap Balan

int precedenceOf(char ope)
{
	if (ope == '*' || ope == '/')
		return 2;
	else if (ope == '+' || ope == '-')
		return 1;
	else
		return 0;
	//( return 0 nhung precedence cua no thuc ra la lon nhat theo ly thuyet
}
string toPostfix(string infix)
{
	string postfix = "";
	AStack st; init(st);

	for (int i = 0; i < infix.length(); i++)
	{
		if (infix[i] >= '0'&&infix[i] <= '9')
		{//TH ki tu la toan hang
			postfix = postfix + infix[i];
		}
		else if (infix[i] == '(')
		{
			push(st, infix[i]);
		}
		else if (infix[i] == ')')
		{
			postfix += " ";//them ' ' truoc khi cong toan tu dc pop ra vao chuoi
			while (Top(st) != '(' && !isEmpty(st)) {//lay toan tu ra bo vao postfix cho toi khi gap  '(' trong stack
				postfix = postfix + (char)Top(st) + " ";
				pop(st);
			}
			pop(st);//lay ra '('
		}
		else
		{//TH ki tu la toan tu
			if (postfix[postfix.length() - 1] != ' ')
				postfix += " ";
			if (precedenceOf(infix[i]) > precedenceOf(Top(st)))
			{
				push(st, infix[i]);
			}
			else
			{
				while (!isEmpty(st) && (precedenceOf(infix[i]) <= precedenceOf(Top(st)))) {
					postfix = postfix + (char)Top(st) + " ";
					pop(st);
				}
				push(st, infix[i]);
			}
		}

	}
	if (!isEmpty(st) && (postfix[postfix.length() - 1] != ' '))
		postfix += " ";
	while (!isEmpty(st))
	{
		postfix = postfix + (char)Top(st) + " ";
		pop(st);
	}

	return postfix;
}
int resultOfOperation(char ope, int num1, int num2)
{
	switch (ope)
	{
	case '+': return num1 + num2;
	case '-': return num1 - num2;
	case '*': return num1 * num2;
	case '/': return num1 / num2;
	}
}
int toNum(string aNum)
{
	int res = 0;
	for (int i = 0; i < aNum.length(); i++)
	{
		res = res * 10 + int(aNum[i] - '0');
	}
	return res;
}
int calculatedResult(string postfix)
{
	AStack st; init(st);
	string aNum = "";
	for (int i = 0; i < postfix.length(); i++)
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
		{
			int num2 = pop(st); int num1 = pop(st);
			push(st, resultOfOperation(postfix[i], num1, num2));
		}
		else if ((postfix[i] == ' ') && (postfix[i - 1] >= '0'&& postfix[i - 1] <= '9'))
		{
			int temp = toNum(aNum);
			push(st, temp);
			aNum = "";
		}
		else if (postfix[i] >= '0'&& postfix[i] <= '9'){
			aNum += postfix[i];
		}

		return Top(st);
}



int _tmain(int argc, _TCHAR* argv[])
{
	string infix = "3+2*(7-4)/(2+1)";
	cout << infix << endl;
	cout << toPostfix(infix) << endl;
	cout << calculatedResult(toPostfix(infix)) << endl << endl;

	infix = "23-3*5";
	cout << infix << endl;
	cout << toPostfix(infix) << endl;
	cout << calculatedResult(toPostfix(infix)) << endl << endl;

	infix = "22*(3333-2135)";
	cout << infix << endl;
	cout << toPostfix(infix) << endl;
	cout << calculatedResult(toPostfix(infix)) << endl << endl;
	return 0;
}

