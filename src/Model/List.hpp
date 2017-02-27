/*
 * List.hpp
 *
 *  Created on: Feb 21, 2017
 *      Author: gkun9931
 */

#ifndef MODEL_LIST_HPP_
#define MODEL_LIST_HPP_
#include "Node.hpp"
template<class Type>
class List
    {
private:
    //dataMembers
    int size;
    Node<Type> * front;
    Node<Type> * end;
public:
    //constructors
    List<Type>();
    List<Type>(const List<Type> & source);
    ~List<Type>();
    //methods
    void addAtIndex(int index, Type value);
    void add(Type value);
    void addFront(Type value);
    Type remove(int index);
    Type setAtIndex(int index, Type value);
    Type getFromIndex(int index);
    bool contains(Type value);
    int getSize() const;
    Node<Type>* getEnd() const;
    Node<Type>* getFront() const;
    };
//Implementation
#include <cstddef>
#include <assert.h>
//constructors
template<class Type>
List<Type>::List()
    {
    size = 0;
    front = nullptr;
    end = nullptr;
    }
template<class Type>
List<Type>::List(const List<Type> & source)
    {
    this->size = source.getSize();
    this->front = new Node<Type>();
    for(int index = 1; index< size; index++)
	{
	Node<Type> * temp = new Node<Type>();
	temp->setNodePointer(front);
	front = temp;
	}
    Node<Type> * copyTemp = source.getFront();
    Node<Type> * updated = this->front;
    for(int index = 0; index < size; index++)
	{
	updated -> setNodeData(copyTemp->getNodeData());
	updated = updated->getNodePointer();
	copyTemp = copyTemp->getNodePointer();
	}
    this -> end = updated;
    }
template<class Type>
List<Type>::~List()
    {
    Node<Type> * destruction = front;
    while(front != nullptr)
	{
	front = front->getNodePointer();
	delete destruction;
	destruction = front;
	}
    }
//methods
template<class Type>
void List<Type>::addAtIndex(int index, Type value)
    {
    assert(index >= 0 && index <= size);
    if (index == 0)
	{
	addFront(value);
	}
    else if (index == size)
	{
	add(value);
	}
    else
	{
	Node<Type> * insertedNode = new Node<Type>(value);
	Node<Type> * current = front;
	for (int currentIndex = 0; currentIndex < index - 1; currentIndex++)
	    {
	    current = current->getNodePointer();
	    }
	insertedNode->setNodePointer(current->getNodePointer());
	current->setNodePointer(insertedNode);
	size++;
	}

    }
template<class Type>
void List<Type>::add(Type value)
    {
    if (this->size == 0)
	{
	Node<Type> * end = new Node<Type>(value);
	this->front = end;
	this->end = end;
	}
    else
	{
	Node<Type> * newEnd = new Node<Type>(value);
	this->end->setNodePointer(newEnd);
	this->end = newEnd;
	}
    size++;
    }
template<class Type>
void List<Type>::addFront(Type value)
    {
    if (size == 0)
	{
	Node<Type> * first = new Node<Type>(value);
	this->front = first;
	this->end = first;
	}
    else
	{
	Node<Type> * newFirst = new Node<Type>(value, front);
	this->front = newFirst;
	}
    size++;
    }
template<class Type>
Type List<Type>::remove(int index)
    {
    Type data;
    //making sure index is valid
    assert(index < size && index >= 0);
    Node<Type> * toRemove;
    //Handling no previous
    if (index - 1 < 0)
	{
	//if there is no previous the removed node has to be the front
	toRemove = front;
	//checking to make sure that this is not also the end node and handling accordingly
	if (toRemove->getNodePointer() == nullptr)
	    {
	    front = nullptr;
	    end = nullptr;
	    }
	else
	    {
	    front = toRemove->getNodePointer();
	    }
	}

    //Handling with previous
    else
	{
	Node<Type> * previous = front;
	//getting previous node
	for (int currentIndex = 0; currentIndex < index - 1; currentIndex++)
	    {
	    previous = previous->getNodePointer();
	    }
	//setting the node to be removed
	toRemove = previous->getNodePointer();
	//setting previous to point past the soon to be removed node
	previous->setNodePointer(previous->getNodePointer()->getNodePointer());
	//Checking to see if previous is now end
	if (previous->getNodePointer() == nullptr)
	    {
	    this->end = previous;
	    }
	}
    data = toRemove->getNodeData();
    delete(toRemove);
    size--;
    return data;
    }
template<class Type>
Type List<Type>::setAtIndex(int index, Type value)
    {
    assert(index < size && index >= 0);
    Node<Type> * current = front;
    for (int currentIndex = 0; currentIndex < index; currentIndex++)
	{
	current = current->getNodePointer();
	}
    Type data  = current->getNodeData();
    current->setNodeData(value);
    return data;
    }
template<class Type>
Type List<Type>::getFromIndex(int index)
    {
    Type data;
    assert(index < size && index >= 0);
    Node<Type> * current = front;
    for (int currentIndex = 0; currentIndex < index; currentIndex++)
	{
	current = current->getNodePointer();
	}
    data = current->getNodeData();
    return data;
    }
template<class Type>
bool List<Type>::contains(Type value)
    {
    bool valueContained = false;
    Node<Type> * current = front;
    if(current->getNodeData() == value)
	{
	valueContained = true;
	}

    for(int index = 0; index<size; index++)
	{
	current = current->getNodePointer;
	if(current->getNodeData() == value)
	    {
	    valueContained = true;
	    }
	}
return valueContained;
    }
template<class Type>
int List<Type>::getSize() const
    {
	return size;
    }
template<class Type>
Node<Type>* List<Type>::getFront() const
    {
    return front;
    }
template<class Type>

Node<Type>* List<Type>::getEnd() const
    {
    return end;
    }

#endif /* MODEL_LIST_HPP_ */
