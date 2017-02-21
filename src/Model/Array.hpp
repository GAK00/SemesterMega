/*
 * Array.hpp
 *
 *  Created on: Feb 15, 2017
 *      Author: gkun9931
 */

#ifndef MODEL_ARRAY_HPP_
#define MODEL_ARRAY_HPP_
#include "Node.hpp"
#include <cstddef>
#include <assert.h>
template<class Type>
class Array
    {
private:
    Node<Type> * front;
    int size;
public:
    Array<Type>(int size);
    Array<Type>();
    int getSize();
    Type getFromIndex(int index);
    void setAtIndex(int index, Type value);
    };
//cpp portion
template<class Type>
Array<Type> :: Array()
    {
    size = 0;
    front = nullptr;
    }
template<class Type>
Array<Type>::Array(int size)
    {
    assert(size>0);
    this->size = size;
    front = nullptr;
    for (int index = 0; index < size; index++)
	{
	Node<Type> * currentNode = new Node<Type>();
	currentNode->setNodePointer(front);
	front = currentNode;
	}
    }
template<class Type>
int Array<Type>::getSize()
    {
    return this->size;
    }
template<class Type>
Type Array<Type>::getFromIndex(int index)
    {
    assert(index>=0&&index<=size);
    Node<Type> * currentPos = front;
    for(int currentIndex = 0; currentIndex<index;currentIndex++)
	{
	    currentPos = currentPos->getNodePointer();
	}
    return currentPos->getNodeData();
    }
template<class Type>
void Array<Type>:: setAtIndex(int index,Type value)
    {
    assert(index>=0&&index<=size);
    Node<Type>*currentPos = front;
    for(int currentIndex =0; currentIndex<index;currentIndex++)
	{
	currentPos= currentPos->getNodePointer();
	}
    currentPos -> setNodeData(value);
    }
#endif /* MODEL_ARRAY_HPP_ */
