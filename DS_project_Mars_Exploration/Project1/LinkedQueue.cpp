#include"LinkedQueue.h"

/*
Function: Queue()
The constructor of the Queue class.

*/
template <typename T>
inline LinkedQueue<T>::LinkedQueue()
{
	backPtr = nullptr;
	frontPtr = nullptr;

}

/*
Function: isEmpty
Sees whether this queue is empty.

Input: None.
Output: True if the queue is empty; otherwise false.
*/
template <typename T>
inline bool LinkedQueue<T>::isEmpty() const
{
	return (frontPtr == nullptr);
}

/*Function:enqueue
Adds newEntry at the back of this queue.

Input: newEntry .
Output: True if the operation is successful; otherwise false.
*/
template <typename T>
bool LinkedQueue<T>::enqueue(const T& newEntry)
{
	Node_Q<T>* newNode_QPtr = new Node_Q<T>(newEntry);
	// Insert the new node
	if (isEmpty())	//special case if this is the first node to insert
		frontPtr = newNode_QPtr; // The queue is empty
	else
		backPtr->setNext(newNode_QPtr); // The queue was not empty

	backPtr = newNode_QPtr; // New node is the last node now
	return true;
} // end enqueue

/*Function: dequeue
Removes the front of this queue. That is, removes the item that was added
earliest.

Input: None.
Output: True if the operation is successful; otherwise false.
*/
template <typename T>
inline bool LinkedQueue<T>::dequeue(T& frntEntry)
{
	if (isEmpty())
		return false;

	Node_Q<T>* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();
	// Queue is not empty; remove front
	if (nodeToDeletePtr == backPtr)	 // Special case: last node in the queue
		backPtr = nullptr;

	// Free memory reserved for the dequeued node
	delete nodeToDeletePtr;

	return true;

}

/*
Function: peek
copies the front of this queue to the passed param. The operation does not modify the queue.

Input: None.
Output: The front of the queue.
*/
template <typename T>
inline bool LinkedQueue<T>::peek(T& frntEntry) const
{
	if (isEmpty())
		return false;

	frntEntry = frontPtr->getItem();
	return true;

}

/*
Function: destructor
removes all nodes from the queue by dequeuing them
*/
template <typename T>
inline LinkedQueue<T>::~LinkedQueue()
{
	T temp;

	//Free (Dequeue) all nodes in the queue
	while (dequeue(temp));
}

/*
Function: Copy constructor
To avoid shallow copy,
copy constructor is provided

Input: LinkedQueue<T>: The Queue to be copied
Output: none
*/
template <typename T>
inline LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& LQ)
{
	Node_Q<T>* Node_QPtr = LQ.frontPtr;
	if (!Node_QPtr) //LQ is empty
	{
		frontPtr = backPtr = nullptr;
		return;
	}

	//insert the first node
	Node_Q<T>* ptr = new Node_Q<T>(Node_QPtr->getItem());
	frontPtr = backPtr = ptr;
	Node_QPtr = Node_QPtr->getNext();

	//insert remaining nodes
	while (Node_QPtr)
	{
		Node_Q<T>* ptr = new Node_Q<T>(Node_QPtr->getItem());
		backPtr->setNext(ptr);
		backPtr = ptr;
		Node_QPtr = Node_QPtr->getNext();
	}
}

template<typename T>
inline void LinkedQueue<T>::print() const
{
	Node_Q<T>* ptr = frontPtr;
	while (ptr)
	{
		cout << ptr->getItem() << " ";
		ptr = ptr->getNext();
	}
	cout << endl;
}
int main()
{
	LinkedQueue<int>H;
	Node_Q<int>* T = new Node_Q<int>(3);
}