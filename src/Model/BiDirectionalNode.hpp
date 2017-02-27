/*
 * BiDirectionalNode.hpp
 *
 *  Created on: Feb 27, 2017
 *      Author: gkun9931
 */

#ifndef MODEL_BIDIRECTIONALNODE_HPP_
#define MODEL_BIDIRECTIONALNODE_HPP_

template<class Type>
class BiDirectionalNode: public Node<Type>
    {
private:
    Type data;
    BiDirectionalNode<Type> * nextPointer;
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
    data = nullptr;
    nextPointer = nullptr;
    prevPointer = nullptr;
    }
template<class Type>
BiDirectionalNode<Type> :: BiDirectionalNode(Type data) : Node(data)
    {

    }
template<class Type>
BiDirectionalNode<Type> :: BiDirectionalNode(Type data, BiDirectioinalNode<Type>* previous,BiDirectioninalNode<Type> *next) : Node(data,nextPointer)
    {

    }

#endif /* MODEL_BIDIRECTIONALNODE_HPP_ */
