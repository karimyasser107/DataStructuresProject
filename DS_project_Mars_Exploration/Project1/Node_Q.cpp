#include"Node_Q.h"
template < typename T>
Node_Q<T>::Node_Q()
{
	next = nullptr;
}

template < typename T>
Node_Q<T>::Node_Q(const T& r_Item)
{
	item = r_Item;
	next = nullptr;
}

template < typename T>
Node_Q<T>::Node_Q(const T& r_Item, Node_Q<T>* nextNode_QPtr)
{
	item = r_Item;
	next = nextNode_QPtr;
}
template < typename T>
void Node_Q<T>::setItem(const T& r_Item)
{
	item = r_Item;
}

template < typename T>
void Node_Q<T>::setNext(Node_Q<T>* nextNode_QPtr)
{
	next = nextNode_QPtr;
}

template < typename T>
T Node_Q<T>::getItem() const
{
	return item;
}

template < typename T>
Node_Q<T>* Node_Q<T>::getNext() const
{
	return next;
}