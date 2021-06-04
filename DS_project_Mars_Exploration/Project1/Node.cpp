#include"Node.h"
#include<iostream>
using namespace std;
template < typename T>
Node<T>::Node()
{
	next = nullptr;
}
template < typename T>
Node<T>::Node(T newItem)
{
	item = newItem;
	next = nullptr;

}
template < typename T>
void Node<T>::setItem(T newItem)
{
	item = newItem;
}
template < typename T>
void Node<T>::setNext(Node<T>* nextNodePtr)
{
	next = nextNodePtr;
}
template < typename T>
T Node<T>::getItem() const
{
	return item;
}
template < typename T>
Node<T>* Node<T>::getNext() const
{
	return next;
}