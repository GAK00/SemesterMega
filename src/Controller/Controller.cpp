/*
 * Controller.cpp
 *
 *  Created on: Feb 6, 2017
 *      Author: gkun9931
 */
#include "Controller.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include "../Model/Timer.hpp"
using namespace std;

Controller::Controller()
    {
    temp = Array<string>(1);
    }
void Controller::testIntArray()
    {
    cout << "Creating an NodeArray" << endl;
    temp = Array<string>(1000001);
    cout<<"populating NodeArray"<<endl;
    for (int spot = 0; spot < temp.getSize(); spot++)
	{
	if((spot%1000)==0)
	    {
	    cout<<"at spot"<<spot<<endl;
	    }
	stringstream ss;
	ss << "string No. "<< spot;
	string str = ss.str();
	temp.setAtIndex(spot, str);
	}
    cout<<"printing NodeArray"<<endl;
    for (int spot = 0; spot < temp.getSize(); spot++)
	{
	cout << temp.getFromIndex(spot) << " is at " << spot << endl;
	}
    }
void Controller::start()
    {
    Timer timer = Timer();
    cout << "Going to test the NodeArray" << endl;
    timer.startTimer();
    testIntArray();
    timer.stopTimer();
    cout << "Finished ArrayNode testing in" << endl;
    timer.displayTimerInformation();
    }

