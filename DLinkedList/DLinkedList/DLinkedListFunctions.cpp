#include "DLinkedListFunctions.h"

DLinkedListFunctions::DLinkedListFunctions()
{
	headNode = nullptr;
	tailNode = nullptr;
}

DLinkedListFunctions::~DLinkedListFunctions()
{
	while (IsEmpty() == false)
		DeleteFirst();
}



//puts new value at front of list and changes pointers
void DLinkedListFunctions::PushFront(int newData)
{
	// allocate new node
	Node* newNode = new Node;
	newNode->data = newData;
	//if list is empty
	if (headNode == nullptr)
	{
		headNode = newNode;
		newNode->prevNode = nullptr;
		newNode->nextNode = nullptr;
		tailNode = newNode;
		NumberOfNodes++;
	}
	//if list has more then 1 element
	else
	{
		newNode->nextNode = headNode;
		newNode->prevNode = nullptr;
		headNode->prevNode = newNode;
		headNode = newNode;
		NumberOfNodes++;
	}
}

//puts new value at back of list and changes pointers
void DLinkedListFunctions::PushBack(int newData)
{
	// allocate new node
	Node* newNode = new Node;
	newNode->data = newData;
	//if list is empty
	if (headNode == nullptr)
	{
		headNode = newNode;
		newNode->prevNode = nullptr;
		newNode->nextNode = nullptr;
		tailNode = newNode;
		NumberOfNodes++;
	}
	//if list has more then 1 element
	else
	{
		newNode->prevNode = tailNode;
		tailNode->nextNode = newNode;
		newNode->nextNode = nullptr;
		tailNode = newNode;
		NumberOfNodes++;
	}
}
//insert node after selected the position enterted
void DLinkedListFunctions::InsertAfter(int position, int newData)
{
	Node* newNode = new Node;
	Node* tempNode;
	tempNode = headNode;

	//if no headNode exists there is nothing in list
	if (headNode == nullptr)
	{
		//coulnt insert
		return;
	}

	if (headNode == tailNode)
	{
		//sets newNode data = newData
		newNode->data = newData;
		//sets nextNode of headNode to newNode
		headNode->nextNode = newNode;
		//sets nextNode of NewNode to null ptr
		newNode->nextNode = nullptr;
		//sets prevNode of headNode to null ptr
		headNode->prevNode = nullptr;
		//sets prevNode of newNode to headNode
		newNode->prevNode = headNode;
		//sets tailNode to newNode
		tailNode = newNode;
		//exits function
		NumberOfNodes++;
		return;
	}

	//while data inside of tempNodeNode != prevData keep looping
	//while (tempNode->data != prevData)
	for (int i = 1; i < position; i++)
	{
		//tempNodeNode++
		tempNode = tempNode->nextNode;
		//if couldnt find data send error msg
		if (tempNode == nullptr)
		{
			return;
		}
	}

	if (tempNode == tailNode)
	{
		//sets newnode data = newData
		newNode->data = newData;
		//sets nextNode of newNode = nullptr
		newNode->nextNode = nullptr;
		//sets prevNode of newNode to tailNode
		newNode->prevNode = tailNode;
		//sets nextNode of tailNode 
		tailNode->nextNode = newNode;
		//sets tailNode = newNode
		tailNode = newNode;
		NumberOfNodes++;
		//exits function
		return;
	}
	{
		//sets newNode data = newData
		newNode->data = newData;
		//sets newNode NextNode to TempNode NextNode
		newNode->nextNode = tempNode->nextNode;
		//sets newNode prevNode to TempNode
		newNode->prevNode = tempNode;
		//set prev of new node's nextNode to newNode
		tempNode->nextNode->prevNode = newNode;
		//sets nextNode of tempNode to NewNode
		tempNode->nextNode = newNode;
	}
}
//deletes node at position entered
void DLinkedListFunctions::DeleteNode(int position)
{
	Node* tempNode;
	tempNode = headNode;

	//if no headNode exists there is nothing in list
	if (headNode == nullptr)
	{
		return;
	}
	//loops through till temp node == position
	for (int i = 1; i < position; i++)
	{
		tempNode = tempNode->nextNode;
	}

	//if head is temp node use deleteFirst method
	if (tempNode->prevNode == nullptr)
	{
		DeleteFirst();
	}
	//if tail is temp node use deleteFirst method
	else if (tempNode->nextNode == nullptr)
	{
		DeleteLast();
	}
	//delete node where tempnode is
	else
	{
		tempNode->nextNode->prevNode = tempNode->prevNode;
		tempNode->prevNode->nextNode = tempNode->nextNode;
		delete tempNode;
		NumberOfNodes--;

	}

}

//print list 
void DLinkedListFunctions::PrintList()
{
	int i = 1;
	Node* tempNode;
	tempNode = headNode;
	while (tempNode != nullptr)
	{
		std::cout << i << "." << tempNode->data << std::endl;
		tempNode = tempNode->nextNode;
		i++;
	}
	std::cout << std::endl;
}


//delete first node in list
void DLinkedListFunctions::DeleteFirst()
{
	if (headNode == nullptr)
	{
		return;
	}
	//if only 1 item in list
	if (headNode == tailNode)
	{
		Node* tempNode;
		tempNode = headNode;
		headNode = nullptr;
		tailNode = nullptr;
		delete tempNode;
		NumberOfNodes--;
		return;
	}
	//if more then 1 item in list
	else
	{
		struct Node* tempNode;
		tempNode = headNode;
		headNode = headNode->nextNode;
		headNode->prevNode = nullptr;
		delete tempNode;
		NumberOfNodes--;
		return;
	}
}
//delete last node in list
void DLinkedListFunctions::DeleteLast()
{
	//if nothing in list exit function
	if (headNode == nullptr)
	{
		return;
	}

	//if only one node in list delete node and make head and tail node nullptr
	if (headNode == tailNode)
	{
		Node* tempNode;
		tempNode = headNode;
		headNode = nullptr;
		tailNode = nullptr;
		delete tempNode;
		NumberOfNodes--;
		return;
	}
	//delete last node
	else
	{
		Node* tempNode;
		tempNode = tailNode;
		tailNode = tailNode->prevNode;
		tailNode->nextNode = nullptr;
		delete tempNode;
		NumberOfNodes--;
		return;
	}
}
//prints the data at head node
DLinkedListFunctions::Node* DLinkedListFunctions::ReturnHead()
{
	return headNode;
}
//prints data at tail node
DLinkedListFunctions::Node* DLinkedListFunctions::ReturnTail()
{
	return tailNode;
}

//prints number of nodes
void DLinkedListFunctions::ReturnNumOfNodes()
{
	std::cout << NumberOfNodes << std::endl;
}

//sorting list  
void DLinkedListFunctions::BubbleSort()
{
	Node* currentNode;

	//sets current node = head node for initial loop
	currentNode = headNode;
	bool sorted = false;
	//while list isnt sorted
	while (!sorted)
	{
		sorted = true;
		currentNode = headNode;

		//loop through number of nodes
		for (int i = 0; i < NumberOfNodes; i++)
		{
			//if next node isnt tailNode
			if (currentNode->nextNode != nullptr)
			{
				//if data > next data swap
				if (currentNode->data > currentNode->nextNode->data)	//if first string comes after second string swap
				{
					sorted = false;
					SwapNodes(currentNode, currentNode->nextNode);
				}
				//if no swap offcured
				else
				{
					currentNode->nextNode->prevNode = currentNode;
					currentNode = currentNode->nextNode;
				}
			}
		}
	}
}

//true/false to check if list is empty
bool DLinkedListFunctions::IsEmpty()
{
	//returns true if number of node == 0
	return NumberOfNodes == 0;
}

//  functions that swaps two nodes and ensures pointers are pointing to correct next and prev node
void DLinkedListFunctions::SwapNodes(Node* a, Node* b)
{
	if (a == b)
	{
		return;
	}
	// if swapping tailNode
	if (b->nextNode == nullptr)
	{
		tailNode = a;
		a->prevNode->nextNode = b;
		b->prevNode = a->prevNode;
		a->prevNode = b;
		a->nextNode = b->nextNode;
		b->nextNode = a;
	}
	// if swapping Node isnt headNode or tailNode
	else if (a->prevNode != nullptr)
	{
		a->prevNode->nextNode = b;
		b->prevNode = a->prevNode;
		a->prevNode = b;
		a->nextNode = b->nextNode;
		b->nextNode = a;
	}
	// if swapping headNode
	else if (a->prevNode == nullptr)
	{
		headNode = b;
		if (b == tailNode)
		{
			tailNode = a;
		}
		b->prevNode = nullptr;
		a->prevNode = b;
		a->nextNode = b->nextNode;
		b->nextNode = a;
	}
}

void DLinkedListFunctions::ErrorCheck()
{
	std::cout << "incorrect input enter correct input" << std::endl;
	system("pause");
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
}
