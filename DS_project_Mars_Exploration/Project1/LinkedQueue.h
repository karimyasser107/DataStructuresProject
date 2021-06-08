#pragma once
#include<iostream>
#include"Nodo.h"
using namespace std;
template <typename T>
class LinkedQueue
{
private:

	Nodo<T>* backPtr;
	Nodo<T>* frontPtr;
public:
	LinkedQueue();
	bool isEmpty() const;
	bool enqueue(T newEntry);
	bool dequeue(T& frntEntry);
	bool peek(T& frntEntry)  const;
	Nodo<T>* getFrontptr();
	int getQueueSize(); 
	void print() const;
	~LinkedQueue();

	//copy constructor
	LinkedQueue(const LinkedQueue<T>& LQ);
};

template<typename T>
inline LinkedQueue<T>::LinkedQueue()
{
	backPtr = NULL;
	frontPtr = NULL;

}

template<typename T>
inline bool LinkedQueue<T>::isEmpty() const
{
	return (frontPtr == nullptr);
}

template<typename T>
inline bool LinkedQueue<T>::enqueue( T newEntry)
{

	Nodo<T>* newNode_QPtr = new Nodo<T>(newEntry);
	// Insert the new node
	if (isEmpty())	//special case if this is the first node to insert
		frontPtr = newNode_QPtr; // The queue is empty
	else
		backPtr->setnext(newNode_QPtr); // The queue was not empty

	backPtr = newNode_QPtr; // New node is the last node now
	return true;
}

template<typename T>
inline bool LinkedQueue<T>::dequeue(T& frntEntry)
{
	if (isEmpty())
		return false;

	Nodo<T>* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getitem();
	frontPtr = frontPtr->getnext();
	// Queue is not empty; remove front
	if (nodeToDeletePtr == backPtr)	 // Special case: last node in the queue
		backPtr = nullptr;

	// Free memory reserved for the dequeued node
	delete nodeToDeletePtr;

	return true;
}

template<typename T>
inline bool LinkedQueue<T>::peek(T& frntEntry) const
{
	if (isEmpty())
		return false;

	frntEntry = frontPtr->getitem();
	return true;
}

template<typename T>
inline Nodo<T>* LinkedQueue<T>::getFrontptr()
{
	return frontPtr;
}

template <typename T>
int LinkedQueue<T> ::getQueueSize()
{
	Nodo<T>* ptr = frontPtr;
	int c = 0;
	while (ptr != nullptr)
	{
		c++;
		ptr = ptr->getnext();
	}
	return c;
}

template<typename T>
inline void LinkedQueue<T>::print() const
{
	Nodo<T>* ptr = frontPtr;
	while (ptr)
	{
		cout << ptr->getitem() << " ";
		ptr = ptr->getnext();
	}
	cout << endl;
}

template<typename T>
inline LinkedQueue<T>::~LinkedQueue()
{
	T temp;

	//Free (Dequeue) all nodes in the queue
	while (dequeue(temp));
}

template<typename T>
inline LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& LQ)
{
	Nodo<T>* Node_QPtr = LQ.frontPtr;
	if (!Node_QPtr) //LQ is empty
	{
		frontPtr = backPtr = nullptr;
		return;
	}

	//insert the first node
	Nodo<T>* ptr = new Nodo<T>(Node_QPtr->getitem());
	frontPtr = backPtr = ptr;
	Node_QPtr = Node_QPtr->getnext();

	//insert remaining nodes
	while (Node_QPtr)
	{
		Nodo<T>* ptr = new Nodo<T>(Node_QPtr->getitem());
		backPtr->setnext(ptr);
		backPtr = ptr;
		Node_QPtr = Node_QPtr->getnext();
	}
}




