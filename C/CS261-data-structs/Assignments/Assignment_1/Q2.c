/* CS261- Assignment 1 - Q.2*/
/* Name: Kais Saradi    
 * Date: 10/14/2019
 * Solution description: A program which has a function to swap two addresses of
 * pointers and decrement the value of a variable, as well as a main function to
 *  display the value of all the variables
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int foo(int* a, int* b, int c){
    /*Swap the addresses stored in the pointer variables a and b*/
    int *temp;
    temp = a;
    a = b;
    b = temp;
    /*Decrement the value of integer variable c*/
    c--;
    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them randomly to values in [0,10] */
    int x = rand() % 11;
    int y = rand() % 11;
    int z = rand() % 11;
    /*Print the values of x, y and z*/
    printf("\nVariable\tValue");
    printf("\nX\t\t%d",x);
    printf("\nY\t\t%d",y);
    printf("\nz\t\t%d",z);
    /*Call foo() appropriately, passing x,y,z as parameters*/
    int value = foo(&x,&y,z);
    /*Print the values of x, y and z*/
    printf("\nVariable\tValue");
    printf("\nX\t\t%d",x);
    printf("\nY\t\t%d",y);
    printf("\nz\t\t%d",z);
    /*Print the value returned by foo*/
    printf("\nFoo returned\t\t%d\n\n", value);
    
    return 0;
}
/*
A:Yes. Since a copy of z is passed to foo, and foo then changes the value of that cope
and returns a different value, the value returned by foo is different than the value of Z

B: No. The only thing foo changes is the address pointed to by a and b, which are swapped.
*/


