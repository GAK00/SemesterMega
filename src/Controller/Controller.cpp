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
#include "../Model/Array.hpp"
using namespace std;

Controller::Controller()
    {
    //temp = Array<string>(1);
    }
void Controller::testArray()
    {
    cout << "Creating an NodeArray" << endl;
    Array<string> temp = Array<string>(100001);
    cout << "populating NodeArray" << endl;

    stringstream ss;
    for (int spot = 0; spot < temp.getSize(); spot++)
	{
	if ((spot % 1000) == 0)
	    {
	    cout << "at spot" << spot << endl;
	    }
	ss << "string No. " << spot;
	string str = ss.str();
	temp.setAtIndex(spot, str);
	ss.str("");
	}
    cout << "printing NodeArray" << endl;

    for (int spot = 0; spot < temp.getSize(); spot++)
	{

	if ((spot % 100) == 0)
	    {
	    cout << temp.getFromIndex(spot) << " is at " << spot << endl;
	    }
	}
    }
void Controller::testAdvancedFeatures()
    {
    int showDestructor = 0;
    if (showDestructor < 1)
	{
	Array<string> word = Array<string>(5);
	cout << "There should be messages about destructor next" << endl;
	}
    Array<string> word = Array<string>(4);
    word.setAtIndex(0, "at zero");
    word.setAtIndex(3, "in the last spot");
    Array<string> copiedWords = Array<string>(word);
    cout << "These should match:" << endl;
    cout << word.getFromIndex(0) << " should be the same as "
	    << copiedWords.getFromIndex(0) << endl;
    copiedWords.setAtIndex(3, "Changed the contents of the copied Array");
    cout << "These will not match" << endl;
    cout << word.getFromIndex(3) << " Should be different than "
	    << copiedWords.getFromIndex(3) << endl;
    }
void Controller::start()
    {
    Timer timer = Timer();
    cout << "Going to test the Advanced features" << endl;
    timer.startTimer();
    testAdvancedFeatures();

    cout << "Finished AdvancedFeatur testing in" << endl;
    timer.stopTimer();
    timer.displayTimerInformation();
    timer.resetTimer();
    cout << "Going to test the NodeArray" << endl;
    timer.startTimer();
    testArray();
    timer.stopTimer();
    timer.displayTimerInformation();
    cout << "Finished ArrayNode testing in" << endl;
    timer.displayTimerInformation();
    }

