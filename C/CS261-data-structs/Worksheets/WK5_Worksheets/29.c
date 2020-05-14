#include <stdlib.h>
#include <stdio.h>
#define TYPE int

struct Node {
    TYPE value;
    struct Node * left;
    struct Node * right;
};

struct BinarySearchTree {
    struct Node *root;
    int size;
};


void initBST(struct BinarySearchTree *tree) {
    tree->size = 0; 
    tree->root = 0;
}

void addBST(struct BinarySearchTree *tree, TYPE newValue) {
    tree->root = _nodeAddBST(tree->root, newValue);
    tree->size++; 
}

int sizeBST(struct BinarySearchTree *tree) 
{return tree->size;}

struct Node *_nodeAddBST(struct Node *current, TYPE newValue) {
assert(newValue!= NULL);
 
    /* base case: the current node is null (the supplied tree is empty), so make a new node, set
    the fields, and return a pointer to that node */
    if (current == 0) {
    struct node * newNode = (struct node*)malloc(sizeof(struct node));
    assert(newNode != 0);
    newNode->left = newNode->right = 0;
    newNode->value = newValue;
    return newNode;
    }
    /*  if current is an actual node, so check if the new node is supposed to be left of the
    current node or right of it (less than current's value or not) */
    if (newValue < current->value)
    current->left = _nodeAddBST(current->left, newValue); /* when newValue goes to the left
    subtree, set the current node's left child to be that same subtree, but with the value added
    in the right location */
    else
    current->right = _nodeAddBST(current->right, newValue); /* when newValue goes to the
    right subtree, set the current node's right child to be that same subtree, but with the value
    added in the right location */
    /* now that the proper child of the current node has been changed to have the added value,
    return that current node */
    /* this is required because the function's job is to return a pointer to the argument node,
    but with the added value included somewhere below (or at) that node */
    return current;

}

int containsBST(struct BinarySearchTree *tree, TYPE d) {
    assert(tree!=NULL);
    assert(d!=NULL);
    
    struct Node *searchNode = tree->root;
    while (searchNode != NULL){
    if (searchNode->value == d)
    return 1; //Return true if found
    else if (d < searchNode->value)
    searchNode = searchNode->left;
    else
    searchNode = searchNode->right;
    }
    return 0; //Return false if not found
}

void removeBST(struct BinarySearchTree *tree, TYPE d) {
    if (containsBST(tree, d)){
        tree->root = _nodeRemoveBST(tree->root, d);
        tree->size--;
    }
}

TYPE_leftMostChild(struct Node * current) {
    assert(current!=NULL); 
    while(current->left != NULL){
        current = current->left;
    }
    return current->value;
}

struct node * _removeLeftmostChild(struct Node *current) {
    /* returns a node pointer to the starting sub-tree but with its left most child removed */
    assert(current!=NULL) 
    /* base case: the supplied tree has no left child, so we know that the supplied tree *is* the
    most left child, which means we can just remove it */
    if (current->left == NULL){
    struct node * temp = current->right;
    free(current);
    return temp;
    }
    /* if there is a left child, set the left child pointer to point to the left child sub-tree,
    but with its left most child removed */
    else { 
    current->left = _removeLeftmostChild(current->left);
    }
    return current;
}

struct Node * _nodeRemoveBST(struct Node * current, TYPE d) {        
    assert(current != NULL);
    assert(d != NULL);
    
    /*  base case: the supplied node *is* the node we want to remove. there are two
    cases to handle: there is no right child, and there is a right child */
    if (current->value == d){
    if (current->right == NULL){ /* if there isn't a right child for this node, we
    can simply free the data for the current node and return the left child (it needs to
    move into the current node's spot) */
    struct Node *tempNode =  current->left;
    free(current);
    return tempNode ;
    }
    else{
    current->value = _leftMostChild(current->right);
    current->right = _removeLeftmostChild(current->right);
    }
    }
    // Else if value is less than current value
    else if (d <current->value){
    current->left = _nodeRemoveBST(current->left, d);
    }
    // Else value is greater than current value
    else{
    current->right = _nodeRemoveBST(current->right, d);
    }
    return current;
}
