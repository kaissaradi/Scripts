/* CS261- Assignment 1 - Q. 0*/
/* Name: Kais Saradi
 * Date: 10/13/2019
 * Solution description: contains two functions, fooA and fooB which print the value and
 * address of their pointers as well as change value and addresses and an main function
 * which prints the value and address of a variable and calls the two functions.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fooA(int* iptr){
  
     /*Print the value and address of the integer pointed to by iptr*/
       printf("\nFunction call to fooA\nValue: %d\t Address: %p\n", *iptr, iptr);   
     /*Increment the value of the integer pointed to by iptr by 5*/
       *iptr = *iptr + 5; 
     /*Print the address of iptr itself*/
       printf("\niptr Address: %p\n", &iptr); 

    /*Dummy variable, ignore the warning*/
   int c=5;  
}


void fooB(int* jptr){
  
     /*Print the value and address of the integer pointed to by jptr*/
     printf("\nFunction call to fooB\nValue: %d\t Address: %p\n", *jptr, jptr);           
     /*Decrement the address by 1 pointed to by jptr using jptr */
     jptr--;
     /*Print the address of jptr itself*/
     printf("\njptr Address: %p\n", &jptr); 
}


int main(){
    
    /*Declare an integer x and initialize it randomly to a value in [0,10] */
    srand(time(0));
    int x = 1+ rand() % 11;
    /*Print the value and address of x*/
    printf("\nVariable: X\tValue: %d \t Address: %p\n", x, &x);
    /*Call fooA() with the address of x*/
    fooA(&x);
    /*Print the value of x*/
    printf("\nVariable: X\tValue: %d\n", x);    //A:The value of X is different now, since fooA changed its value directly
    /*Call fooB() with the address of x*/
    fooB(&x);
    /*Print the value and address of x*/
    printf("\nVariable: X\tValue: %d \t Address: %p\n", x, &x); //A: The value and address are the same, since fooB only changed the address pointed to by jptr
                                                                // and did not access or change and other variables/addresses
    return 0;
}


