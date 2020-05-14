/*********************************************************************************
** Program name: Zoo Tycoon
** Author:       Kais Saradi
** Date:         04/30/2019
** Description:  This document contains the main function for the zoo tycoon game
** It  initializes a zoo object and displays the menu. Then it plays the game until
** the user chooses to quit.
**********************************************************************************/
#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "animal.hpp"
#include "tiger.hpp"
#include "penguin.hpp"
#include "turtle.hpp"
#include "zoo.hpp"
#include "menu.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    double tiger_COST = 10000;
    double penguin_COST = 1000;
    double turtle_COST = 100;
    const double BASE_FOOD_COST = 10;

    zoo zoo(100000);
    int choice, buy, animalType;
    int startingAnimals = 0;  //how many animals user would like to start with
    int day = 1; //starting day
    int keepPlaying = 1;
    cout.precision(10);
    cout << "\t*Welcome to Zoo Tycoon!*\n " << endl;
    //start menu
    choice = menu();

    //as user how many animals they would like to start with
    if (choice == 1)
    {
        cout << "\n\n Welcome! You are the proud owner of your own zoo, with exhibits for Tigers, Penguins, and Turtles!" << endl;         
        cout << "You are starting the game with the bank balance $" << zoo.getBalance() << endl;
        //starting Tigers
        cout << "\nEnter a number of tigers to buy (1 or 2): ";
        startingAnimals = checkInt(1,2);
        if (startingAnimals == 1)
        {
            tiger tiger1(1, tiger_COST, 1, 5 * BASE_FOOD_COST, 0.2 * tiger_COST);       //add the tiger(s)
            zoo.addTiger(tiger1);
        }
        else if(startingAnimals == 2)
        {
            tiger tiger1(1, tiger_COST, 1, 5 * BASE_FOOD_COST, 0.2 * tiger_COST);
            tiger tiger2(1, tiger_COST, 1, 5 * BASE_FOOD_COST, 0.2 * tiger_COST);
            zoo.addTiger(tiger1);
            zoo.addTiger(tiger2);
        }
        //Starting Turtles
        cout << "\n\nEnter a number of turtles to buy (1 or 2): ";
        startingAnimals = checkInt(1,2);
        if (startingAnimals == 1)
        {
            turtle turtle1(1, turtle_COST, 10, 0.5 * BASE_FOOD_COST, 0.05 * turtle_COST);   //add the turtle(s)
            zoo.addTurtle(turtle1);
        }
        else if (startingAnimals == 2)
        {
            turtle turtle1(1, turtle_COST, 10, 0.5 * BASE_FOOD_COST, 0.05 * turtle_COST);
            turtle turtle2(1, turtle_COST, 10, 0.5 * BASE_FOOD_COST, 0.05 * turtle_COST);
            zoo.addTurtle(turtle1);
            zoo.addTurtle(turtle2);
        }
        //Starting penguins
        cout << "\nEnter a number of penguins to buy (1 or 2): ";
        startingAnimals = checkInt(1,2);
        if (startingAnimals == 1)
        {
            penguin penguin1(1, penguin_COST, 5, BASE_FOOD_COST, 0.1 * penguin_COST);   //add the penguins(s)
            zoo.addPenguin(penguin1);
        }
        else if (startingAnimals == 2)
        {
            penguin penguin1(1, penguin_COST, 5, BASE_FOOD_COST, 0.1 * penguin_COST);
            penguin penguin2(1, penguin_COST, 5, BASE_FOOD_COST, 0.1 * penguin_COST);
            zoo.addPenguin(penguin1);
            zoo.addPenguin(penguin2);
        }
        //starting the begining of the first day
        while (keepPlaying == 1)
        {  
            cout << "\n\nDay: " << day << endl;
            cout << "Current balance: $" << zoo.getBalance() << endl;
            //incrementing the day and increasing all animals age, as well as subtracting costs
            zoo.newDay();  
            //generating random event
            zoo.randomEvent();

            zoo.totalProfit();
            cout << "your profit for the day is " << zoo.getProfit() << endl;
            cout << "Enter [1] if you like to buy an adult animal, otherwise enter any integer to continue : "; 
            //ask user if they would like to add an animal
            buy = checkInt();
            if (buy == 1)
            {
                cout << "\nPlease select the type of animal you would like:" << endl;
                cout << "[1] tiger" << endl;
                cout << "[2] penguin" << endl;
                cout << "[3] turtle" << endl;          
                animalType = checkInt(1,3);
                //add appropriate animal
                if (animalType == 1)
                {
                    tiger tiger1(3, tiger_COST, 1, 5 * BASE_FOOD_COST, 0.2 * tiger_COST);
                    zoo.addTiger(tiger1);
                }
                else if (animalType == 2)
                {
                    penguin penguin1(3, penguin_COST, 5, BASE_FOOD_COST, 0.1 * penguin_COST);
                    zoo.addPenguin(penguin1);
                }
                else if (animalType == 3)
                {
                    turtle turtle1(1, turtle_COST, 10, 5 * BASE_FOOD_COST, 0.05 * turtle_COST);
                    zoo.addTurtle(turtle1);
                }

            }
            //end of day report
            cout << "\nDay " << day++ << " is complete! your exhibits are as follows: " << endl;
            cout << "You have " << zoo.gettigers() << " tigers in the exhibit" << endl;
            cout << "You have " << zoo.getpenguins() << " penguins in the exhibit" <<endl;
            cout << "You have " << zoo.getturtles() << " turtles in the exhibit" << endl;
            if(zoo.getBalance() <= 0) //check for bankrupcy
            {
                cout << "\n...You've gone bankrupt! Game over!\n" << endl;
            }
            cout << "Enter [1] if you like to keep playing, [2] to quit: "; //continue playing?
            keepPlaying = checkInt(1,2);
            if (keepPlaying != 1)
            {
                cout << "\n\nFinal balance: $" << zoo.getBalance() << endl;
                cout << "Goodye ..." << endl;
            }
        }
    }
    else if (choice == 2)       //if user choses to exit menu
    {          
        cout << "\nGoodbye!  ...\n" << endl;
    }
    zoo.~zoo();
    return 0;
}