/*******************************************************************************
** Program name: Zoo Tycoon
** Author:       Kais Saradi
** Date:         04/28/2019
** Description:  This program contains input validation functions for checking for
** an integer, with overloaded options for adding limits, and a menu function to 
** display a menu.
*********************************************************************************/
#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "zoo.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;
int checkInt();
int checkInt (int lowerLim);    //override functions to allow you to check for an integer with an upper and lower limit
int checkInt(int lowerLim, int upperLim);
int menu();

#endif