/*******************************************************************************
** Program name: Zoo Tycoon
** Author:       Kais Saradi
** Date:         04/28/2019
** Description:  This program contains input validation functions for checking for
** an integer, with overloaded options for adding limits, and a menu function to 
** display a menu.
*********************************************************************************/
#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "menu.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;

/**********************************************************************************
 *  input validation function which asks the user to enter an integer. The function
 *  checks to make sure either of the first two characters entered is a digit, then
 *  converts the string to an integer.
 * *******************************************************************************/
int checkInt()
{
    string input = " ";
    int num = 0;
    bool error = true;
    do
    {
        cout << "\nPlease enter an integer" << endl;
        getline(cin, input); 
        if(input.empty())
        {
            cout << "\nerror!\n";
        }
        else if(isdigit(input.at(0))|| (input.at(0) == '-' && isdigit(input.at(1))) )
        {
            num = stoi(input);
            error = false;   
        }
        else
        {
            cout << "\nerror!\n";
        }
    }
    while(error);
    return num;
}


/*******************************************************************************
 *  Overloaded checkInt function which allows the user to pass a lower limit,
 *  so the integer entered must be greater than or equal to the lower limit.
 * ***************************************************************************/
int checkInt(int lowerLim)
{
    string input = " ";
    int num = 0;
    bool error = true;
    do
    {
        cout << "\nPlease enter an integer greater than or equal to " << lowerLim << endl;
        getline(cin, input); 
        if(input.empty())
        {
            cout << "\nerror!\n";
        }
        else if(isdigit(input.at(0)))
        {
            num = stoi(input);
            if(num >= lowerLim)
            {
                error = false; 
            }  
        }
        else
        {
            cout << "\nerror!\n";
        }
    }
    while(error); 
    return num;
}

/*************************************************************************************
 * overloaded function which asks for and validates and integer between the lower and
 * upper limit that are passed to the function.
 * **********************************************************************************/
int checkInt(int lowerLim, int upperLim)
{
    string input = " ";
    int num = 0;
    bool error = true;
    do
    {
        cout << "\nPlease enter an integer from " << lowerLim << " to " << upperLim << endl;
        getline(cin, input); 
        if(input.empty())
        {
            cout << "\nerror!\n";
        }
        else if(isdigit(input.at(0)))
        {
            num = stoi(input);
            if(num >= lowerLim && num <= upperLim)
            {
                error = false; 
            }  
        }
        else
        {
            cout << "\nerror!\n";
        }
    }
    while(error);
    return num;
}

/********************************************************************************
**                                  menu
** this is the menu() function which prints the menu and asks the user to make a
** selection. The function then returns the integer that the user entered after
** validating input.
********************************************************************************/
int menu()
{
    int choice = 0;
    cout << "Please select an option:" << endl;
    cout << "[1] Play Game" << endl;
    cout << "[2] Exit Game" << endl;
    choice = checkInt(1,2);
    return choice;
}
