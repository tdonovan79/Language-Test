//LinkedStack.h
//Thomas Donovan
//4/3/19
#ifndef _LINKED_STACK
#define _LINKED_STACK
#include "StackInterface.h"
#include "Node.h"
#include <cassert>


template< class ItemType>
class LinkedStack : public StackInterface<ItemType>
{
	private:
		//pointer to top of stack
		Node<ItemType>* topPtr;
	public:
		//constructors
		LinkedStack();
		LinkedStack(const LinkedStack<ItemType>& aStack);
		//destructor
		virtual ~LinkedStack();
		//check if stack is empty
 		bool isEmpty() const;
 		//add new item to top of stack
 		bool push(const ItemType& newItem);
 		//take item off of top of stack
 		bool pop();
 		//return item at top of stack
 		ItemType peek() const;
};
//constructors
template<class ItemType>
LinkedStack<ItemType>::LinkedStack() : topPtr(nullptr)
{
}
//Copy constructor
template<class ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& aStack)
{
	// Point to nodes in original chain
 	Node<ItemType>* origChainPtr = aStack.topPtr;
 	//if origChainPointer is null original is empty
	if (origChainPtr == NULL)
 		topPtr = NULL;
	else
 	{
 		//Copy original Node
 		topPtr = new Node<ItemType>();
 		topPtr->setItem(origChainPtr->getItem());
 		// Point to first node in new chain
 		Node<ItemType>* newChainPtr = topPtr;
 		// Copy remaining nodes
 		while (origChainPtr != NULL)
 		{
			// Advance original-chain pointer
 			origChainPtr = origChainPtr->getNext();
			// Get next item from original chain
			 ItemType nextItem = origChainPtr->getItem();
			// Create a new node containing the next item
 			Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
			// Link new node to end of new chain
 			newChainPtr->setNext(newNodePtr);
			// Advance pointer to new last node
 			newChainPtr = newChainPtr->getNext();
 		}
 		//mark end of chain
 		newChainPtr->setNext( NULL);
	}
}
//deconstructor
template<class ItemType>
LinkedStack<ItemType>::~LinkedStack()
{
	//Pop until stack is empty
	while (!isEmpty())
		pop();
}
//see if stack is empty
template<class ItemType>
bool LinkedStack<ItemType>::isEmpty() const
{
	return topPtr == NULL;
}
//add new node to top of stack
template<class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newItem)
{
	Node<ItemType>* newNodePtr = new Node<ItemType>(newItem, topPtr);
	topPtr = newNodePtr;
	newNodePtr = NULL;
	return true;
}
//if stack is not empty, delete top node
template<class ItemType>
bool LinkedStack<ItemType>::pop()
{
	bool result = false;
	if (!isEmpty())
 	{
 		Node<ItemType>* nodeToDeletePtr = topPtr;
		topPtr = topPtr->getNext();
		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
 		nodeToDeletePtr = nullptr;
 		result = true;
 	}
	return result;
}
//if stack is not empty, return top node
template< class ItemType>
ItemType LinkedStack<ItemType>::peek() const
{
	assert(!isEmpty());
	return topPtr->getItem();
}

#endif






