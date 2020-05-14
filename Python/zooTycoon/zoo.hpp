/*********************************************************************************
** Program name: Zoo Tycoon
** Author:       Kais Saradi
** Date:         04/30/2019
** Description:  This head contains the class declaration for the zoo class. it
** contains a constructor, functions to add and remove animals, get and set
** functions for the animals and balance, add a day, and create a random event. it
also contains a deconstructor to free all dynamic memory.
**********************************************************************************/
#ifndef ZOO_HPP
#define ZOO_HPP
#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "animal.hpp"
#include "tiger.hpp"
#include "penguin.hpp"
#include "turtle.hpp"
#include "menu.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;

class zoo
{
    private:
    tiger *tigerExhibit;
    penguin *penguinExhibit;
    turtle *turtleExhibit;
    int tigerSpace;
    int penguinSpace;
    int turtleSpace;
    int tigerCount;
    int penguinCount;
    int turtleCount;  
    double balance;
    double profit;   
    public:
    zoo();
    zoo(double balance);
    void addTiger(tiger newtiger);
    void addTurtle(turtle newturtle);
    void addPenguin(penguin newpenguin);  
    bool removeTiger();
    bool removeTurtle();
    bool removePenguin();   
    void randomDeath();   
    bool hasAdultTiger();
    bool hasAdultTurtle();
    bool hasAdultPenguin();
    int gettigers();
    int getturtles();
    int getpenguins();
    void setBalance(double balance);
    void setProfit(double profit);
    double getBalance();
    double getProfit();
    void totalProfit();
    void newDay();
    void randomEvent();
    ~zoo();
};

#endif