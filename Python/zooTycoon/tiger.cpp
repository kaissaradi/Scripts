/**********************************************************************************
** Program name: Zoo Tycoon
** Author:       Kais Saradi
** Date:         04/30/2019
** Description:  This document contains the member functions for the tiger class,
** which is a child class of the animal class. It contains a constructor for
** creating a new tiger object.
***********************************************************************************/
#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "animal.hpp"
#include "tiger.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;

/*********************************************************************************
 *      Tiger constructor which initializes an animal object with an overloaded
 *                                  contructor
 * *******************************************************************************/
tiger::tiger() : animal() {}

tiger::tiger(int age, double cost, int numberofBabies, double baseFoodCost, double payoff)
: animal(age, cost, numberofBabies, baseFoodCost, payoff) {}