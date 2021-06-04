#pragma once
#include"Node.h"
#include<iostream>
using namespace std;


template <typename T>
class LinkedList
{
private:
	Node<T>* Head;

public:

	LinkedList();

	~LinkedList();
	Node<T>* getHead();
	// Prints the linked list in the required format
	// DON'T CHANGE ANYTHING INSIDE THIS FUNCTION *********
	// BECAUSE THE AUTOMATIC JUDGE COMPARES FOR THIS FORMAT
	void DeleteNode(Node<T>* Doll);
	void PrintList()	const;

	// DO NOT CHANGE ANYTHING IN THIS FUNCTION *********
	void ReadList();

	// you should NOT change this function
	void InsertEnd(const T& data);

	void DeleteAll();
};