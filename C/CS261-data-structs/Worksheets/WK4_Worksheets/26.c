#include <stdlib.h>
#include <stdio.h>
#define TYPE int
/*Assume you have access to all existing dynArr functions */
/* _binarySearch is also included in dynArr.c now as an internal function! */
int _binarySearch(TYPE *data, int size, TYPE testValue);

/* These are the new functions to take advantage of the ordered dynamic array 
and available to the end user , so they will be declared in the .h file */
int dyArrayBinarySearch (struct dyArray * da, TYPE testValue) {
    return _binarySearch (da->data, da->size, testValue);
}

void orderedArrayAdd (struct dyArray *da, TYPE newElement) {
    int index = _binarySearch(da->data, da->size, newElement);
    dyArrayAddAt (da, index, newElement);  /* takes care of resize if necessary*/
}

/* you must complete the following */
int orderedArrayContains (struct dyArray *da, TYPE testElement) {
}

void orderedArrayRemove (struct dyArray *da, TYPE testElement) {
}
