/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
			
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: 	
	post:	
*/
int isBalanced(char* s)
{
	/* FIXME: You will write this function */
	char c = *(s);	
	DynArr *stack;
	stack = newDynArr(50); 
	c = nextChar(s);
	//iterate through the string
	while(c != 0){	
		//if the character is an open bracket push it onto the stack
		if(c == '(' || c == '{' || c == '['){
			pushDynArr(stack, c);
		}
		//if the character is a close bracket compare it to the top of the stack
		if(c == ')'){
			if(isEmptyDynArr(stack)){
				return 0;
			}
			if(topDynArr(stack) == '('){
				popDynArr(stack);
			}
		}
		if(c == '}'){
			if(isEmptyDynArr(stack)){
				return 0;
			}
			if(topDynArr(stack) == '{'){
				popDynArr(stack);
			}
		}
		if(c == ']'){
			if(isEmptyDynArr(stack)){
				return 0;
			}
			if(topDynArr(stack) == '['){
				popDynArr(stack);
			}
		}
		c = nextChar(s);
	}
	//if the stack is empty at the end of the string then it is balanced
	if(isEmptyDynArr(stack)){
		return 1;
	}
	return 0;
}

int main(int argc, char* argv[]){
	
	char* s=argv[1];	
	int res;
	
	printf("Assignment 2\n");
	//check for a null string
	if (s == 0){
		printf("The string is balanced\n");
		return 0;
	}

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}

