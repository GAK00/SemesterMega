/*
 * CicularList.hpp
 *
 *  Created on: Mar 15, 2017
 *      Author: gkun9931
 */

#ifndef MODEL_CICULARLIST_HPP_
#define MODEL_CICULARLIST_HPP_
#include "DoubleList.hpp"
#include<assert.h>
#include <cstddef>
template<class Type>
class CircularList: public DoubleList<Type>
    {
private:
public:
    CircularList();
    ~CircularList();
    void add(Type data);
    Type remove(int index);
    Type getFromIndex(int index);
    Type setAtIndex(int index, Type data);
    BiDirectionalNode<Type> * findNode(int index);
    };

template<class Type>
CircularList<Type>::CircularList() :
	DoulbyLinkedList<Type>()
    {

    }
template<class Type>
CircularList<Type>::~CircularList()
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
BiDirectionalNode<Type> * CircularList<Type>::findNode(int index)
    {
    BiDirectionalNode<Type> * toFind = new BiDirectionalNode<Type>(data);
    if (index < thisgetSize() / 2)
   	{
   	toFind = this->getFront();
   	for (int spot = 0; spot < index; spot++)
   	    {
   	    toFind = toFind->getNextPointer();
   	    }
   	}
       else
   	{
   	toFind = this->getEnd();
   	for (int spot = this->getSize() - 1; spot > index; spot--)
   	    {
   	    toFind= toFInd->getPreviousPointer();
   	    }
   	}
    }
template<class Type>
void CircularList<Type>::add(Type data)
    {
    BiDirectionalNode<Type> * addMe = new BiDirectionalNode<Type>(data);
    if (this->getSize() == 0)
	{
	this->setFront(addMe);
	this->setEnd(addMe);
	addMe->setPreviousPointer(this->getFront());
	this->getFront()->setNextPointer(this->getEnd());
	}
    else
	{
	this->getEnd()->setNextPointer(addMe);
	addMe->setPreviousPointer(this->getEnd());
	addMe->setNextPointer(this->getFront());
	this->getFront()->setPreviousPointer(addMe);
	this->setEnd(addMe);
	}
    this->setSize(this->getSize() + 1);
    }
template<class Type>
Type CircularList<Type>::remove(int index)
    {
    assert(index >= 0 && index < this->getSize());
    Type removedValue;
    BiDIrectionalNode<Type> * removed = findNode(index);
    removedValue = removed->getNodeData();
    BiDirectionalNode<Type> * oldPrevious = removed->getPreviousPointer();
    BiDirectionalNode<Type> * oldNext = removed->getNextPointer();
    if (this->getSize() > 1)
	{
	oldPrevious->setNexPointer(oldNext);
	oldNext->setPreviousPointer(oldPrevious);
	}
    else
	{
	this->setFront(nullptr);
	this->setEnd(nullptr);
	}
    delete removed;
    this->setSize(this->getSize - 1);
    return removedValue;
    }
template<class Type>
Type CircularList<Type>::getFromIndex(int index)
    {
    assert(index>=0 && index<this->getSize());
    return findNode(index)->getNodeData();
    }
template<class Type>
Type CircularList<Type>::setAtIndex(int index,Type data)
    {
    assert(index>=0 && index<this->getSize());
    BiDirectionalNode<Type> * toSet = findNode(index);
    Type toReturn = toSet->getNodeData();
    toSet->setNodeData(data);
    return toReturn;
    }

#endif /* MODEL_CICULARLIST_HPP_ */
