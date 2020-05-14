/**********************************************************************************
** Program name: Zoo Tycoon
** Author:       Kais Saradi
** Date:         04/30/2019
** Description:  This document contains the member functions for the turtle class,
** which is a child class of the animal class. It contains a constructor for
** creating a new turtle object.
***********************************************************************************/
#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "animal.hpp"
#include "turtle.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;

/*********************************************************************************
 *      Turtle constructor which initializes an animal object with an overloaded
 *                                  contructor
 * *******************************************************************************/
turtle::turtle() : animal() {}

turtle::turtle(int age, double cost, int numberofBabies, double baseFoodCost, double payoff)
: animal(age, cost, numberofBabies, baseFoodCost, payoff) {}