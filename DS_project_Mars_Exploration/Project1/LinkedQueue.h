#pragma once
#include"Node_Q.h"
#include<iostream>
using namespace std;

template <typename T>
class LinkedQueue
{
private:

	Node_Q<T>* backPtr;
	Node_Q<T>* frontPtr;
public:
	LinkedQueue();
	bool isEmpty() const;
	bool enqueue(const T& newEntry);
	bool dequeue(T& frntEntry);
	bool peek(T& frntEntry)  const;
	void print() const;
	~LinkedQueue();

	//copy constructor
	LinkedQueue(const LinkedQueue<T>& LQ);
};
