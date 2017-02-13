/*
 * IntNode.cpp
 *
 *  Created on: Feb 6, 2017
 *      Author: gkun9931
 */
#include <cstddef>
#include "IntNode.hpp"

IntNode::IntNode()
    {
    this->nodeData = -999;
    this->nodePointer = nullptr;
    }

IntNode::IntNode(int data)
    {
    this->nodeData = data;
    this->nodePointer = nullptr;
    }
IntNode::IntNode(int nodeData, IntNode * next)
    {
    this->nodeData = nodeData;
    this->nodePointer = next;
    }
int IntNode :: getNodeData()
    {
    return nodeData;
    }
IntNode* IntNode::getNodePointer()
    {
    return nodePointer;
    }
void IntNode:: setNodeData(int nodeData)
    {
    this->nodeData = nodeData;
    }
void IntNode:: setNodePointer(IntNode * nodePointer)
    {
    this->nodePointer = nodePointer;
    }

