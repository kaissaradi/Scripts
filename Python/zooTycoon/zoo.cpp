/*********************************************************************************
** Program name: Zoo Tycoon
** Author:       Kais Saradi
** Date:         04/30/2019
** Description:  This document contains the member functions for the zoo class. it
** contains a constructor, functions to add and remove animals, get and set
** functions for the animals and balance, add a day, and create a random event. it
also contains a deconstructor to free all dynamic memory.
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

/*********************************************************************************
 *  Zoo constructor with overloaded constructor to pass the initial balance, sets
 * the capacity for each exhibit, creates a dynamically allocated array for each
 * exhibit, and sets the variables for the zoo
 * *******************************************************************************/
zoo::zoo() 
{
    balance = 1000000;
    profit = 0;
    tigerCount = 0;
    turtleCount = 0;  
    penguinCount = 0;

    tigerSpace = 10;
    turtleSpace = 10;
    penguinSpace = 10;

    tigerExhibit = new tiger[tigerSpace];
    turtleExhibit = new turtle[turtleSpace];
    penguinExhibit = new penguin[penguinSpace];
}

zoo::zoo(double balance)
{
    this -> balance = balance;
    profit = 0;
    tigerCount = 0;
    turtleCount = 0;  
    penguinCount = 0;

    tigerSpace = 10;
    turtleSpace = 10;
    penguinSpace = 10;

    tigerExhibit = new tiger[tigerSpace];
    turtleExhibit = new turtle[turtleSpace];
    penguinExhibit = new penguin[penguinSpace];

}

/*********************************************************************************
 *  Add Function to add an animal to the array, resize it if it is full, and 
 *  update the count of animals in the array, then it subtracts the cost for the
 *  animal from the players balance
 * *******************************************************************************/
void zoo::addTiger(tiger newTiger)
{
    if (tigerCount == tigerSpace) //check if the exhibit reached capacity
    {
        tiger* newArray = new tiger[(2 * tigerSpace)]; //create new arrray
        for (int i = 0; i < tigerSpace; i++)
        {
            newArray[i] = tigerExhibit[i];
        }
        delete[] tigerExhibit;

        tigerExhibit = newArray;
        tigerSpace = (2 * tigerSpace);
    }

    tigerExhibit[tigerCount] = newTiger;  
    tigerCount++;  
    balance = balance - newTiger.getCost();
}

/*********************************************************************************
 *  Add Function to add an animal to the array, resize it if it is full, and 
 *  update the count of animals in the array, then it subtracts the cost for the
 *  animal from the players balance
 * *******************************************************************************/
void zoo::addTurtle(turtle newTurtle)
{
    if (turtleCount == turtleSpace)
    {
        turtle* newArray = new turtle[(2 * turtleSpace)];
        for (int i = 0; i < turtleSpace; i++)
        {
            newArray[i] = turtleExhibit[i];
        }      

        delete[] turtleExhibit;

        turtleExhibit = newArray;
        turtleSpace = 2 * turtleSpace;
    }

    turtleExhibit[turtleCount] = newTurtle;  
    turtleCount++;
    balance = balance - newTurtle.getCost();
}

/*********************************************************************************
 *  Add Function to add an animal to the array, resize it if it is full, and 
 *  update the count of animals in the array, then it subtracts the cost for the
 *  animal from the players balance
 * *******************************************************************************/
void zoo::addPenguin(penguin newPenguin)
{
    if (penguinCount == penguinSpace)
    {
        penguin* newArray = new penguin[(2 * penguinSpace)];
        for (int i = 0; i < penguinSpace; i++)
        {
            newArray[i] = penguinExhibit[i];
        }
        delete[] penguinExhibit;

        penguinExhibit = newArray;
        penguinSpace = 2 * penguinSpace;
    }
    
    penguinExhibit[penguinCount] = newPenguin;  
    penguinCount++;
    balance = balance - newPenguin.getCost();
}


/*********************************************************************************
 *         Function to remove a Tiger from the  exhibit
 * *******************************************************************************/
bool zoo::removeTiger()
{
    if (tigerCount == 0)
    {
        return false;
    }
    else
    {      
        cout << "...A tiger has been removed from the zoo..." << endl;
        tigerCount--;
        return true;
    }
}
/*********************************************************************************
 *         Function to remove a Turtle from the  exhibit
 * *******************************************************************************/
bool zoo::removeTurtle()
{
    if (turtleCount == 0)
    {
        return false;
    }
    else
    {
        cout << "...A turtle has been removed from the zoo..." << endl;
        turtleCount--;
        return true;
    }
}
/*********************************************************************************
 *         Function to remove a Penguin from the  exhibit
 * *******************************************************************************/
bool zoo::removePenguin()
{
    if (penguinCount == 0)
    {
        return false;
    }
    else
    {
        cout << "...A penguin has been removed from the zoo..." << endl;
        penguinCount--;
        return true;
    }
}

/****************************************************************************
 *  RandomDeath function which generates a random animal to remove, then 
 * uses the remove function to check if the exhibit is empty. If it is, it 
 * checks the next exhibits to remove an animal. If there are no animals, it 
 * displays the terminating message.
 * ************************************************************************/
void zoo::randomDeath()
{
    bool animalsRemaining = false;
    int ranAnimal = rand() * 3 + 1;
    
    if (ranAnimal == 1)
    {
        animalsRemaining = removeTiger();
        //if no animals in tigerexhibit, check turtle exhibit, then penguin exhibit
        if (!animalsRemaining)
        {
            animalsRemaining = removeTurtle();
        }
        if (!animalsRemaining)
        {
            animalsRemaining = removePenguin();
        }
    }
    else if (ranAnimal == 2)
    {
        animalsRemaining = removeTurtle();
        
        if (!animalsRemaining)
        {
            animalsRemaining = removeTiger();
        }

        if (!animalsRemaining)
        {
            animalsRemaining = removePenguin();
        }          
    }
    else if (ranAnimal == 3)
    {
        animalsRemaining = removePenguin();
        if (!animalsRemaining)
        {
            animalsRemaining = removeTurtle();
        }
        if (!animalsRemaining)
        {
            animalsRemaining = removeTiger();
        }
    }
    else
    {
        cout << "There are no animals left in the zoo" << endl;
    }
    
}



/*********************************************************************************
 *    function which checks the exhibit for a adult Tiger, over 3 days old, and 
 * returns true if one exists, otherwise it returns false.
 * *******************************************************************************/
bool zoo::hasAdultTiger()
{ 
    for (int i = 0; i < tigerCount; i++)
    {
        if (tigerExhibit[i].getAge() > 2)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }

}
/*********************************************************************************
 *    function which checks the exhibit for a adult Turtle, over 3 days old, and 
 * returns true if one exists, otherwise it returns false.
 * *******************************************************************************/
bool zoo::hasAdultTurtle()
{  
    for (int i = 0; i < turtleCount; i++)
    {
        if (turtleExhibit[i].getAge() > 2 )
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
}
/*********************************************************************************
 *    function which checks the exhibit for a adult Penguin, over 3 days old, and 
 * returns true if one exists, otherwise it returns false.
 * *******************************************************************************/
bool zoo::hasAdultPenguin()
{ 
    for (int i = 0; i < penguinCount; i++)
    {
        if (penguinExhibit[i].getAge() > 2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

/*********************************************************************************
 *      Get and Set functions return the count of each animal, as well as to 
 *                       set and get the balance and profit
 * *******************************************************************************/
int zoo::gettigers()
{
    return tigerCount;
}

int zoo::getturtles()
{
    return turtleCount;
}
int zoo::getpenguins()
{
    return penguinCount;
}
void zoo::setBalance(double balance)
{
    this -> balance = balance;
}

void zoo::setProfit(double profit)
{
    this -> profit = profit;
}
double zoo::getBalance()
{
    return balance;
}
double zoo::getProfit()
{
    return profit;
}

/*********************************************************************************
 *              Void function to calculate the total profit
 * *******************************************************************************/
void zoo::totalProfit()
{   //Summing total profit for each exhibit
    for (int i = 0; i < tigerCount; i++)
    {
        profit = profit + tigerExhibit[i].getpayo ff();
    }
    for (int i = 0; i < turtleCount; i++)
    {
        profit = profit + turtleExhibit[i].getpayoff();
    }
        for (int i = 0; i < penguinCount; i++)
    {
        profit = profit + penguinExhibit[i].getpayoff();
    }
}

/*********************************************************************************
 *  A function to increment the day for each animal, the method increments each 
 *          animals age, and subtracts the food cost for the day
 * *******************************************************************************/
void zoo::newDay()
{   //increase age by one day and subtract food costs for the day
    for (int i = 0; i < tigerCount; i++)
    {
        tigerExhibit[i].setAge(tigerExhibit[i].getAge() + 1);
        balance = balance - tigerExhibit[i].getBaseFoodCost();
    }
    for (int i = 0; i < turtleCount; i++)
    {
        turtleExhibit[i].setAge(turtleExhibit[i].getAge() + 1);
        balance = balance - turtleExhibit[i].getBaseFoodCost();
    }
    for (int i = 0; i < penguinCount; i++)
    {
        penguinExhibit[i].setAge(penguinExhibit[i].getAge() + 1);
        balance = balance - penguinExhibit[i].getBaseFoodCost();
    }
}

/*********************************************************************************
 *      RandomEvent Function to generate one of four random events
 * *******************************************************************************/
void zoo::randomEvent()
{
    int randEvent = rand() % 4 + 1; //one of 4 random events
    int randType, randBonus;    //integer to choose a random animal type and bonus amount
    double tiger_COST = 10000;
    double penguin_COST = 1000;
    double turtle_COST = 100;
    const double BASE_FOOD_COST = 10;
    tiger tigercub(1, tiger_COST, 1, 5 * BASE_FOOD_COST, 0.2 * tiger_COST);
    penguin penguinchick(1, penguin_COST, 5, BASE_FOOD_COST, 0.1 * penguin_COST);
    turtle turtlebaby(1, turtle_COST, 10, 0.5 * BASE_FOOD_COST, 0.05 * turtle_COST);
    if(randEvent == 1)
    {    
        cout << "Random Event: A sickness occurs, an animal is removed from the zoo. " << endl;
        randomDeath();
    }

    else if(randEvent == 2)
    {
        cout << "Random Event: A boom in zoo attendance occurs." << endl;

        for (int i = 0; i < tigerCount; i++)
        {
            randBonus = rand() % 251 + 250;
            tigerExhibit[i].setpayoff(tigerExhibit[i].getpayoff() + randBonus);
        }
        cout << "\nA bonus of " << randBonus << " has been added for each tiger.\n" << endl;
    }

    else if(randEvent ==3)
    {
        cout << "Random Event: A baby is born!" << endl;

        randType = rand() % 3 + 1;

        if (randType == 1 && hasAdultTiger())
        {
            for (int i = 0; i < tigerCount; i++)
            {
                if (tigerExhibit[i].getAge() >= 3)
                {
                    tigerExhibit[i].setNumberOfBabies(1);
                    break;
                }
            }
            addTiger(tigercub);
            cout << "A tiger cub was born! " << endl;   
        }   
        else if (randType == 2 && hasAdultPenguin())
        {
            for (int i = 0; i < penguinCount; i++)
            {
                if (penguinExhibit[i].getAge() >= 3)
                {
                    penguinExhibit[i].setNumberOfBabies(1);
                    break;
                }
            }
            addPenguin(penguinchick);
            addPenguin(penguinchick);
            addPenguin(penguinchick);
            addPenguin(penguinchick);
            addPenguin(penguinchick);
            cout << "5 penguin chicks were hatched! " << endl;
        }
        else if(randType == 3 && hasAdultTurtle())
        {
            for (int i = 0; i < turtleCount; i++)
            {
                if (turtleExhibit[i].getAge() >= 3)
                {
                    turtleExhibit[i].setNumberOfBabies(1);
                    break;
                }
            }
            addTurtle(turtlebaby);
            addTurtle(turtlebaby);
            addTurtle(turtlebaby);
            addTurtle(turtlebaby);
            addTurtle(turtlebaby);
            addTurtle(turtlebaby);
            addTurtle(turtlebaby);
            addTurtle(turtlebaby);
            addTurtle(turtlebaby);
            addTurtle(turtlebaby);
            cout << "10 turtle eggs hatched! " << endl;
        }
    }
    else if(randEvent == 4)
    {
        cout << "Random Event: Nothing happens." << endl;
    }
}


zoo::~zoo()
{
    delete[] tigerExhibit;
    delete[] penguinExhibit;
    delete[] turtleExhibit;
}