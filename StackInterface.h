//StackInterface.h
//Thomas Donovan
//4/3/19
#ifndef _STACK_INTERFACE
#define _STACK_INTERFACE
template<class ItemType>
class StackInterface
{
		public:
			//see if stack is empty
			virtual bool isEmpty() const = 0;
 			//add new node to top of stack
			virtual bool push( const ItemType& newEntry) = 0;
			//remove node from top of stack
			virtual bool pop() = 0;
			//return item at top of stack
			virtual ItemType peek() const = 0;
};
#endif 
