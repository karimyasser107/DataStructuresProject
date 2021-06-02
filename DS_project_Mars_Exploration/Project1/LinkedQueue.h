/** ADT queue: Link-based implementation.
 @file LinkedQueue.h */
#ifndef _LINKED_QUEUE 
#define _LINKED_QUEUE 
#include "QueueInterface.h" 
#include "Node.h" 
#include "PrecondViolatedExcep.h" 
template< class ItemType>
class LinkedQueue : public QueueInterface<ItemType>
{
private:
	// The queue is implemented as a chain of linked nodes that has 
	// two external pointers, a head pointer for the front of the queue 
	// and a tail pointer for the back of the queue. 
	Node<ItemType>* backPtr;
	Node<ItemType>* frontPtr;
public:
	LinkedQueue();
	LinkedQueue(const LinkedQueue& aQueue);
	~LinkedQueue();
	bool isEmpty() const;
	bool enqueue(const ItemType& newEntry);
	bool dequeue();
	/** @throw PrecondViolatedExcep if the queue is empty */
	ItemType peekFront() const throw(PrecondViolatedExcep);
}; // end LinkedQueue 
//#include "LinkedQueue.cpp" 
#endif 

