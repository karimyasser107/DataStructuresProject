#pragma once
#include<iostream>
using namespace std;
template < typename T>
class Node_Q
{
private:
	T item; // A data item
	Node_Q<T>* next; // Pointer to next node
public:
	Node_Q();
	Node_Q(const T& r_Item);
	Node_Q(const T& r_Item, Node_Q<T>* nextNode_QPtr);
	void setItem(const T& r_Item);
	void setNext(Node_Q<T>* nextNode_QPtr);
	T getItem() const;
	Node_Q<T>* getNext() const;
}; // end Node_Q