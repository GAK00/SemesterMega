/*
 * BinarySearchTree.hpp
 *
 *  Created on: Apr 11, 2017
 *      Author: gkun9931
 */

#ifndef MODEL_BINARYSEARCHTREE_HPP_
#define MODEL_BINARYSEARCHTREE_HPP_

#include "BinarySearchTreeNode.hpp"
#include "Tree.hpp"

template<class Type>
class BinarySearchTree: public Tree<Type>
    {
protected:
    BinarySearchTreeNode<Type> * root;
    int calculateSize(BinarySearchTreeNode<Type> * start);
    int calculateHeight(BinarySearchTreeNode<Type> * start);
    bool isBalanced(BinarySearchTreeNode<Type> * start);
    void inOrderTraversal(BinarySearchTreeNode<Type> * root);
    void preOrderTraversal(BinarySearchTreeNode<Type> * root);
    void postOrderTraversal(BinarySearchTreeNode<Type> * root);
    void removeNode(BinarySearchTreeNode<Type> * &node);
    bool isComplete(BinarySearchTreeNode<Type> * root, int index, int size);
public:
    BinarySearchTree();
    ~BinarySearchTree();
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
    Type findMinimum();
    Type findMaximum();
    BinarySearchTreeNode<Type> * getRoot();
    void setRoot(BinarySearchTreeNode<Type> * root);
    void insert(Type value);
    bool contains(Type value);
    void remove(Type value);
    int getSize();
    int getHeight();
    bool isComplete();
    bool isBalanced();
    };

#include<cstddef>
#include<iostream>
#include <algorithm>
#include <limits>
using namespace std;
template<class Type>
BinarySearchTree<Type>::BinarySearchTree() :
	Tree<Type>()
    {
    root = nullptr;
    }
template<class Type>
BinarySearchTree<Type>::~BinarySearchTree()
    {
    delete root;
    }
template<class Type>
void BinarySearchTree<Type>::inOrderTraversal()
    {
    inOrderTraversal(root);
    }
template<class Type>
void BinarySearchTree<Type>::preOrderTraversal()
    {
    preOrderTraversal(root);
    }
template<class Type>
void BinarySearchTree<Type>::postOrderTraversal()
    {
    postOrderTraversal(root);
    }
template<class Type>
void BinarySearchTree<Type>::inOrderTraversal(BinarySearchTreeNode<Type> * root)
    {
    if (root != nullptr)
	{
	inOrderTraversal(root->getLeftChild());
	cout << "Node Contents: " << root->getNodeData() << endl;
	inOrderTraversal(root->getRightChild());
	}
    }
template<class Type>
void BinarySearchTree<Type>::preOrderTraversal(BinarySearchTreeNode<Type> * root)
    {
    if (root != nullptr)
	{
	cout << "Node Contents: " << root->getNodeData() << endl;
	preOrderTraversal(root->getLeftChild());
	preOrderTraversal(root->getRightChild());
	}
    }
template<class Type>
void BinarySearchTree<Type>::postOrderTraversal(BinarySearchTreeNode<Type> * root)
    {

    if (root != nullptr)
	{
	postOrderTraversal(root->getLeftChild());
	postOrderTraversal(root->getRightChild());
	cout << "Node Contents: " << root->getNodeData() << endl;
	}
    }
template<class Type>
BinarySearchTreeNode<Type> * BinarySearchTree<Type>::getRoot()
    {
    return root;
    }
template<class Type>
void BinarySearchTree<Type>::setRoot(BinarySearchTreeNode<Type> * root)
    {
    this->root = root;
    }
template<class Type>
int BinarySearchTree<Type>::calculateSize(BinarySearchTreeNode<Type> * start)
    {
    int size = 1;
    if (start == nullptr)
	{
	return 0;
	}
    else
	{
	size += calculateSize(start->getLeftChild());
	size += calculateSize(start->getRightChild());
	}
    return size;
    }
template<class Type>
int BinarySearchTree<Type>::calculateHeight(BinarySearchTreeNode<Type> * start)
    {
    if (start == nullptr)
	{
	return 0;
	}
    else
	{
	return 1 + (max(calculateHeight(start->getLeftChild()), calculateHeight(start->getRightChild())));
	}
    }
template<class Type>
bool BinarySearchTree<Type>::isBalanced(BinarySearchTreeNode<Type> * start)
    {
    if (start == nullptr)
	{
	return true;
	}
    int dif = abs(calculateHeight(start->getLeftChild()) - calculateHeight(start->getRightChild()));
    if (dif <= 1 && isBalanced(start->getLeftChild()) && isBalanced(start->getRightChild()))
	{
	return true;
	}
    return false;
    }
template<class Type>
bool BinarySearchTree<Type>::isComplete(BinarySearchTreeNode<Type> * start, int size, int index)
    {

    if (start == nullptr)
	{
	return true;
	}
    if (index >= size)
	{
	return false;
	}
    return (isComplete(start->getLeftChild(), 2 * index + 1, size) && isComplete(start->getRightChild(), 2 * index + 2, size));
    }
template<class Type>
void BinarySearchTree<Type>::insert(Type value)
    {
    cout << "adding " << value << endl;
    if (root == nullptr)
	{
	root = new BinarySearchTreeNode<Type>(value);
	}
    else
	{
	BinarySearchTreeNode<Type> * current = nullptr;
	BinarySearchTreeNode<Type> * child = root;
	while (child != nullptr)
	    {
	    current = child;
	    if (value < child->getNodeData())
		{
		child = child->getLeftChild();
		}
	    else if (value > child->getNodeData())
		{
		child = child->getRightChild();
		}
	    else
		{
		cerr << "Item is already in list don't be stupid stupid" << endl;
		return;
		}
	    }
	if (current->getNodeData() > value)
	    {
	    current->setLeftChild(new BinarySearchTreeNode<Type>(value));
	    current->getLeftChild()->setRootPointer(current);
	    }
	else
	    {
	    current->setRightChild(new BinarySearchTreeNode<Type>(value));
	    current->getRightChild()->setRootPointer(current);
	    }

	}

    }
template<class Type>
void BinarySearchTree<Type>::remove(Type value)
    {
    if (root == nullptr)
	{
	cerr << "There is nothing here don't be stupid stupid" << endl;
	}
    else
	{
	BinarySearchTreeNode<Type> * current = root;
	while (current != nullptr)
	    {
	    if (current->getNodeData() < value)
		{
		current = current->getRightChild();
		}
	    else if (current->getNodeData() > value)
		{
		current = current->getLeftChild();
		}
	    else
		{
		removeNode(current);
		return;
		}
	    }
	}
    }
template<class Type>
void BinarySearchTree<Type>::removeNode(BinarySearchTreeNode<Type> * &node)
    {
    //if (node->getRootPointer() != nullptr && node->getRightChild() == nullptr)
    //{
    if (node->getRootPointer() == nullptr)
	{
	root = nullptr;
	}
    else
	{
	if (node->getRootPointer()->getNodeData() > node->getNodeData())
	    {
	    node->getRootPointer()->setLeftChild(nullptr);
	    }
	else
	    {
	    node->getRootPointer()->setRightChild(nullptr);
	    }
	}
    //}

    if ((node->getRightChild() == nullptr || node->getLeftChild() == nullptr))
	{
	BinarySearchTreeNode<Type> * notNull = node->getLeftChild();
	if (node->getLeftChild() == nullptr)
	    {
	    notNull = node->getRightChild();
	    }
	if (node->getRootPointer() == nullptr)
	    {
	    root = notNull;
	    }
	else
	    {
	    notNull->setRootPointer(node->getRootPointer());
	    if (node->getRootPointer()->getNodeData() > node->getNodeData())
		{
		node->getRootPointer()->setLeftChild(notNull);
		}
	    else
		{
		node->getRootPointer()->setRightChild(notNull);
		}
	    }
	}
    else
	{
	BinarySearchTreeNode<Type> * newRoot = root->getLeftChild();
	while (newRoot->getRightChild() != nullptr)
	    {
	    newRoot = newRoot->getRightChild();
	    }
	newRoot->getRootPointer()->setRightChild(nullptr);

	newRoot->setLeftChild(node->getLeftChild());
	newRoot->setRightChild(node->getRightChild());
	newRoot->setRootPointer(node->getRootPointer());
	if (newRoot->getRootPointer() == nullptr)
	    {
	    root = newRoot;
	    }
	}
    if (node == nullptr || node->getRootPointer() == nullptr)
	{
	root = node;
	}
    delete node;
    }
template<class Type>
bool BinarySearchTree<Type>::contains(Type value)
    {
    if (root == nullptr)
	{
	return false;
	}
    else
	{
	BinarySearchTreeNode<Type> * current = root;
	while (current != nullptr)
	    {
	    if (value < current->getNodeData())
		{
		current = current->getLeftChild();
		}
	    else if (value > current->getNodeData())
		{
		current = current->getRightChild();
		}
	    else
		{
		return true;
		}
	    }
	}
    return false;
    }
template<class Type>
int BinarySearchTree<Type>::getSize()
    {
    return calculateSize(root);
    }
template<class Type>
int BinarySearchTree<Type>::getHeight()
    {
    return calculateHeight(root);
    }
template<class Type>
bool BinarySearchTree<Type>::isComplete()
    {
    return isComplete(root, 0, getSize());
    }
template<class Type>
bool BinarySearchTree<Type>::isBalanced()
    {
    return isBalanced(root);
    }
template<class Type>
Type BinarySearchTree<Type> :: findMinimum()
{
    BinarySearchTreeNode<Type> * temp = root;
    while(temp ->getLeftChild()!= nullptr)
	{
	temp = temp->getLeftChild();
	}
    return temp->getNodeData();
}
template<class Type>
Type BinarySearchTree<Type> :: findMaximum()
    {
    BinarySearchTreeNode<Type> * temp = root;
    while(temp -> getRightChild()!=nullptr)
	{
	temp = temp->getRightChild();
	}
    return temp->getNodeData();
    }
#endif /* MODEL_BINARYSEARCHTREE_HPP_ */
