/*
 * List.hpp
 *
 *  Created on: Feb 21, 2017
 *      Author: gkun9931
 */

#ifndef MODEL_LIST_HPP_
#define MODEL_LIST_HPP_
#include "Node.hpp"
template<class Type>
class List
    {
private:
    //dataMembers
    int size;
    Node<Type> * front;
public:
    //constructors
    List<Type>();
    List<Type>(const List<Type> & source);
    ~List<Type>();
    //methods
    void addAtIndex(int index, Type value);
    void add(Type value);
    Type remove(int index);
    Type setAtIndex(int index, Type value);
    Type getFromIndex(int index);
    bool contains(Type value);
    int getSize() const;
    Node<Type> getFront() const;
    };
//Implementation
#include <cstddef>
//constructors
template<class Type>
List<Type>::List()
    {
    size = 0;
    front = nullptr;
    }
template<class Type>
List<Type>::List(const List<Type> & source)
    {

    }
template<class Type>
List<Type>::~List()
    {

    }
//methods
template<class Type>
void List<Type>::addAtIndex(int index, Type value)
    {

    }
template<class Type>
void List<Type>::add(Type value)
    {

    }
template<class Type>
Type List<Type>::remove(int index)
    {

    }
template<class Type>
Type List<Type> ::setAtIndex(int index, Type value)
    {

    }
template<class Type>
Type List<Type>::getFromIndex(int index)
    {

    }
template<class Type>
bool List<Type>::contains(Type value)
    {

    }
template<class Type>
int List<Type>::getSize() const
    {

    }
template<class Type>
Node<Type> List<Type>::getFront() const
    {

    }

#endif /* MODEL_LIST_HPP_ */
