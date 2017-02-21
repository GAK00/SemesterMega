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
    //constructors
    Array<Type>(int size);
    Array<Type>();
    //Destructor
    ~Array<Type>();
    //Copy Constructor
    Array<Type>(const Array<Type> & toBeCopied);
    int getSize() const;
    Node<Type> * getFront() const;
    Type getFromIndex(int index);
    void setAtIndex(int index, Type value);
    //Assignement Operator
    void operator =(const Array<Type> & toBeAssigned);
    };
//cpp portion
using namespace std;
#include <iostream>
template<class Type>
Array<Type>::Array()
    {
    size = 0;
    front = nullptr;
    }
template<class Type>
Array<Type>::Array(int size)
    {
    assert(size > 0);
    this->size = size;
    front = nullptr;
    for (int index = 0; index < size; index++)
	{
	Node<Type> * currentNode = new Node<Type>();
	currentNode->setNodePointer(front);
	front = currentNode;
	}
    }
//destructor
template<class Type>
Array<Type>::~Array()
    {
    int count = size;
    Node<Type> * remove = front;
    while (front != nullptr)
	{
	//move to next node
	front = front->getNodePointer();
	cout << "moving to the next node. At: " << count << endl;
	//deletethe front pointer
	delete remove;
	cout << "deleting the old front pointer." << endl;
	remove = front;
	cout << "Moving to new front pointer." << endl;
	count--;
	cout << "Front is at: " << front << "count is :" << count << endl;
	}
    }
//copy constructor
template<class Type>
Array<Type>::Array(const Array<Type> & toBeCopied)
    {
    this->size = toBeCopied.getSize();
    this->front = new Node<Type>();
    for(int index = 1; index< size; index++)
	{
	Node<Type> * temp = new Node<Type>();
	temp->setNodePointer(front);
	front = temp;
	}
    Node<Type> * copyTemp = toBeCopied.getFront();
    Node<Type> * updated = this->front;
    for(int index = 0; index < size; index++)
	{
	updated -> setNodeData(copyTemp->getNodeData());
	updated = updated->getNodePointer();
	copyTemp = copyTemp->getNodePointer();
	}
    }
template<class Type>
int Array<Type>::getSize() const
    {
    return this->size;
    }
template<class Type>
Node<Type> * Array<Type>::getFront() const
    {
    return this->front;
    }
template<class Type>
Type Array<Type>::getFromIndex(int index)
    {
    assert(index >= 0 && index <= size);
    Node<Type> * currentPos = front;
    for (int currentIndex = 0; currentIndex < index; currentIndex++)
	{
	currentPos = currentPos->getNodePointer();
	}
    return currentPos->getNodeData();
    }
template<class Type>
void Array<Type>::setAtIndex(int index, Type value)
    {
    assert(index >= 0 && index <= size);
    Node<Type>*currentPos = front;
    for (int currentIndex = 0; currentIndex < index; currentIndex++)
	{
	currentPos = currentPos->getNodePointer();
	}
    currentPos->setNodeData(value);
    }
#endif /* MODEL_ARRAY_HPP_ */
