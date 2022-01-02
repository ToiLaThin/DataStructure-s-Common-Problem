// Main.cpp : Defines the entry point for the console application.
//my implementation comes from : https://www.geeksforgeeks.org/circular-singly-linked-list-insertion */

#include "stdafx.h"
#include"CirSinglyLinkedList.h"


void Josephus(int n, int k);
int _tmain(int argc, _TCHAR* argv[])
{
	int n, k;
	cout << "Nhap so nguoi trong tro choi n: ";
	cin >> n;
	cout << "Nhap so buoc nhay k: ";
	cin >> k;
	Josephus(n,k);
	return 0;
}

void Josephus(int n, int k)
{
	//init the game
	//data moi la thu tu cua moi nguoi 
	//con index thi luon thay doi vi xoa lien tuc
	CirSinglyLinkedList<int> killCircle = CirSinglyLinkedList<int>();
	int i = 1;
	while (i <= n)
	{
		killCircle.addLast(i);
		i++;
	}

	Node<int>* killNode = killCircle.tail->next; 
	Node<int>* preNode = killCircle.tail;
	int step = k - 1;
	while (killCircle.tail != killCircle.tail->next)//there 's still more than one alive
	{
		i = 0;
		while (i < step)//chay den nguoi can giet
		{
			preNode = killNode;
			killNode = killNode->next;
			i++;
		}
		//de dam bao van con killNode cho cac lan sau
		Node<int>* temp = killNode->next;

		if (killNode == killCircle.tail->next)
			killCircle.delFirst();
		else if (killNode == killCircle.tail)
			killCircle.delLast();
		else{
			preNode->next = temp;
			free(killNode); killNode = nullptr; //xoa
		}
		killNode = temp;
	}

	cout << killCircle.tail->data << endl;
}

