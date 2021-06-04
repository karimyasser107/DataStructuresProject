#pragma once
#include<iostream>
using namespace std;

// ================== Class Node ========================

template<typename T>
class Node
{
private:
	T item;
	Node<T>* next;
public:

	Node();

	Node(T newItem);

	void setItem(T newItem);

	void setNext(Node<T>* nextNodePtr);

	T getItem() const;

	Node<T>* getNext() const;
};