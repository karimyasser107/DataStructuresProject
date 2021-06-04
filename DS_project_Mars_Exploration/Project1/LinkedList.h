#include"Node.h"
#include<iostream>
using namespace std;
template <typename T>
class LinkedList
{
private:
	Node<T>* Head;

public:

	LinkedList()
	{
		Head = nullptr;
	}

	~LinkedList()
	{
		DeleteAll();
	}
	Node* getHead()
	{
		return Head;
	}
	// Prints the linked list in the required format
	// DON'T CHANGE ANYTHING INSIDE THIS FUNCTION *********
	// BECAUSE THE AUTOMATIC JUDGE COMPARES FOR THIS FORMAT
	void DeleteNode(Node*Doll)
	{
		if (Doll == Head)
		{
			Head = Head->getNext();
			Doll->setNext(0);
			delete(Doll);
			Doll = Head;
		}
		else
		{
			Node<T>* Toll = Head;
			while (Toll->getNext() != Doll)
				Toll = Toll->getNext();
			if (Doll->getNext() == NULL)
				Toll->setNext(0);
			else
			{
				Toll->setNext(Doll->getNext());
			}
			delete(Doll);
			Doll = Toll;
		}
	}
	void PrintList()	const
	{
		Node<T>* p = Head;
		while (p)
		{
			cout << p->getItem() << " ";
			p = p->getNext();
		}
		cout << endl;
	}

	// DO NOT CHANGE ANYTHING IN THIS FUNCTION *********
	void ReadList()
	{
		int val;
		cin >> val;
		while (val != -1)
		{
			this->InsertEnd(val);
			cin >> val;
		}
	}

	// you should NOT change this function
	void InsertEnd(const T& data)
	{
		Node<T>* R = new Node<T>(data);
		if (!Head)
		{
			Head = R;
			return;
		}
		Node<T>* p = Head;
		while (p->getNext())
			p = p->getNext();
		p->setNext(R);
	}

	void DeleteAll()
	{
		Node<T>* P = Head;
		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
	}
};