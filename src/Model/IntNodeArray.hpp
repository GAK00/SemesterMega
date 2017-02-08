/*
 * IntNodeArray.hpp
 *
 *  Created on: Feb 8, 2017
 *      Author: gkun9931
 */

#ifndef MODEL_INTNODEARRAY_HPP_
#define MODEL_INTNODEARRAY_HPP_
#include "IntNode.hpp"
class IntNodeArray
    {
private:
    IntNode* head;
    int size;
public:
    IntNodeArray(int bigness);
    int getSize();
    int getFromIndex(int index);
    void setAtIndex(int index, int value );
    };

#endif /* MODEL_INTNODEARRAY_HPP_ */
