#include <stdlib.h>
#include <stdio.h>
#define TYPE int

struct link 
{
    TYPE value;
    struct link * next;
};

struct linkedListStack 
{
    struct link *firstLink;
};

void linkedListStackInit (struct linkedListStack * s)
{ s->firstLink = 0; }

void linkedListStackFree (struct linkedListStack *s)
{ while (! linkedListStackIsEmpty(s)) linkedListStackPop(s); }

void linkedListStackPush (struct linkedListStack *s, TYPE d) 
{
    struct link * newLink = (struct link *) malloc(sizeof(struct link));
    assert (newLink != 0);
/* Fix me */
    newLink->value = d;
    newLink->next = s->firstLink;
    s->firstLink = newLink;
}

TYPE linkedListStackTop (struct linkedListStack *s) 
{
/* Fix me */
    if(!linkedListStackIsEmpty(s)){
        return s->firstLink->value;
    }
    else{
        printf("\nThe Stack is Empty!\n");
    }
}

void linkedListStackPop (struct linkedListStack *s) 
{
/* Fix me */
    if(!linkedListStackIsEmpty(s) && s->firstLink->next != 0){
        struct link * tempLink = (struct link *) malloc(sizeof(struct link));
        assert (tempLink != 0);
        tempLink = s->firstLink;
        s->firstLink = s->firstLink->next;
        free(tempLink);
    }
    if(!linkedListStackIsEmpty(s) && s->firstLink->next == 0){
        free(s->firstLink);
    }
    else{
        printf("\nThe Stack is Empty!\n");
    }
}

int linkedListStackIsEmpty (struct linkedListStack *s) 
{
/* Fix me */
    if(s->firstLink == 0){
        return 1;
    }
    else{
        return 0;
    }
}