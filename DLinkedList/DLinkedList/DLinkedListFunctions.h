#pragma once
#include<iostream>
class DLinkedListFunctions
{
public:
	struct Node
	{
		//data inside node
		int data;
		//pointer to the nextNode
		struct Node* nextNode;
		//Pointer to prev node
		struct Node* prevNode;
	};
	Node* headNode;
	Node* tailNode;
	int NumberOfNodes = 0;
	
	void Init();

	void PushFront(int newData);

	void PushBack(int newData);

	void InsertAfter(int prevData, int newData);

	void DeleteNode(int position);

	void PrintList();

	void DeleteFirst();

	void DeleteLast();

	void ReturnHead();

	void ReturnTail();

	void ReturnNumOfNodes();

	void BubbleSort();

	bool IsEmpty();

	void SwapNodes(Node* a, Node* b);

	void ErrorCheck();

};

