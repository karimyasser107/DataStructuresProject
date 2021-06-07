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
	void PrintList()	const;

	void DeleteNode(Nodo<T>* Doll);
	void DeleteHead(T&);

	void ReadList();
	bool isEmpty();

	void InsertEnd( T data);

	int getListSize();

	Nodo<T>* getNode_With_Pos(int);

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
 void LinkedList<T>::DeleteHead(T& passed_Item)
{
	passed_Item = Head->getitem();
	Nodo<T>* temp = Head;
	Head=temp->getnext();
	delete temp;
	return;
}


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

template<typename T>
inline bool LinkedList<T>::isEmpty()
{
	if (Head == NULL)
		return true;
	else
		return false;
}


template < typename T>
inline void LinkedList<T>::InsertEnd( T  data)
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

template <typename T>
int LinkedList<T> ::getListSize()
{
	Nodo<T>* ptr = Head;
	int c = 0;
	while (ptr != nullptr)
	{
		c++;
		ptr = ptr->getnext();
	}
	return c;
	
}

template <typename T>
Nodo<T>* LinkedList<T> ::getNode_With_Pos(int pos)
{
	if (pos == 0)
		return NULL;
	int c = 0;
	Nodo<T>* ptr = Head;
	while (ptr)
	{
		c++;
		if (c = pos)
			return ptr;
		ptr = ptr->getnext();
	}
	return NULL;
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