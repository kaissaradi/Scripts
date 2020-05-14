#include<stdio.h>
#include<stdio.h>
#define TYPE int

struct dlink {
    TYPE value;
    struct dlink * next;
    struct dlink * prev;
};

struct linkedList {
    int size;
    struct dlink * frontSentinel;
    struct dlink * backSentinel;
};

/* these functions are written for you */
void LinkedListInit (struct linkedList *q) {
    q->frontSentinel = (struct dlink *) malloc(sizeof(struct dlink));
    assert(q->frontSentinel != 0);
    q->backSentinel = (struct dlink *) malloc(sizeof(struct dlink));
    assert(q->backSentinel);
    q->frontSentinel->next = q->backSentinel;
    q->backSentinel->prev = q->frontSentinal;
    q->size = 0;
}

void linkedListFree (struct linkedList *q) {
    while (q->size > 0)
    linkedListRemoveFront(q);
    free (q->frontSentinel);
    free (q->backSentinel);
    q->frontSentinel = q->backSentinel = 0;
}
void LinkedListAddFront (struct linkedList *q, TYPE e)
{ _addLink(q, q->frontSentinel->next, e); }

void LinkedListAddback (struct linkedList *q, TYPE e)
{ _addLink(q, q->backSentinel, e); }

void linkedListRemoveFront (struct linkedList *q) {
assert(! linkedListIsEmpty(q));
_removeLink (q, q->frontSentinal->next);
}

void LinkedListRemoveBack (struct linkedList *q) {
assert(! linkedListIsEmpty(q));
_removeLink (q, q->backSentinel->prev);
}

int LinkedListIsEmpty (struct linkedList *q) {
return q->size == 0;
}


/* write addLink and removeLink. Make sure they update the size field correctly */
/* _addLink places a new link BEFORE the provide link, lnk */
void _addLink (struct linkedList *q, struct dlink *lnk, TYPE e) {
    struct dlink *newLink = (struct dlink *) malloc(sizeof(struct dlink));
    assert(newLink != 0);
    newLink->value = e;
    newLink->next = lnk;
    newLink->prev = lnk->prev;
    lnk->prev = newLink;
    newLink->prev->next = newLink;
    q->size += 1;
}
void _removeLink (struct linkedList *q, struct dlink *lnk) {
    lnk->next->prev  = lnk->prev;
    lnk->prev->next = lnk->next;
    free(lnk);
}
TYPE LinkedListFront (struct linkedList *q) {
    return q->frontSentinel->next->value;
}
TYPE LinkedListBack (struct linkedList *q) {
    return q->backSentinel->prev->value;
}