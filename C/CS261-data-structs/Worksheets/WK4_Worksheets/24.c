#include <stdlib.h>
#include <stdio.h>
#define TYPE int

struct linkedListIterator {
    struct linkedList * lst;
    struct dLink * currentLink;
};

void linkedListIteratorInit (struct linkedList  *lst, struct linkedListIterator * itr) {
    itr->lst = lst;
    itr->currentLink = itr->lst->frontSentinel;
}

void _removeLink (struct linkedList  *lst, struct dLink * lnk);

int linkedListIteratorHasNext (struct linkedListIterator *itr) {
}

TYPE linkedListIteratorNext (struct linkedListIterator *itr) {
}

/* think about the next one carefully. Draw a picture. What should itr->currentLink be pointing to
after the remove operation? */
void linkedListIteratorRemove (struct linkedListIterator *itr) {
}
