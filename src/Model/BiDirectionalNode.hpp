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
public:
    BiDirectionalNode();
    BiDirectionalNode(Type data);
    BiDirectionalNode(Type data, BiDirectionalNode<Type>*previous,
	    BiDirectionalNode<Type> * next);
    BiDirectionalNode<Type> * getPreviousPointer();
    void setPreviousPointer(BiDirectionalNode<Type> * prevPointer);
    };

//Implementation
template<class Type>
BiDirectionalNode<Type>::BiDirectionalNode() :Node<Type>::
	Node()
    {
    prevPointer = nullptr;
    }
template<class Type>
BiDirectionalNode<Type>::BiDirectionalNode(Type data) :Node<Type>::
	Node(data)
    {

    prevPointer = nullptr;
    }
template<class Type>
BiDirectionalNode<Type>::BiDirectionalNode(Type data,
	BiDirectionalNode<Type> * previous, BiDirectionalNode<Type> * next) :Node<Type>::
	Node(data, next)
    {
    this->prevPointer = prevPointer;
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
#endif /* MODEL_BIDIRECTIONALNODE_HPP_ */
