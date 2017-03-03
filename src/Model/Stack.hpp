/*
 * Stack
 *
 *  Created on: Mar 1, 2017
 *      Author: gkun9931
 */

#ifndef MODEL_STACK_
#define MODEL_STACK_
#include "DoubleList.hpp"
#include <cstddef>
template<class Type>
class Stack: DoubleList<Type>
    {
private:
public:
    Stack();
    ~Stack();
    void add(Type value);
    Type remove(int index);
    Type pop();
    Type peek();
    void push(Type value);
    };

/*
 the add method only adds to the end
 */
template<class Type>
void Stack<Type>::add(Type value)
    {
    push(valueToAdd);
    }
template<class Type>
void Stack<Type>::push(Type value)
    {
    if (size == 0||this->front==nullptr||this->end == nullptr)
	{
	front = new BiDirectionalNode(value);
	end = front;
	}
    else
	{
	BiDirectionalNode * toAdd = new BiDirectionalNode(value, nullptr, end);
	end->setNextPointer(toAdd);
	end = toAdd;
	}
    size++;
    }

#endif /* MODEL_STACK_ */
