/*********************************************************************************
** Program name: Zoo Tycoon
** Author:       Kais Saradi
** Date:         04/30/2019
** Description:  This document contains the member functions for the Parent class
** Animal. It has a constructor for creating a new animal object, and set and get 
** functions for the variables.
**********************************************************************************/
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


/*********************************************************************************
 * The animal constructor which initializes an empty animal baby, with an over-
 *          loaded constructor to pass each variable
 * *******************************************************************************/
animal::animal()
{
    age = 0;
    cost = 0.0;
    numberOfBabies = 0;
    baseFoodCost = 0.0;
    payoff = 0.0;
}
animal::animal(int age, double cost, int numberOfBabies, double baseFoodCost, double payoff)
{
    this -> age = age;
    this -> cost = cost;
    this -> numberOfBabies = numberOfBabies;
    this -> baseFoodCost = baseFoodCost;
    this -> payoff = payoff;
}

/*********************************************************************************
 *          Get Functions to return each variable of the animal object
 * *******************************************************************************/
int animal::getAge()
{
    return age;
}
double animal::getCost()
{
    return cost;
}
int animal::getNumberOfBabies()
{
    return numberOfBabies;
}
 double animal::getBaseFoodCost()
{
     return baseFoodCost;
}
double animal::getpayoff()
{
    return payoff;
}

/*********************************************************************************
 *          set functions to set each variable for the animal object
 * *******************************************************************************/
void animal::setAge(int age)
{
    this-> age = age;
}
void animal::setCost(double cost)
{
    this -> cost = cost;
}
void animal::setNumberOfBabies(int numberOfBabies)
{
    this ->numberOfBabies = numberOfBabies;
}
void animal::setBaseFoodCost(double baseFoodCost)
{
    this -> baseFoodCost = baseFoodCost;
}
void animal::setpayoff(double payoff)
{
    this -> payoff = payoff;
}