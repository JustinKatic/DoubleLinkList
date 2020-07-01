#include<iostream>
#include"DLinkedListFunctions.h"

DLinkedListFunctions dLink;

int main()
{

	DLinkedListFunctions list;
	list.PushBack(10);
	list.PushFront(8);
	list.PushBack(9);
	list.BubbleSort();
	list.DeleteFirst();
	list.PrintList();
	list.InsertAfter(0, 34);
	list.PrintList();

	system("pause");

	int choice;

	//while true
	while (1)
	{
		//getting user choice and error checking an int is entered
		system("cls");
		std::cout << "1.PushFront\n2.PushBack\n3.InsertAfter\n4.DeleteFirst\n5.DeleteLast\n6.PrintList\n7.Exit\n8.printHeadNode\n9.printTailNode\n10.returnNumberOfNodes\n11.DeleteAtUserInput\n12.BubbleSort\n13.IsListEmpty\n";
		dLink.PrintList();
		std::cin >> choice;
		if (std::cin.fail())
		{
			dLink.ErrorCheck();
			continue;
		}

		//push front
		else if (choice == 1)
		{
			int element;
			std::cout << "Enter data: ";
			std::cin >> element;
			if (std::cin.fail())
			{
				dLink.ErrorCheck();
				continue;
			}
			dLink.PushFront(element);
		}

		//push back
		else if (choice == 2)
		{
			int element;
			std::cout << "Enter data: ";
			std::cin >> element;
			if (std::cin.fail())
			{
				dLink.ErrorCheck();
				continue;
			}
			dLink.PushBack(element);
		}

		//insert after
		else if (choice == 3)
		{
			int newData;
			int prevData;
			std::cout << "Enter the data in prev location to where youd like new data after: ";
			std::cin >> prevData;
			if (std::cin.fail())
			{
				dLink.ErrorCheck();
				continue;
			}
			std::cout << "Enter new Data: ";
			std::cin >> newData;
			if (std::cin.fail())
			{
				dLink.ErrorCheck();
				continue;
			}
			dLink.InsertAfter(prevData, newData);
		}

		//delete first
		else if (choice == 4)
		{
			dLink.DeleteFirst();
		}

		//delete last
		else if (choice == 5)
		{
			dLink.DeleteLast();
		}

		//print list
		else if (choice == 6)
		{
			dLink.PrintList();
			system("pause");
		}

		//exit
		else if (choice == 7)
		{
			break;
		}

		//print headNode
		else if (choice == 8)
		{
			std::cout << dLink.ReturnHead()->data << std::endl;
			system("pause");
		}

		//print tailNode
		else if (choice == 9)
		{
			std::cout << dLink.ReturnTail()->data << std::endl;
			system("pause");
		}

		//return number of nodes
		else if (choice == 10)
		{
			dLink.ReturnNumOfNodes();
			system("pause");
		}

		//deleted after
		else if (choice == 11)
		{
			int position;
			std::cout << "Enter the index location to where youd like remove data from: ";
			std::cin >> position;
			if (std::cin.fail())
			{
				dLink.ErrorCheck();
				continue;
			}
			dLink.DeleteNode(position);
		}

		//bubble sort
		else if (choice == 12)
		{
			dLink.BubbleSort();
		}

		//is list empty
		else if (choice == 13)
		{
			std::cout << dLink.IsEmpty() << std::endl;
			system("pause");
		}

		//error check
		else if (choice >= 14 || choice <= 0)
		{
			std::cout << "incorrect input enter one of the displayed options" << std::endl;
			system("cls");
		}
	}
	return 0;
}