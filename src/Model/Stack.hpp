/*
 * Stack
 *
 *  Created on: Mar 1, 2017
 *      Author: gkun9931
 */

#ifndef MODEL_STACK_
#define MODEL_STACK_
#include "DoubleList.hpp"
#include <cstddef>
template<class Type>
class Stack: public DoubleList<Type>
    {
private:
public:
    Stack();
    ~Stack();
    void add(Type value);
    Type remove(int index);
    Type pop();
    Type peek();
    void push(Type value);
    };

/*
 the add method only adds to the end
 */
using namespace std;
#include <ioStream>
template<class Type>
Stack<Type>::Stack()
    {

    }
template<class Type>
Stack<Type>::~Stack()
    {
    BiDirectionalNode<Type> * remove = this->getFront();
    while (this->getFront() != nullptr)
	{
	this->setFront(this->getFront()->getNextPointer());
	delete remove;
	remove = this->getFront();
	}
    }
template<class Type>
void Stack<Type>::add(Type value)
    {
    push(value);
    }
template<class Type>
void Stack<Type>::push(Type value)
    {
    if (this->getSize() == 0 || this->getFront() == nullptr
	    || this->getEnd() == nullptr)
	{
	BiDirectionalNode<Type> *newNode = new BiDirectionalNode<Type>(value);
	this->setFront(newNode);
	this->setEnd(newNode);
	}
    else
	{
	cout<<this->getFront()<<endl;
	BiDirectionalNode<Type> * toAdd = new BiDirectionalNode<Type>(value,
		this->getEnd(), nullptr);
	this->getEnd()->setNextPointer(toAdd);
	this->setEnd(toAdd);
	}
    this->setSize(this->getSize() + 1);
    }

template<class Type>
Type Stack<Type>::remove(int index)
    {
    assert(index == this->getSize() - 1 && this->getSize() > 0);
    return pop();
    }
template<class Type>
Type Stack<Type>::pop()
    {
    assert(this->getSize() > 0);
    Type removedValue;
    BiDirectionalNode<Type> * toDelete;
    if (this->getSize() == 1)
	{
	removedValue = this->getEnd()->getNodeData();
	toDelete = this->getEnd();
	delete toDelete;
	this->setFront(nullptr);
	this->setEnd(nullptr);
	}
    else
	{
	removedValue = this->getEnd()->getNodeData();
	toDelete = this->getEnd();
	this->getEnd()->getPreviousPointer()->setNextPointer(nullptr);
	this->setEnd(this->getEnd()->getPreviousPointer());
	delete toDelete;
	}

    this->setSize(this->getSize() - 1);
    return removedValue;

    }
template<class Type>
Type Stack<Type>::peek()
    {
    assert(this->getSize() > 0);
    return this->getEnd()->getNodeData();
    }

#endif /* MODEL_STACK_ */
