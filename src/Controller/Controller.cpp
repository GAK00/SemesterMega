/*
 * Controller.cpp
 *
 *  Created on: Feb 6, 2017
 *      Author: gkun9931
 */
#include "Controller.hpp"
#include <iostream>
#include "../Model/Array.hpp"
#include "../Model/Node.hpp"
using namespace std;

Controller::Controller()
    {
    }
void Controller::testIntArray()
    {
    cout << "Creating an IntNodeArray" << endl;
    Array<int> temp = Array<int>(101);
    for (int spot = 0; spot < 101; spot++)
	{
	temp.setAtIndex(spot, spot*5);
	}
    for (int spot = 0; spot < temp.getSize(); spot++)
	{
	cout << temp.getFromIndex(spot) << " is at " << spot << endl;
	}
    }
void Controller::start()
    {
    cout << "Going to test the NodeArray" << endl;
    testIntArray();
    cout << "Finished ArrayNode testing" << endl;
    }

