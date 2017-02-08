/*
 * IntNode.hpp
 *
 *  Created on: Feb 6, 2017
 *      Author: gkun9931
 */

#ifndef SEMESTERMEGA_MODEL_INTNODE_HPP_
#define SEMESTERMEGA_MODEL_INTNODE_HPP_

class IntNode
{
private:
	int nodeData;
	IntNode * nodePointer;
public:
	//constructors
	IntNode();
	IntNode(int nodeData);
	IntNode(int nodeData,IntNode * nodePointer);
	//methods
	int getNodeData();
	IntNode* getNodePointer();
	void setNodeData(int value);
	void setNodePointer(IntNode* updatedNode);
};



#endif /* SEMESTERMEGA_MODEL_INTNODE_HPP_ */

