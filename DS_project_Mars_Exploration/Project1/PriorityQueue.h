#pragma once
#include<iostream>
#include"Nodo.h"
using namespace std;
template <typename T>
class PriorityQueue
{
private:

	Nodo<T>* backPtr;
	Nodo<T>* frontPtr;
	int greater;
public:
	PriorityQueue();
	bool isEmpty() const;
	bool dequeue(T& frntEntry);
	bool peek(T& frntEntry)  const;
	void print() const;
	void push(T& ito, int signo);
	~PriorityQueue();

	//copy constructor
	PriorityQueue(const PriorityQueue<T>& LQ);
};

template<typename T>
inline PriorityQueue<T>::PriorityQueue()
{
	backPtr = nullptr;
	frontPtr = nullptr;

}

template<typename T>
inline bool PriorityQueue<T>::isEmpty() const
{
	return (frontPtr == nullptr);
}


template<typename T>
inline bool PriorityQueue<T>::dequeue(T& frntEntry)
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
inline bool PriorityQueue<T>::peek(T& frntEntry) const
{
	if (isEmpty())
		return false;

	frntEntry = frontPtr->getitem();
	return true;
}

template<typename T>
inline void PriorityQueue<T>::print() const
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
inline void PriorityQueue<T>::push(T& ito, int signo)
{
	if (isEmpty())
	{
		Nodo<T>* kok = new Nodo<T>(ito);
		kok->setsign(signo);
		backPtr = frontPtr = kok;
		kok->setnext(NULL);
		greater = signo;
	}
	else
	{
		if (signo > greater)
		{
			Nodo<T>* kok = new Nodo(ito);
			kok->setsign(signo);
			kok->setnext(frontPtr);
			frontPtr = kok;
			greater = signo;
		}
		else
		{
			Nodo<T>* kod;
			kod = frontPtr;
			while (kod->getnext()->getsign() > signo && kod->getnext()!=NULL)
			{
				kod = kod->getnext();
			}
			if (kod->getnext() == NULL)
			{
				Nodo<T>* kok = new Nodo(ito);
				kok->setsign(signo);
				kok->setnext(kod->getnext());
				kod->getnext(kok);
				backPtr = kok;
			}
			else
			{
				Nodo<T>* kok = new Nodo(ito);
				kok->setsign(signo);
				kok->setnext(kod->getnext());
				kod->getnext(kok);
			}
		}
	}
}

template<typename T>
inline PriorityQueue<T>::~PriorityQueue()
{
	T temp;

	//Free (Dequeue) all nodes in the queue
	while (dequeue(temp));
}

template<typename T>
inline PriorityQueue<T>::PriorityQueue(const PriorityQueue<T>& LQ)
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





