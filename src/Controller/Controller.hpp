/*
 * Controller.hpp
 *
 *  Created on: Feb 6, 2017
 *      Author: gkun9931
 */

#ifndef SEMESTERMEGA_CONTROLLER_CONTROLLER_HPP_
#define SEMESTERMEGA_CONTROLLER_CONTROLLER_HPP_
#include "../model/Node.hpp"
#include<string>
using namespace std;
class Controller
    {
private:
    Node<string> stringNode;
    Node<int> intNode;
    void testIntArray();
public:
    Controller();
    void start();
    };




#endif /* SEMESTERMEGA_CONTROLLER_CONTROLLER_HPP_ */
