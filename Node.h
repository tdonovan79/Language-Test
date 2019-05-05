//Node.h
//Thomas Donovan
//4/3/19
#ifndef _NODE
#define _NODE

template<class ItemType>
class Node
{
	private:
		//an item of data
		ItemType item;
		//pointer to next node
		Node<ItemType>* next;
	public:
		//constructors
		Node();
		Node(const ItemType& anItem);
		Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
		//set item to a value
		void setItem(const ItemType& anItem);
		//set next pointer to a value
		void setNext(Node<ItemType>* nextNodePtr);
		//return item
		ItemType getItem() const ;
		//return pointer to next node
		Node<ItemType>* getNext() const ;
		
};
//constructors
template<class ItemType>
Node<ItemType>::Node() : next(nullptr)
{
}
template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem), next(nullptr)
{	
}

template< class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) : item(anItem), next(nextNodePtr)
{
}

//set value for an item
template< class ItemType>
void Node<ItemType>::setItem( const ItemType& anItem)
{
	item = anItem;
}

//set value for pointer to next node
template< class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
	next = nextNodePtr;
}

//return value of an item
template< class ItemType>
ItemType Node<ItemType>::getItem() const
{
	return item;
}

//return pointer to next node
template< class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
 return next;
}
#endif


