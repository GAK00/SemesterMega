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
private:
    BinarySearchTreeNode<Type> * root;
    int calculateSize(BinarySearchTreeNode<Type> * start);
    void inOrderTraversal(BinarySearchTreeNode<Type> * root);
    void preOrderTraversal(BinarySearchTreeNode<Type> * root);
    void postOrderTraversal(BinarySearchTreeNode<Type> * root);
public:
    BinarySearchTree();
    ~BinarySearchTree();
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
    BinarySearchTreeNode<Type> * getRoot();
    void setRoot(BinarySearchTreeNode<Type> * root);
    void printToFile();
    };
template<class Type>
BinarySearchTree<Type>::BinarySearchTree() :
	Tree<Type>()
    {
    root = nullptr;
    }
template<class Type>
BinarySearchTree<Type>::~BinarySearchTree()
    {

    }
template<class Type>
void BinarySearchTree<Type>::printToFile()
    {

    }
template<class Type>
void BinarySearchTree<Type>::inOrderTraversal()
    {

    }
template<class Type>
void BinarySearchTree<Type>::preOrderTraversal()
    {

    }
template<class Type>
void BinarySearchTree<Type>::postOrderTraversal()
    {

    }
template<class Type>
void BinarySearchTree<Type>::inOrderTraversal(BinarySearchTreeNode<Type> * root)
    {

    }
template<class Type>
void BinarySearchTree<Type>::preOrderTraversal(BinarySearchTreeNode<Type> * root)
    {

    }
template<class Type>
void BinarySearchTree<Type>::postOrderTraversal(BinarySearchTreeNode<Type> * root)
    {

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

    }

#endif /* MODEL_BINARYSEARCHTREE_HPP_ */
