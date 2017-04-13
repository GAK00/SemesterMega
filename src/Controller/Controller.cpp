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
#include<cstddef>
#include "../Model/Timer.hpp"
#include "../Model/List.hpp"
#include"../Model/Stack.hpp"
#include"../Model/Queue.hpp"
#include "../Model/FastList.hpp"
#include "../Model/Meme.hpp"
#include "../Model/BinarySearchTree.hpp"
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
    cout << word.getFromIndex(0) << " should be the same as " << copiedWords.getFromIndex(0) << endl;
    copiedWords.setAtIndex(3, "Changed the contents of the copied Array");
    cout << "These will not match" << endl;
    cout << word.getFromIndex(3) << " Should be different than " << copiedWords.getFromIndex(3) << endl;
    }
void Controller::testList()
    {
    cout << "start" << endl;
    List<int> list = List<int>();
    list.add(1);
    list.add(2);
    list.add(3);
    list.remove(1);
    list.addAtIndex(1, 5);
    list.setAtIndex(2, 2);
    list.addFront(22);\
    for (int index = 0; index < list.getSize(); index++)
	{
	cout << list.getFromIndex(index) << endl;
	}
    cout << list.getSize() << endl;
    cout << "end" << endl;

    }
void Controller::testListTiming()
    {
    int listSize = 10000000;
    int weight = 99;
    int dataCollection = 500;
    int masterLoop = 100;
    double MavgSlow = 0;
    double MavgFast = 0;
    for (int Mindex = 0; Mindex < masterLoop; Mindex++)
	{
	FastList<int> timingList;
	for (int index = 0; index < listSize; index++)
	    {
	    timingList.add(rand());
	    }
	long slowTime[dataCollection];
	long fastTime[dataCollection];
	double avgSlow = 0;
	double avgFast = 0;
	Timer fastTimer;
	for (int index = 0; index < dataCollection; index++)
	    {
	    int randomIndex = (rand() % (listSize * (100-weight) / 100)) + (listSize * (weight)) / 100;
	    fastTimer.startTimer();
	    timingList.getFromIndex(randomIndex);
	    fastTimer.stopTimer();
	    slowTime[index] = fastTimer.getExecutionTimeInMiliSeconds();
	    fastTimer.resetTimer();

	    fastTimer.startTimer();
	    timingList.getFromIndexFast(randomIndex);
	    fastTimer.stopTimer();
	    fastTime[index] = fastTimer.getExecutionTimeInMiliSeconds();
	    fastTimer.resetTimer();
	    avgSlow += slowTime[index];
	    avgFast += fastTime[index];
	    }
	avgSlow = avgSlow / dataCollection;
	avgFast = avgFast / dataCollection;
	MavgSlow += avgSlow;
	MavgFast += avgFast;
	if (Mindex % 10 == 0)
	    {
	    cout << "The average speed for the slow method was: " << avgSlow << " microSeconds" << endl;
	    cout << "The average speed for the fast method was: " << avgFast << " microseconds" << endl;
	    cout << "A time savings of: " << avgSlow - avgFast << " microSeconds." << endl;
	    cout << endl;
	    }
	}
    for (int index = 0; index < 5; index++)
	{
	cout << endl;
	}
    MavgSlow = MavgSlow / masterLoop;
    MavgFast = MavgFast / masterLoop;
    cout << "final master slow avg was: " << MavgSlow << endl;
    cout << "final master fast avg was: " << MavgFast << endl;
    cout << "final master time savings was: " << MavgSlow - MavgFast << endl;
    }
void Controller::testNumberStack()
    {
    Stack<int> stack;
    for (int index = 0; index < 100; index++)
	{
	cout << index << endl;
	cout << "size: " << stack.getSize() << endl;
	stack.push(index);
	}
    stack.add(100);
    for (int index = 0; index < 100; index++)
	{
	cout << "size: " << stack.getSize() << endl;
	cout << stack.pop() << endl;
	cout<< "next" << stack.peek()<< endl;
	}
    stack.remove(100);
    cout << "end" << endl;
    }
void Controller::testMemeQueue()
    {
    Meme firstMeme("doggo");
    Queue<Meme> memeQueue;
    cout<<"queueing " <<firstMeme.getTitle()<<endl;
    memeQueue.add(firstMeme);
    Meme secondMeme("doggo on fire");
    secondMeme.setDankness(9001);
    cout<<"queueing " <<secondMeme.getTitle()<<endl;
    memeQueue.enqueue(secondMeme);
    cout<<"reading queue"<<endl;
    int size = memeQueue.getSize();
    for(int index = 0; index<size; index++)
	{
	Meme meme = memeQueue.dequeue();
	cout<< meme.getTitle() <<" dankness level " << meme.getDankness()<<endl;
	}
    }
void Controller::testBSTree()
    {
    BinarySearchTree<int> toTest;
    toTest.insert(3);
    toTest.insert(1);
    toTest.insert(0);
    toTest.insert(2);
    toTest.insert(4);
    toTest.insert(5);
    //toTest.remove(3);
    toTest.postOrderTraversal();
    }
void Controller::start()
    {
//Timer timer = Timer();
//cout << "Going to test the Advanced features" << endl;
//timer.startTimer();
//testAdvancedFeatures();
//
//cout << "Finished AdvancedFeatur testing in" << endl;
//timer.stopTimer();
//timer.displayTimerInformation();
//timer.resetTimer();
//cout << "Going to test the NodeArray" << endl;
//timer.startTimer();
//testArray();
//timer.stopTimer();
//timer.displayTimerInformation();
//cout << "Finished ArrayNode testing in" << endl;
//timer.displayTimerInformation();
//testList();
// testListTiming();
//  testStack();
   // testMemeQueue();
    testBSTree();
    }

