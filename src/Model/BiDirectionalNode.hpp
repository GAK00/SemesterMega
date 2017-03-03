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
    biDirectionalNode<Type> * prevPointer;
public:
    BiDirectionalNode();
    BiDirectionalNode(Type data);
    BiDirectionalNode(Type data, BiDirectionalNode<Type>*previous,
	    BiDirectionalNode<Type> * next);
    Type getNodeData();
    BiDirectionalNode<Type> * getNextPointer();
    BiDirectionalNode<Type> * getPreviousPointer();
    void setNodeData(Type data);
    void setNextPointer(BiDirectionalNode<Type> * nextPointer);
    void setPreviousPointer(BiDirectionalNode<Type> * prevPointer);
    };

//Implementation
template<class Type>
BiDirectionalNode<Type> :: BiDirectionalNode() : Node()
    {
    prevPointer = nullptr;
    }
template<class Type>
BiDirectionalNode<Type> :: BiDirectionalNode(Type data) : Node(data)
    {

	prevPointer = nullptr;
    }
template<class Type>
BiDirectionalNode<Type> :: BiDirectionalNode(Type data,BiDirectionalNode<Type> * previous,BiDirectionalNode<Type> * next) : Node(data, next)
    {
    this->prevPointer = prevPointer;
    }
template<class Type>
Type BiDirectionalNode<Type> ::getNodeData() : Node<Type>::getNodeData()
    {
    return Node<Type>::getNodeData();
    }
template<class Type>
BiDirectionalNode<Type> * BiDirectionalNode<Type> :: getNextPointer() : Node<Type>::getNodePointer()
    {
	return Node<Type>::getNodePointer();
    }
#endif /* MODEL_BIDIRECTIONALNODE_HPP_ */
