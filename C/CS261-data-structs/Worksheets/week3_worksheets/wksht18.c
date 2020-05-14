#include<stdio.h>
#include<stdio.h>
#define TYPE int

struct link {
    TYPE value;
    struct link * next;
};

struct listQueue {
    struct link *firstLink;
    struct link *lastLink;
};

void listQueueInit (struct listQueue *q) {
    struct link *lnk = (struct link *) malloc(sizeof(struct link));
    assert(lnk != 0); /* lnk is the sentinel */
    lnk->next = 0;
    q->firstLink = q->lastLink = lnk;
}

void listQueueAddBack (struct listQueue *q, TYPE e) {
    struct link *newLink = (struct link *) malloc(sizeof(struct link));
    assert(newLink != 0);
    newLink->value = e;
    if(listQueueIsEmpty(q)){
        newLink->next = 0;
        q->lastLink = newLink;
        q->firstLink->next = q->lastLink;
    }
    else{
        q->lastLink->next = newLink;
        newLink->next = 0;
        newLink = q->lastLink;
    }
}

TYPE listQueueFront (struct listQueue *q) {
    if(!listQueueIsEmpty(q)){
        return q->firstLink->next->value;
    }
    else{
        printf("\nThe Queue is Empty!\n");
    }
}

void listQueueRemoveFront (struct listQueue *q) {
    
    if(!listQueueIsEmpty(q) && q->firstLink->next != 0){
        struct link *newLink = (struct link *) malloc(sizeof(struct link));
        assert(newLink != 0);
        newLink = q->firstLink->next;
        q->firstLink->next = newLink->next;
        free(newLink);
    }
    else if(!listQueueIsEmpty(q) && q->firstLink->next == q->lastLink){
        free(q->lastLink);
        q->lastLink = q->firstLink;
    }
    else{
        printf("\nThe Queue is Empty!\n");
    }
}

int listQueueIsEmpty (struct listQueue *q) {
    if(q->firstLink->next == 0){
        return 1;
    }
    else{
        return 0;
    }
}
