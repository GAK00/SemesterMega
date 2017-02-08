/*
 * IntNodeArray.cpp
 *
 *  Created on: Feb 8, 2017
 *      Author: gkun9931
 */

#include "IntNodeArray.hpp"
#include "IntNode.hpp"
#include <assert.h>
IntNodeArray::IntNodeArray(int size)
    {
    assert(size > 0);
    this->size = size;
    this->head = new IntNode();
    for(int index = 0; index < size; index++)
	{
	IntNode * currentNode = new IntNode();
	currentNode->setNodePointer(head);
	head = currentNode;
	}
    int IntNodeArray :: getFromIndex(int index)
	{
	int value = 0;

	return value;
	}
    }

