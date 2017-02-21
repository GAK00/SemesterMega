//
//  Timer.hpp
//  Project2
//
//  Created by Kunz, Geran on 1/31/17.
//  Copyright © 2017 Kunz, Geran. All rights reserved.
//

#ifndef Timer_hpp
#define Timer_hpp

#include <time.h>

class Timer
{
private:
    //Data members
    clock_t executionTime;
public:
    //Constructor
    Timer();
    //Mehtods
    void startTimer();
    void stopTimer();
    void resetTimer();
    void displayTimerInformation();
    long getExecutionTimeInMiliSeconds();
};

#endif /* Timer_hpp */
