/*
 * Controller.cpp
 *
 *  Created on: Feb 6, 2017
 *      Author: gkun9931
 */
#include "Controller.hpp"
#include <iostream>
#include "../Model/IntNodeArray.hpp"
using namespace std;

Controller::Controller()
    {
    }
void Controller::testIntArray()
    {
    cout << "Creating an IntNodeArray" << endl;
    IntNodeArray temp = IntNodeArray(101);
    for (int spot = 0; spot < 101; spot++)
	{
	temp.setAtIndex(spot, spot*5);
	}
    for (int spot = 0; spot < 101; spot++)
	{
	cout << temp.getFromIndex(spot) << " is at " << spot << endl;
	}
    }
void Controller::start()
    {
    cout << "Going to test the IntNodeArray" << endl;
    testIntArray();
    cout << "Finished IntArrayNode testing" << endl;
    }

