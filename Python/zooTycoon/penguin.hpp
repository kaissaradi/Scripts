/**********************************************************************************
** Program name: Zoo Tycoon
** Author:       Kais Saradi
** Date:         04/30/2019
** Description:  This header file contains the class declaration  for the penguin
** class, which is a child class of the animal class. It contains a constructor for
** creating a new penguin object.
***********************************************************************************/
#ifndef PENGUIN_HPP
#define PENGUIN_HPP
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

class penguin : public animal
{
public:
    penguin();
    penguin(int age, double cost, int numberofBabies, double baseFoodCost, double payoff);
};

#endif