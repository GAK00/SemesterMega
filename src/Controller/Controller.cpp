/*
 * Controller.cpp
 *
 *  Created on: Feb 6, 2017
 *      Author: gkun9931
 */
#include "Controller.hpp"
#include <iostream>
#include "../Model/IntNodeArray.hpp"
#include "../Model/Node.hpp"
using namespace std;

Controller::Controller()
    {

    stringNode = Node<string>("Derpy");
    intNode = Node<int>(42);
    }
void Controller::testIntArray()
    {
    cout << "Creating an IntNodeArray" << endl;
    IntNodeArray temp = IntNodeArray(101);
    for (int spot = 0; spot < 101; spot++)
	{
	temp.setAtIndex(spot, spot*5);
	}
    for (int spot = 0; spot < temp.getSize(); spot++)
	{
	cout << temp.getFromIndex(spot) << " is at " << spot << endl;
	}
    cout<<intNode.getNodeData()<<stringNode.getNodeData()<<endl;
    }
void Controller::start()
    {
    cout << "Going to test the IntNodeArray" << endl;
    testIntArray();
    cout << "Finished IntArrayNode testing" << endl;
    }

