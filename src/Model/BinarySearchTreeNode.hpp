/*
 * BinarySearchTreeNode.hpp
 *
 *  Created on: Apr 11, 2017
 *      Author: gkun9931
 */

#ifndef MODEL_BINARYSEARCHTREENODE_HPP_
#define MODEL_BINARYSEARCHTREENODE_HPP_
#include "Node.hpp"

template<class Type>
class BinarySearchTreeNode: public Node<Type>

    {
private:
    BinarySearchTreeNode<Type> * root;
    BinarySearchTreeNode<Type> * leftChild;
    BinarySearchTreeNode<Type> * rightChild;
public:
    BinarySearchTreeNode();
    ~BinarySearchTreeNode();
    BinarySearchTreeNode(Type data);
    BinarySearchTreeNode<Type> * getRootPointer();
    BinarySearchTreeNode<Type> * getLeftChild();
    BinarySearchTreeNode<Type> * getRightChild();

    void setRootPointer(BinarySearchTreeNode<Type> * root);
    void setLeftChild(BinarySearchTreeNode<Type> * left);
    void setRightChild(BinarySearchTreeNode<Type> * right);
    };

#include <cstddef>
template<class Type>
BinarySearchTreeNode<Type>::BinarySearchTreeNode()
    {
    this->setNodeData(nullptr);
    this->root = nullptr;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
    }
template<class Type>
BinarySearchTreeNode<Type> :: ~BinarySearchTreeNode()
    {
    delete leftChild;
    delete rightChild;
    }
template<class Type>
BinarySearchTreeNode<Type>::BinarySearchTreeNode(Type data) :
	Node<Type>(data)
    {
    this->root = nullptr;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
    }
template <class Type>
BinarySearchTreeNode<Type> * BinarySearchTreeNode<Type> :: getRootPointer()
    {
    return root;
    }
template <class Type>
BinarySearchTreeNode<Type> * BinarySearchTreeNode<Type> :: getLeftChild()
    {
    return leftChild;
    }
template<class Type>
BinarySearchTreeNode<Type> * BinarySearchTreeNode<Type> :: getRightChild()
    {
    return rightChild;
    }
template<class Type>
void BinarySearchTreeNode<Type> :: setRootPointer(BinarySearchTreeNode<Type> * root)
    {
	 this -> root = root;
    }
template <class Type>
void BinarySearchTreeNode<Type> :: setLeftChild(BinarySearchTreeNode<Type> * left)
    {
    this->leftChild = left;
    }
template <class Type>
void BinarySearchTreeNode<Type> :: setRightChild(BinarySearchTreeNode<Type> * right)
    {
    this->rightChild = right;
    }

#endif /* MODEL_BINARYSEARCHTREENODE_HPP_ */
