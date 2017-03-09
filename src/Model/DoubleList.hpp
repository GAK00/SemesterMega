/*
 * DoubleList.hpp
 *
 *  Created on: Mar 1, 2017
 *      Author: gkun9931
 */

#ifndef MODEL_DOUBLELIST_HPP_
#define MODEL_DOUBLELIST_HPP_
#include "BiDirectionalNode.hpp"
template<class Type>
class DoubleList
    {
private:
    BiDirectionalNode<Type> * front;
    BiDirectionalNode<Type> * end;
    int size;
public:
    virtual void add(Type value) = 0;
    virtual Type remove(int index) = 0;
    DoubleList();
    virtual ~DoubleList();

    int getSize() const;
    BiDirectionalNode<Type> * getFront() const;
    BiDirectionalNode<Type> * getEnd() const;
    void setFront(BiDirectionalNode<Type> * front);
    void setSize(int updated);
    void setEnd(BiDirectionalNode<Type> * end);
    };

template<class Type>
DoubleList<Type>::DoubleList()
    {
    this->size = 0;
    this->front = nullptr;
    this->end = nullptr;
    }

template<class Type>
DoubleList<Type>::~DoubleList()
    {
    //Implemented only to avoid errors.
    //Just like a Java interface method.
    }

template<class Type>
int DoubleList<Type>::getSize() const
    {
    return this->size;
    }

template<class Type>
BiDirectionalNode<Type> * DoubleList<Type>::getFront() const
    {
    return this->front;
    }

template<class Type>
BiDirectionalNode<Type> * DoubleList<Type>::getEnd() const
    {
    return this->end;
    }

template<class Type>
void DoubleList<Type>::setSize(int size)
    {
    this->size = size;
    }

template<class Type>
void DoubleList<Type>::setFront(BiDirectionalNode<Type> * front)
    {
    this->front = front;
    }

template<class Type>
void DoubleList<Type>::setEnd(BiDirectionalNode<Type> * end)
    {
    this->end = end;
    }
#endif /* MODEL_DOUBLELIST_HPP_ */
/*
 * add(Type data)
 * {
 * if(size == 0)
 * {
 * front = new BiDirectionalNode<Type>(data)
 * front.setNextPointer(front);
 * front.setLastPointer(front);
 * end = front;
 * }
 * else
 * {
 * BiDirectioinalNode * toAdd = newBiDirectionalNode(data,end,front);
 * end.setNextPointer(toAdd)
 * end = toAdd;
 * front.setLastPointer(end);
 * }
 * }
 */
