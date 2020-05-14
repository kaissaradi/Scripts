/**********************************************************************************
** Program name: Zoo Tycoon
** Author:       Kais Saradi
** Date:         04/30/2019
** Description:  This header file contains the function declaration for the Animal 
** class. It has a constructor for creating a new animal object, and set and get 
** functions for the variables.
***********************************************************************************/
#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include <cstdlib>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class animal
{
    protected:
    int age;
    double cost;
    int numberOfBabies;
    double baseFoodCost;
    double payoff;
    public:
        animal();
        animal(int age, double cost, int numberOfBabies, double baseFoodCost, double payoff);
        int getAge();
        double getCost();
        int getNumberOfBabies();
        double getBaseFoodCost();
        double getpayoff();
        void setAge(int age);
        void setCost(double cost);
        void setNumberOfBabies(int numberOfBabies);
        void setBaseFoodCost(double baseFoodCost);
        void setpayoff(double payoff);
};

#endif