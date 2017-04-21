/*
 * AvlTree.hpp
 *
 *  Created on: Apr 19, 2017
 *      Author: gkun9931
 */

#ifndef MODEL_AVLTREE_HPP_
#define MODEL_AVLTREE_HPP_
#include "BinarySearchTree.hpp"
template<class Type>
class AvlTree: public BinarySearchTree<Type>
    {
private:
    BinarySearchTreeNode<Type> * LR(BinarySearchTreeNode<Type> *root);
    BinarySearchTreeNode<Type> * RR(BinarySearchTreeNode<Type>* root);
    BinarySearchTreeNode<Type> * LRR(BinarySearchTreeNode<Type> *root);
    BinarySearchTreeNode<Type> * RLR(BinarySearchTreeNode<Type> *root);
    BinarySearchTreeNode<Type> * insertNode(BinarySearchTreeNode<Type> *root, Type itemToInsert);
    BinarySearchTreeNode<Type> * remove(BinarySearchTreeNode<Type> *root, Type value);
    BinarySearchTreeNode<Type> * Balance();
    int heightDifference(BinarySearchTreeNode<Type>* root);
    BinarySearchTreeNode<Type> * balanceSubTree(BinarySearchTeeNode<Type> root);
public:
    AvlTree();
    ~AvlTree();
    void insert(Type itemToInsert);
    void remove(Type value);
    };
template<class Type>
AvlTree<Type> :: AvlTree() : BinarySearchTree <Type>()
    {
    }
template<class Type>
AvlTree<Type> :: ~AvlTree()
    {
    delete this->getRoot();
    }
template<class Type>
int AvlTree<Type>::heightDifference(BinarySearchTreeNode<Type> * node)
    {
    int balance;
    int leftHeight = calculateHeight(node->getLeftChild());
    int rightHeight = calculateHeight(node->getRightChild());
    balance = leftHeight - rightHeight;
    return balance;
    }
template<class Type>
BinarySearchTreeNode<Type> * AvlTree<Type>::LR(BinarySearchTreeNode<Type> * root)
    {
    BinarySearchTreeNode<Type> * changedNode;
    changedNode = root->getLeftChild();
    root->setLeftChild(changedNode->getRightChild());
    changedNode->getRightChild()->setRootPointer(root);
    changedNode->setRightChild(root);
    root->setRootPointer(changedNode);
    return changedNode;
    }
template<class Type>
BinarySearchTreeNode<Type> * AvlTree<Type>::RR(BinarySearchTreeNode<Type> * root)
    {
    binarySearchTreeNode<Type> changedNode;
    changedNode = root->getRightChild();
    root->setRightChild(changedNode->getLeftChild());
    changedNode->getLeftChild()->setRootPointer(root);
    changedNode->setLeftChild(root);
    root->setRootPoitner(changedNode);
    }
template<class Type>
BinarySearchTreeNode<Type>* AvlTree<Type>::RLR(BinarySearchTreeNode<Type> * root)
    {
    BinarySearchTreeNode<Type> * changedNode;
    changedNode = parnent->getRightChild();
    root->setRightChild(LR(changedNode));
    root->getRightChild()->setRootPointer(root);
    BinarySearchTreeNode<Type> * elderRoot;
    elderRoot = root->getRootPointer();
    BinarySearchTreeNode<Type> * right = rightRotation(root);
    right->setRootPointer(elderRoot);
    return right;
    }
template<class Type>
BinarySearchTreeNode<Type>* AvlTree<Type>::lRR(BinarySearchTreeNode<Type> * root)
    {
    BinarySearchTreeNode<Type> * changedNode;
    changedNode = parnent->getLeftChild();
    root->setLeftChild(LR(changedNode));
    root->getLeftChild()->setRootPointer(root);
    BinarySearchTreeNode<Type> * elderRoot;
    elderRoot = root->getRootPointer();
    BinarySearchTreeNode<Type> * left = leftRotation(root);
    left->setRootPointer(elderRoot);
    return right;
    }
template<class Type>
BinarySearchTreeNode<Type> * balanceSubTree(BinarySearchTreeNode<Type> * root)
    {
    int balanceFactor = heightDifference(root);
    if (balanceFactor > 1)
	{
	BinarySearchTreeNode<Type> * elderRoot = root->getRootPointer();
	if (heightDifference(root->getLeftChild()) > 0)
	    {
	    root = LR(root);
	    root->setRootPointer(elderRoot);
	    }
	else
	    {
	    root = LRR(root);
	    root->setRootPointer(elderRoot);
	    }
	}
    else if(balanceFactor < -1)
	{

	BinarySearchTreeNode<Type> * elderRoot = root->getRootPointer();
	if(heightDifference(root->getRightChild())>0)
	    {
		root = RLR(root);
		root->setRootPointer(elderRoot);
	    }
	else
	    {
		root = RR(root);
		root->setRootPointer(elderRoot);	    }

	}
    return nullptr;
    }
template <class Type>
BinarySearchTreeNode<Type> * AvlTree<Type> :: insertNode(BinarySearchTreeNode<Type> * root, Type inserted)
    {
	if(root == nullptr)
	    {
	    root = new BinarySearchTreeNode<Type>(inserted);
	    return root;
	    }
	else if(inserted < root-> getNodeData())
	    {
		root->setLeftChild(insertNode(root->getLeftChild(), inserted));
		root->getLeftChild()->setRootPointer(root);
		root = balanceSubTree(root);
	    }
	else if(inserted > root->getNodeData())
	    {
	    root -> setRightChild(insertNode(root->getRightChild(), inserted));
	    root -> getRightChild() -> setRootPointer(root);
	    root = balanceSubTree(root);
	    }
	return root;
    }
template <class Type>
void AvlTree<Type> :: insert(Type item)
    {
    insertNode(this->getRoot(), item);
    }

#endif /* MODEL_AVLTREE_HPP_ */
