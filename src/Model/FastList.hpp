/*
 * FastList.hpp
 *
 *  Created on: Mar 3, 2017
 *      Author: gkun9931
 */

#ifndef MODEL_FASTLIST_HPP_
#define MODEL_FASTLIST_HPP_
#include "DoubleList.hpp"
template<class Type>
class FastList: public DoubleList<Type>
    {
private:
public:
    FastList();
    ~FastList();
    Type getFromIndexFast(int index);
    void setAtIndexFast(int index, Type value);
    Type remove(int index);
    Type getFromIndex(int index);
    void setAtIndex(int index, Type value);
    void add(Type value);
    };
template<class Type>
FastList<Type>::FastList() :
	DoubleList<Type>()
    {
    }
template<class Type>
FastList<Type>::~FastList()
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
Type FastList<Type>::getFromIndexFast(int index)
    {
    assert(index >= 0 && index < this->getSize());
    Type valueAtIndex;
    BiDirectionalNode<Type>* reference;
    if (index < this->getSize() / 2)
	{
	reference = this->getFront();
	for (int position = 0; position < index; position++)
	    {
	    reference = reference->getNextPointer();
	    }
	}
    else
	{
	reference = this->getEnd();
	for (int position = this->getSize() - 1; position > index; position--)
	    {
	    reference = reference->getPreviousPointer();
	    }
	}
    valueAtIndex = reference->getNodeData();
    return valueAtIndex;
    }
template<class Type>
Type FastList<Type>::getFromIndex(int index)
    {
    assert(index >= 0 && index < this->getSize());
    Type valueAtIndex;
    BiDirectionalNode<Type>* reference;
    reference = this->getFront();
    for (int position = 0; position < index; position++)
	{
	reference = reference->getNextPointer();
	}

    valueAtIndex = reference->getNodeData();
    return valueAtIndex;

    }
template<class Type>
void FastList<Type>::setAtIndexFast(int index, Type value)
    {
    assert(index >= 0 && index < this->getSize());
    Type valueAtIndex;
    BiDirectionalNode<Type>* reference;
    if (index < this->getSize() / 2)
	{
	reference = this->getFront();
	for (int position = 0; position < index; position++)
	    {
	    reference = reference->getNextPointer();
	    }
	}
    else
	{
	reference = this->getEnd();
	for (int position = this->getSize() - 1; position > index; position--)
	    {
	    reference = reference->getPreviousPointer();
	    }
	}
    valueAtIndex = reference->setNodeData(value);
    }
template<class Type>
void FastList<Type>::setAtIndex(int index, Type value)
    {
    assert(index >= 0 && index < this->getSize());
    Type valueAtIndex;
    BiDirectionalNode<Type>* reference;
    reference = this->getFront();
    for (int position = 0; position < index; position++)
	{
	reference = reference->getNextPointer();
	}

    valueAtIndex = reference->setNodeData(value);
    }
template<class Type>
void FastList<Type>::add(Type value)
    {
    BiDirectionalNode<Type> * addNode = new BiDirectionalNode<Type>(value);
    if (this->getSize() == 0)
	{
	this->setFront(addNode);
	this->setEnd(addNode);
	}
    else
	{
	this->getEnd()->setNextPointer(addNode);
	addNode->setPreviousPointer(this->getEnd());
	}
    this->setEnd(addNode);
    this->setSize(this->getSize() + 1);
    }
template<class Type>
Type FastList<Type>::remove(int index)
    {
    Type derp;
    BiDirectionalNode<Type> * nodeToTakeOut = this->getFront();
    if (index < this->getSize() / 2)
	{
	nodeToTakeOut = this->getFront();
	for (int position = 0; position < index; position++)
	    {
	    nodeToTakeOut = nodeToTakeOut->getNextPointer();
	    }
	}
    else
	{
	nodeToTakeOut = this->getEnd();
	for (int position = this->getSize() - 1; position > index; position--)
	    {
	    nodeToTakeOut = nodeToTakeOut->getPreviousPointer();
	    }
	}
    derp = nodeToTakeOut->getNodeData();
    nodeToTakeOut->getPreviousPointer()->setNextPointer(nodeToTakeOut->getNextPointer());
    nodeToTakeOut->getNextPointer()->setPreviousPointer(nodeToTakeOut->getPreviousPointer());
    delete nodeToTakeOut;
    return derp;
    }

#endif /* MODEL_FASTLIST_HPP_ */
