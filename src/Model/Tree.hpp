/*
 * Tree.hpp
 *
 *  Created on: Apr 11, 2017
 *      Author: gkun9931
 */

#ifndef MODEL_TREE_HPP_
#define MODEL_TREE_HPP_
template<class Type>
class Tree
    {
private:
public:
    virtual int getSize() =0;
    virtual int getHeight() =0;
    virtual bool isComplete() =0;
    virtual bool isBalanced() = 0;
    virtual void inOrderTraversal() = 0;
    virtual void preOrderTraversal() = 0;
    virtual void postOrderTraversal() = 0;
    virtual bool contains(Type value) = 0;
    virtual void insert(Type toInsert) = 0;
    virtual void remove(Type toRemove) = 0;
    };

#endif /* MODEL_TREE_HPP_ */
