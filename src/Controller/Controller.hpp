/*
 * Controller.hpp
 *
 *  Created on: Feb 6, 2017
 *      Author: gkun9931
 */

#ifndef SEMESTERMEGA_CONTROLLER_CONTROLLER_HPP_
#define SEMESTERMEGA_CONTROLLER_CONTROLLER_HPP_
#include "../model/Node.hpp"
#include "../model/Array.hpp"
#include<string>
using namespace std;
class Controller
    {
private:
    void testArray();
    void testAdvancedFeatures();
    void testList();
    Array<string> temp;
public:
    Controller();
    void start();
    };




#endif /* SEMESTERMEGA_CONTROLLER_CONTROLLER_HPP_ */
