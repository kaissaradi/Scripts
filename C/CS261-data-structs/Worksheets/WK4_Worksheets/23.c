#include <stdlib.h>
#include <stdio.h>
#define TYPE int
struct dynArrayIterator {
    struct dynArray * da;
    int currentIndex; 
};

void dynArrayIteratorInit (struct dynArray *da, struct dynArrayIterator *itr) {
}

int dynArrayIteratorHasNext (struct dynArrayIterator *itr) {
}

TYPE dynArrayIteratorNext (struct dynArrayIterator *itr) {
}

void dynArrayIteratorRemove (struct dynArrayIterator *itr) {
}
