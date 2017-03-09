/*
 * Queue
 *
 *  Created on: Mar 3, 2017
 *      Author: gkun9931
 */

#ifndef MODEL_QUEUE_HPP_
#define MODEL_QUEUE_HPP_

#include "DoubleList.hpp"
#include <cstddef>
template<class Type>
class Queue: public DoubleList<Type>
    {
private:
public:
    Queue();
    ~Queue();
    void add(Type data);
    void enqueue(Type data);
    Type dequeue();
    Type peek();
    Type remove(int index);
    };
using namespace std;
#include <iostream>
template<class Type>
Queue<Type>::Queue() :
	DoubleList<Type>()
    {

    }
template<class Type>
Queue<Type>::~Queue()
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
Type Queue<Type>::remove(int index)
    {
    assert(index == 0 && this->getSize() > 0);
    return dequeue();
    }
template<class Type>
Type Queue<Type>::dequeue()
    {

    assert(this->getSize() > 0);
    Type removedValue = this->getFront()->getNodeData();
    BiDirectionalNode<Type> * removeMe = this->getFront();

    if (this->getSize() == 1)
	{
	delete removeMe;
	this->setEnd(nullptr);
	this->setFront(nullptr);
	}
    else
	{
	this->setFront(removeMe->getNextPointer());
	this->getFront()->setPreviousPointer(nullptr);
	delete removeMe;
	}

    this->setSize(this->getSize() - 1);
    return removedValue;
    }
template<class Type>
Type Queue<Type>::peek()
    {
    assert(this->getSize() > 0);
    return this->getFront()->getNodeData();
    }
template<class Type>
void Queue<Type>::enqueue(Type value)
    {
    BiDirectionalNode<Type> * toAdd = new BiDirectionalNode<Type>(value);
    if (this->getSize() == 0 || this->getFront() == nullptr
	    || this->getEnd() == nullptr)
	{
	this->setFront(toAdd);
	this->setEnd(toAdd);
	}
    else
	{
	this->getEnd()->setNextPointer(toAdd);
	toAdd->setNextPointer(this->getEnd());
	this->setEnd(toAdd);
	}
    this->setSize(this->getSize() + 1);
    }
template<class Type>
void Queue<Type>::add(Type value)
    {
    this->enqueue(value);
    }

#endif /* MODEL_QUEUE_HPP_ */
