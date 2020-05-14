#include <stdlib.h>
#include <stdio.h>
#define TYPE int
struct dLink {
    TYPE value;
    struct dLink * next;
    struct dLink * prev;
};

struct linkedList {
    struct dLink * frontSentinel;
    struct dLink * backSentinel;
    int size;
};
/* the following functions were written in earlier lessons */
void linkedlistInit (struct linkedList *lst);
void linkedListFree (struct linkedList *lst);
void _addLink (struct linkedList * lst, struct dLink * lnk, TYPE e);
void _removeLink (struct linkedList * lst, struct dLink * lnk);   
void linkedListAdd (struct linkedList * lst, TYPE e)
{ _addLink(lst, lst->frontSentinel->next, e); }


/* you must write the following */
int linkedListContains (struct linkedList *lst, TYPE e) {
}
void linkedListRemove (struct linkedList *lst, TYPE e) {
}
