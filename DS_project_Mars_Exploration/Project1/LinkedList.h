#pragma once
#include"Nodo.h"
#include<iostream>
using namespace std;


template <typename T>
class LinkedList
{
private:
	Nodo<T>* Head;

public:

	LinkedList();

	~LinkedList();
	Nodo<T>* getHead();
	// Prints the linked list in the required format
	// DON'T CHANGE ANYTHING INSIDE THIS FUNCTION *********
	// BECAUSE THE AUTOMATIC JUDGE COMPARES FOR THIS FORMAT
	void DeleteNode(Nodo<T>* Doll);
	void PrintList()	const;

	// DO NOT CHANGE ANYTHING IN THIS FUNCTION *********
	void ReadList();

	// you should NOT change this function
	void InsertEnd( T data);

	void DeleteAll();
};


template < typename T>
inline LinkedList<T>::LinkedList()
{
	Head = nullptr;
}
template < typename T>
inline LinkedList<T>::~LinkedList()
{
	DeleteAll();
}
template < typename T>
inline Nodo<T>* LinkedList<T>::getHead()
{
	return Head;
}
// Prints the linked list in the required format
// DON'T CHANGE ANYTHING INSIDE THIS FUNCTION *********
// BECAUSE THE AUTOMATIC JUDGE COMPARES FOR THIS FORMAT
template < typename T>
inline void LinkedList<T>::DeleteNode(Nodo<T>* Doll)
{
	if (Doll == Head)
	{
		Head = Head->getnext();
		Doll->setnext(0);
		delete(Doll);
		Doll = Head;
	}
	else
	{
		Nodo<T>* Toll = Head;
		while (Toll->getnext() != Doll)
			Toll = Toll->getnext();
		if (Doll->getnext() == NULL)
			Toll->setnext(0);
		else
		{
			Toll->setnext(Doll->getnext());
		}
		delete(Doll);
		Doll = Toll;
	}
}
template < typename T>
inline void LinkedList<T>::PrintList()	const
{
	Nodo<T>* p = Head;
	while (p)
	{
		cout << p->getitem() << " ";
		p = p->getnext();
	}
	cout << endl;
}

// DO NOT CHANGE ANYTHING IN THIS FUNCTION *********
template < typename T>
inline void LinkedList<T>::ReadList()
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
inline void LinkedList<T>::InsertEnd( T data)
{
	Nodo<T>* R = new Nodo<T>(data);
	if (!Head)
	{
		Head = R;
		return;
	}
	Nodo<T>* p = Head;
	while (p->getnext())
		p = p->getnext();
	p->setnext(R);
}
template < typename T>
inline void LinkedList<T>::DeleteAll()
{
	Nodo<T>* P = Head;
	while (Head)
	{
		P = Head->getnext();
		delete Head;
		Head = P;
	}
}