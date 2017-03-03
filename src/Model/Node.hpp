/*
 * Node.hpp
 *
 *  Created on: Feb 13, 2017
 *      Author: gkun9931
 */

#ifndef MODEL_NODE_HPP_
#define MODEL_NODE_HPP_
#include<cstddef>
template<class Type>
class Node
    {
private:
    Type nodeData;
    Node<Type>* nextPointer;
public:
    Node<Type>();
    Node<Type>(Type data);
    Node<Type>(Type data, Node<Type> * nextPointer);
    Type getNodeData();
    Node<Type> * getNextPointer();
    void setNodeData(Type value);
    void setNextPointer(Node<Type>* nexPointer);
    };


/*
 Implementation goes here
 */
template<class Type>
Node<Type> :: Node()
    {
    nextPointer = nullptr;
    //node data not initialized because of unknown type
    }
template<class Type>
Node<Type>::Node(Type data)
    {
    nodeData = data;
    nextPointer = nullptr;
    }
template<class Type>
Node<Type>::Node(Type data, Node<Type>* pointer)
    {
    nodeData = data;
    nextPointer = pointer;
    }
template<class Type>
Type Node<Type>::getNodeData()
    {
    return nodeData;
    }
template<class Type>
Node<Type> * Node<Type>::getNextPointer()
    {
    return nextPointer;
    }
template<class Type>
void Node<Type>:: setNodeData(Type value)
    {
    nodeData = value;
    }
template<class Type>
void Node<Type>::setNextPointer(Node<Type> * nextPointer)
    {
    this->nextPointer=nextPointer;
    }
#endif /* MODEL_NODE_HPP_ */
