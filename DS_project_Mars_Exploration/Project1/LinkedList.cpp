#include"LinkedList.h"
#include<iostream>
using namespace std;

template < typename T>
LinkedList<T>::LinkedList()
{
	Head = nullptr;
}
template < typename T>
LinkedList<T>::~LinkedList()
{
	DeleteAll();
}
template < typename T>
Node<T>* LinkedList<T>::getHead()
{
	return Head;
}
// Prints the linked list in the required format
// DON'T CHANGE ANYTHING INSIDE THIS FUNCTION *********
// BECAUSE THE AUTOMATIC JUDGE COMPARES FOR THIS FORMAT
template < typename T>
void LinkedList<T>::DeleteNode(Node<T>* Doll)
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
template < typename T>
void LinkedList<T>::PrintList()	const
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
template < typename T>
void LinkedList<T>::ReadList()
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
template < typename T>
void LinkedList<T>::InsertEnd(const T& data)
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
template < typename T>
void LinkedList<T>::DeleteAll()
{
	Node<T>* P = Head;
	while (Head)
	{
		P = Head->getNext();
		delete Head;
		Head = P;
	}
}