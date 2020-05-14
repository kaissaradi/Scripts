/**********************************************************************************
** Program name: Zoo Tycoon
** Author:       Kais Saradi
** Date:         04/30/2019
** Description:  This header file contains the class declaration  for the turtle
** class, which is a child class of the animal class. It contains a constructor for
** creating a new turtle object.
***********************************************************************************/
#ifndef TURTLE_HPP
#define TURTLE_HPP
#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "animal.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;

class turtle : public animal
{
public:
    turtle();
    turtle(int age, double cost, int numberofBabies, double baseFoodCost, double payoff);
};

#endif