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
    Node<Type>* nodePointer;
public:
    Node<Type>();
    Node<Type>(Type data);
    Node<Type>(Type data, Node<Type> * nextPointer);
    Type getNodeData();
    Node<Type> * getNodePointer();
    void setNodeData(Type value);
    void setNodePointer(Node<Type>* nexPointer);
    };


/*
 Implementation goes here
 */
template<class Type>
Node<Type> :: Node()
    {
    nodePointer = nullptr;
    //node data not initialized because of unknown type
    }
template<class Type>
Node<Type>::Node(Type data)
    {
    nodeData = data;
    nodePointer = nullptr;
    }
template<class Type>
Node<Type>::Node(Type data, Node<Type>* pointer)
    {
    nodeData = data;
    nodePointer = pointer;
    }
template<class Type>
Type Node<Type>::getNodeData()
    {
    return nodeData;
    }
template<class Type>
Node<Type> * Node<Type>::getNodePointer()
    {
    return nodePointer;
    }
#endif /* MODEL_NODE_HPP_ */
