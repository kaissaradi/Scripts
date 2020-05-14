struct BSTIterator {
    struct DynArr    *stk;
    struct BSTree    *tree;
}; 

void BSTIteratorInit (struct BSTree *tree, struct BSTIterator *itr) {
    itr->tree = tree;
    itr->stk = newDynArr(); 
} 

int BSTIteratorHasNext (struct BSTIterator * itr) {
    struct Node *n;
    if(isEmptyDynArr(itr->stk)){
        _slideLeft(itr->tree->root, itr);
    }
    else {
        n = topDynArr(itr->stk);
        popDynArr(itr->stk);
        _slideLeft(n->right, itr);
    }
    if(!isEmptyDynArr(itr->stk)){
        return 1;
    }
    else return 0;
}

TYPE BSTIteratorNext (struct BSTIterator *itr) {
    return (topDynArr(itr->stk))->val;
}

void _slideLeft(struct Node *cur, struct BSTIterator *itr) 
{ 
    while(cur != null) 
    { 
        dynArrayPush(Itr->stk, cur); 
        cur = cur->left;
    } 
} 


