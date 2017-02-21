//
//  Timer.cpp
//  Project2
//
//  Created by Kunz, Geran on 1/31/17.
//  Copyright © 2017 Kunz, Geran. All rights reserved.
//

#include "Timer.hpp"
#include <iostream>;

using namespace std;

Timer :: Timer()
{
    executionTime = 0;
}

void Timer :: resetTimer()
{
    executionTime = 0;
}

void Timer :: startTimer()
{
    executionTime = clock();
}

void Timer :: stopTimer()
{
    executionTime = clock()-executionTime;
}

void Timer :: displayTimerInformation()
{
    cout << "The execlution time is: "<< executionTime <<endl;
    cout << "In human time it is: " << double(executionTime)/CLOCKS_PER_SEC<<" seconds"<< endl;
}

long Timer :: getExecutionTimeInMiliSeconds()
{
    return executionTime;
}
