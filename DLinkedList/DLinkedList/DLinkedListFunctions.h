#pragma once
#include<iostream>
class DLinkedListFunctions
{
public:
	DLinkedListFunctions();
	~DLinkedListFunctions();

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


	void PushFront(int newData);

	void PushBack(int newData);

	void InsertAfter(int position, int newData);

	void DeleteNode(int position);

	void PrintList();

	void DeleteFirst();

	void DeleteLast();

	Node* ReturnHead();

	Node* ReturnTail();

	void ReturnNumOfNodes();

	void BubbleSort();

	bool IsEmpty();

	void SwapNodes(Node* a, Node* b);

	void ErrorCheck();
};

