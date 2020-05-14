#include <stdlib.h>
#include <stdio.h>
#define TYPE int

struct AVLnode {
    TYPE value;
    struct AVLnode *left;
    struct AVLnode *right;
    int height;
};

int _h(struct AVLnode * current)
{ if(current == 0) return -1;  return current ->height;}

void _setHeight (struct AVLnode * current) {
    int lch = _h(current ->left);
    int rch =_h(current ->right);
    if (lch <rch) current ->height = 1 + rch;
    else current ->height = 1 + lch;
}

struct AVLnode * _AVLnodeAdd (struct AVLnode* current,TYPE newValue) {
    struct AVLnode * newnode;
    if (current == 0) {
        newnode = (struct AVLnode *) malloc(sizeof(struct AVLnode));
        assert(newnode != 0);
        newnode->value = newValue;
        newnode->left = newnode->right = 0;
        return newnode;
        //why don’t we balance here ??
    } else if (LT(newValue, current->value))
    current->left = _AVLnodeAdd(current->left, newValue);
    else current->right = _AVLnodeAdd(current->right, newValue);
    return _balance(current);    /* <-NEW  the call on balance */
}

int _bf (struct AVLnode * current)
    {return _h(current->right)- _h(current->left);}

struct AVLnode * _balance (struct AVLnode * current) {
    int cbf = _bf(current);
    if (cbf < -1) {
            if ( _bf(current->left) > 0) // double rotation
                current->left = _rotateLeft(current->left);
            return _rotateRight(current); // single rotation
    } 
    else if (cbf > 1) {
        if ( _bf(current->right) < 0)
            current->right = _rotateRight(current->right);
        return _rotateLeft(current);
    }
    _setHeight(current);
    return current;
}


struct AVLnode * _rotateLeft (struct AVLnode * current) {


}


struct AVLnode * _rotateRight (struct AVLnode * current) {
 

}

void removeAVLTree(struct AVLTree *tree, TYPE val) {
    if (containsAVLTree(tree, val)) {
        tree->root = _removeNode(tree->root, val);
        tree->cnt--;
    }
}

TYPE _leftMost(struct AVLNode *cur) {
    while(cur->left != 0) { 
        cur = cur->left;
    }
    return cur->val;
}

struct AVLNode *_removeLeftmost(struct AVLNode *cur) {
    struct AVLNode *temp;
    if(cur->left!= 0){
        cur->left = _removeLeftmost(cur->left);
        return _balance(cur);
    }
    temp = cur->rght;
    free(cur);
    return temp;
}

struct AVLNode *_removeNode(struct AVLNode *cur, TYPE val) {
    
}


