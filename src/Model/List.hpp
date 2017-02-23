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

    }
template<class Type>
List<Type>::~List()
    {

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
	addEnd(value);
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
	this->end = new end;
	}
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
	if (toRemove->getNodePointer == nullptr)
	    {
	    front = nullptr;
	    end = nullptr;
	    }
	else
	    {
	    front = toRemove->getNodePointer;
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
	toRemove = previous->getNodePointer;
	//setting previous to point past the soon to be removed node
	previous->setNodePointer(toRemove->getNodePointer->getNodePointer);
	//Checking to see if previous is now end
	if (previous->getNodePointer() == nullptr)
	    {
	    this->end = previous;
	    }
	}
    data = toRemove->getNodeData();
    return data;
    }
template<class Type>
Type List<Type>::setAtIndex(int index, Type value)
    {

    }
template<class Type>
Type List<Type>::getFromIndex(int index)
    {
    Type data;
    assert(index < size && index >= 0);
    Node<Type> * current = front;
    for (int currentIndex = 0; currentIndex < index; currentIndex++)
	{
	current = current->getNodePointer;
	}
    data = current->getNodeData;
    return data;
    }
template<class Type>
bool List<Type>::contains(Type value)
    {

    }
template<class Type>
int List<Type>::getSize() const
    {

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
