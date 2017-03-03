/*
 * BiDirectionalNode.hpp
 *
 *  Created on: Feb 27, 2017
 *      Author: gkun9931
 */

#ifndef MODEL_BIDIRECTIONALNODE_HPP_
#define MODEL_BIDIRECTIONALNODE_HPP_

#include "Node.hpp"

template<class Type>
class BiDirectionalNode: public Node<Type>
    {
private:
    BiDirectionalNode<Type> * prevPointer;
    BiDirectionalNode<Type> * nextPointer;
public:
    BiDirectionalNode();
    BiDirectionalNode(Type data);
    BiDirectionalNode(Type data, BiDirectionalNode<Type>*previous,
	    BiDirectionalNode<Type> * next);
    BiDirectionalNode<Type> * getPreviousPointer();
    void setPreviousPointer(BiDirectionalNode<Type> * prevPointer);
    BiDirectionalNode<Type> * getNextPointer();
    void setNextPointer(BiDirectionalNode<Type> * prevPointer);
    };

//Implementation
template<class Type>
BiDirectionalNode<Type>::BiDirectionalNode() :
	Node<Type>::Node()
    {
    prevPointer = nullptr;
    nextPointer = nullptr;
    }
template<class Type>
BiDirectionalNode<Type>::BiDirectionalNode(Type data) :
	Node<Type>::Node(data)
    {

    prevPointer = nullptr;
    nextPointer = nullptr;
    }
template<class Type>
BiDirectionalNode<Type>::BiDirectionalNode(Type data,
	BiDirectionalNode<Type> * previous, BiDirectionalNode<Type> * next) :
	Node<Type>::Node(data)
    {
    this->prevPointer = previous;
    this->nextPointer = next;
    }
template<class Type>
BiDirectionalNode<Type> * BiDirectionalNode<Type>::getPreviousPointer()
    {
    return prevPointer;
    }
template<class Type>
void BiDirectionalNode<Type>::setPreviousPointer(BiDirectionalNode<Type> * prev)
    {
    this->prevPointer = prev;
    }
template<class Type>
BiDirectionalNode<Type> * BiDirectionalNode<Type>::getNextPointer()
    {
    return nextPointer;
    }
template<class Type>
void BiDirectionalNode<Type>::setNextPointer(BiDirectionalNode<Type> * next)
    {
    this->nextPointer = next;
    }
#endif /* MODEL_BIDIRECTIONALNODE_HPP_ */
