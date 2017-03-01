/*
 * DoubleList.hpp
 *
 *  Created on: Mar 1, 2017
 *      Author: gkun9931
 */

#ifndef MODEL_DOUBLELIST_HPP_
#define MODEL_DOUBLELIST_HPP_

template<class Type>
class DoubleList
    {
private:
    BiDirectionalNode<Type> * front;
    BiDirectionalNode<Type> * end;
    int size;
public:
    virtual void add(Type value) = 0;
    virtual void remove(int index) = 0;
    virtual DoubleList();
    virtual ~DoubleList() = 0;
    int getSize() const;
    BiDirectionalNode<Type> * getFront() const;
    BiDirectionalNode<Type> * getEnd() const;

    };

//cpp point
template<class Type>
DoubleList<Type>::DoubleList()
    {
    size = 0;
    front = nullptr;
    end = nullptr;
    }
template<class Type>
BiDirectionalNode<Type> * DoubleList<Type>::getEnd() const
    {
    return end;
    }
template<class Type>
BiDirectionalNode<Type> * DoubleList<Type>::getFront() const
    {
    return front;
    }
template<class Type>
int DoubleList<Type>::getSize() const
    {
    return size;
    }
#endif /* MODEL_DOUBLELIST_HPP_ */
