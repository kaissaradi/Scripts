//WORKSHEET 0

//#ifndef arrBagStack 
//#define arrBagStack 
#define TYPE int
#define EQ(a, b) (a == b)
//#endif
struct arrBagStack 
{ 
	TYPE data[100];
	int count; 
};

void initArr(struct arrBagStack* b); 
void addArr(struct arrBagStack* b, TYPE v); 
int containsArr(struct arrBagStack* b, TYPE v); 
void removeArr(struct arrBagStack* b, TYPE v); 
int sizeArr(struct arrBagStack* b);

void pushArr(struct arrBagStack* b, TYPE v); 
TYPE topArr(struct arrBagStack* b); 
void popArr(struct arrBagStack* b); 
int isEmptyArr(struct arrBagStack* b); 


void initArr(struct arrBagStack* b) 
{
	b->count = 0;
}

/* Stack Interface  Functions */

void pushArr(struct arrBagStack* b, TYPE v) 
{
	if (b->count < 100) 
	{ 
		b->data[b->count] = v; b->count++; 
	} // check count value 
	else 
	{ 
		printf("stack is %d \n", b->count); 
	} 
}

TYPE topArr(struct arrBagStack* b)
{ 
	assert(!isEmptyArr(b));
	return b->data[b->count - 1];
}

void popArr(struct arrBagStack* b) 
{
	assert(!isEmptyArr(b)); 
	b->data[b->count - 1] = 0; 
	b->count--; 
} 
int isEmptyArr(struct arrBagStack* b) 
{
	if (b->count == 0) 
	{ 
		return 1; 
	} 
	return 0; 
}
/* Bag Interface Functions */

void addArr(struct arrBagStack* b, TYPE v) 
{ 
	if (b->count < 100)
	{ 
		b->data[b->count] = v;
		b->count++; 
	} 
	else
	{ 
		printf("Bag has reached %d \n", b->count);
	} 
} 
int containsArr(struct arrBagStack* b, TYPE v)
{
	for (int i = 0; i < b->count; i++) 
	{
		if (v == b->data[i]) 
		{ 
			return 1;
		} 
	}
	return 0; 
}

void removeArr(struct arrBagStack* b, TYPE v) 
{ 
	for (int i = 0; i < b->count; i++) 
	{ 
		if (b->data[i] == v) 
		{
			b->data[i] = b->data[b->count - 1];
			b->count--; 
		}
	}
}

int sizeArr(struct arrBagStack* b)
{
	return b->count;
}

//WORKSHEET 14
struct DynArr 
{ 
	TYPE* data;	/* pointer to the data array */ 
	int size;	
	int capacity;    
}; 

void initDynArr(struct DynArr* v, int capacity) 
{
	v->data = malloc(sizeof(TYPE) * capacity); 
	assert(v->data != 0);       
	v->size = 0;       
	v->capacity = capacity; 
}   

void freeDynArr(struct DynArr* v) 
{ 
	if (v->data != 0) 
	{ 
		free(v->data);    /* free the space on the heap */   
		v->data = 0;      /* make it point to NULL */
	}   
	v->size = 0;        
	v->capacity = 0; 
}  

int sizeDynArr(struct DynArr* v) 
{
	return v->size;
}   

void addDynArr(struct DynArr* v, TYPE val) 
{          /* Check to see if a resize is necessary */    
	if (v->size >= v->capacity)  
	{ 
		_setCapacityDynArr(v, 2 * v->capacity);
	}
 
	v->data[v->size] = val;        
	v->size++; 
}

void _setCapacityDynArr(struct DynArr* v, int newCap)
{
	assert(v != 0);

	/* Allocate new temporary dynamic array with given cap */  
	TYPE* temp = malloc(sizeof(TYPE) * newCap); 
	assert(temp != 0);          
	/* Copy elements from old array to new array */   
	for (int i = 0; i < v->size; i++) 
	{ 
		temp[i] = v->data[i]; 
	}           
	/* Free the old array */   
	free(v->data);           
	/* Set pointer v to new array */    
	v->data = temp;        
	temp = 0;         
	/* Update the capacity */         
	v->capacity = newCap;
}

TYPE getDynArr(struct DynArr* da, int position)
{ 
	assert(da != 0 && da->size != 0);
	assert(position >= 0 && position < da->size);
	return da->data[position]; 
}

void putDynArr(struct DynArr* da, int position, TYPE value)
{
	assert(da != 0 && da->size != 0);
	assert(position >= 0 && position < da->size);
	da->data[position] = value; 
}

void swapDynArr(struct DynArr* da, int i, int j) 
{
	assert(da != 0 && da->size != 0);
	assert(i >= 0 && i < da->size); 
	assert(j >= 0 && j < da->size); 
	TYPE temp = getDynArr(da, i); 
	putDynArr(da, i, getDynArr(da, j));
	putDynArr(da, j, temp);
}

void removeAtDynArr(struct DynArr* da, int index) 
{
	assert(da != 0 && da->size != 0);
	assert(index >= 0 && index < da->size);

	/* Move all elements up */ 
	for (int i = index; i <= da->size - 1; i++)
	{ 
		putDynArr(da, i, getDynArr(da, i + 1)); 
	} 
	da->size--;
}

/* Dynamic Array implementation of the Stack Interface */ 
void pushDynArr(struct DynArr* da, TYPE e) 
{
	assert(da != 0);
	addDynArr(da, e);
}
TYPE topDynArr(struct DynArr* da) 
{
	assert(da != 0);
	assert(sizeDynArr(da) > 0);  
	return getDynArr(da, sizeDynArr(da) - 1);
}
void popDynArr(struct DynArr* da) 
{
	assert(da != 0);
	assert(sizeDynArr(da) >= 1);
	removeAtDynArr(da, sizeDynArr(da)-1); 
}
int isEmptyDynArr(struct DynArr* da) 
{ 
	assert(da != 0); 
	if (sizeDynArr(da) == 0) 
	{ 
		return 1;	
	}
	return 0;  
}

struct link
{
	TYPE value;
	struct link* next;
};
struct linkedListStack
{
	struct link* firstLink;
};

void linkedListStackInit(struct linkedListStack* s)
{
	s->firstLink = 0;
} 
void linkedListStackFree(struct linkedListStack* s) 
{
	while (!linkedListStackIsEmpty(s)) 
		linkedListStackPop(s); 
}
void linkedListStackPush(struct linkedListStack* s, TYPE d)
{
	struct link* newLink = malloc(sizeof(struct link));
	assert(newLink != 0); 
	newLink->value = d; 
}
TYPE linkedListStackTop(struct linkedListStack* s)
{ 
	assert(s != 0); assert(!linkedListStackIsEmpty(s));
	return s->firstLink->value; 
} 
void linkedListStackPop(struct linkedListStack* s)
{ 
	assert(s != 0); assert(!linkedListStackIsEmpty(s));
	struct link* temp; 
	temp = s->firstLink;
	s->firstLink = s->firstLink->next;
	free(temp); 
	temp = 0; 
}
int linkedListStackIsEmpty(struct linkedListStack* s)
{ 
	assert(s != 0);
	if (s->firstLink == 0) 
	{ 
		return 1; 
	}
	 return 0; 
}

struct listQueue 
{ 
	struct link* firstLink;
	struct link* lastLink;
}; 
void listQueueInit(struct listQueue* q) 
{ 
	struct link* lnk = malloc(sizeof(struct link));
	assert(lnk != 0);
	/* lnk is the sentinel */ 
	lnk->next = 0;  
	q->firstLink = q->lastLink = lnk;
}
void listQueueAddBack(struct listQueue* q, TYPE e)
{
	struct link* newLink = malloc(sizeof(struct link));
	assert(newLink != 0);
	assert(q != 0);
	q->lastLink->next = newLink;
	q->lastLink = newLink;
	newLink->value = e; 
	newLink->next = NULL;
} 
TYPE listQueueFront(struct listQueue* q) 
{
	assert(q != 0); 
	assert(q->firstLink != q->lastLink); 
	return q->firstLink->next->value; 
}
void listQueueRemoveFront(struct listQueue* q) 
{
	assert(q != 0);
	assert(q->firstLink != q->lastLink);
	struct link* temp = q->firstLink->next;
	if (q->firstLink->next == q->lastLink) 
	{
		q->lastLink = q->firstLink; 
		q->firstLink->next = NULL; 
	}
	else { 
		q->firstLink->next = q->firstLink->next->next; 
	}
	free(temp); 
	temp = NULL;
} 
int listQueueIsEmpty(struct listQueue* q) 
{
	assert(q != 0); 
	if (q->firstLink == q->lastLink) 
	{
		return 1;
	} 
	return 0;
}

struct dLink 
{
	TYPE value;
	struct dLink* next;
	struct dLink* prev;
};
struct linkedList
{
	int size; 
	struct dLink* frontSentinel; 
	struct dLink* backSentinel; 
}; 
void linkedListInit(struct linkedList* q) 
{ 
	q->frontSentinel = malloc(sizeof(struct dLink)); 
	assert(q->frontSentinel != 0);
	q->backSentinel = malloc(sizeof(struct dLink));
	assert(q->backSentinel); 
	q->frontSentinel->next = q->backSentinel;
	q->backSentinel->prev = q->frontSentinel; 
	q->size = 0; 
}
void linkedListFree(struct linkedList* q) 
{
	while (q->size > 0) 
		linkedListRemoveFront(q);  
	free(q->frontSentinel); 
	free(q->backSentinel);  
	q->frontSentinel = q->backSentinel = NULL; 
}
void linkedListAddFront(struct linkedList* q, TYPE e)
{
	_addBefore(q, q->frontSentinel->next, e); 
}
void linkedListAddback(struct linkedList* q, TYPE e)
{
	_addBefore(q, q->backSentinel, e);
}
void linkedListRemoveFront(struct linkedList* q) 
{
	assert(q != 0); 
	assert(!linkedListIsEmpty(q)); 
	_removeLink(q, q->frontSentinel->next); 
}
void linkedListRemoveBack(struct linkedList* q) 
{
	assert(q != 0); 
	assert(!linkedListIsEmpty(q));  
	_removeLink(q, q->backSentinel->prev); 
}
int linkedListIsEmpty(struct linkedList* q) 
{
	return q->size == 0; 
}
/* write addBefore and removeLink. Make sure they update the size field correctly */ 
/* _addBefore places a new link BEFORE the provide link, lnk */
void _addBefore(struct linkedList* q, struct dLink* lnk, TYPE e)
{
	struct dLink* newLink = malloc(sizeof(struct dLink)); 
	assert(newLink != 0); assert(q != 0);
	newLink->value = e;   
	newLink->next = lnk;    
	newLink->prev = lnk->prev;   
	lnk->prev->next = newLink;  
	lnk->prev = newLink;   
	q->size++; 
}
void _removeLink(struct linkedList* q, struct dLink* lnk) 
{
	assert(q != 0); 
	lnk->prev->next = lnk->next;  
	lnk->next->prev = lnk->prev;   
	free(lnk);    
	lnk = 0;   
	q->size--;
}
TYPE linkedListFront(struct linkedList* q)
{
	assert(q != 0);
	assert(!linkedListIsEmpty(q)); 
	return q->frontSentinel->next->value;
}

TYPE linkedListBack(struct linkedList* q) 
{
	assert(q != 0); 
	assert(!linkedListIsEmpty(q)); 
	return q->backSentinel->prev->value;
}

void _dequeSetCapacity(struct deque* d, int newCap) 
{
	/* Create a new underlying array*/ 
	TYPE* newData = malloc(sizeof(TYPE) * newCap);
	assert(newData != 0);
	/* copy elements to it */ 
	int j = d->beg;
	for (int i = 0; i < d->size; i++) 
	{
		newData[i] = d->data[j];
		j = j + 1; 
		if (j >= d->capacity) 
			j = 0;
	}
	/* Delete the old underlying array*/ 
	free(d->data); 
	/* update capacity and size and data*/
	d->data = newData;
	d->capacity = newCap;
	d->beg = 0;
} 
void dequeFree(struct deque* d)
{
	free(d->data); 
	d->size = 0;
	d->capacity = 0;
}
struct deque 
{
	TYPE* data; 
	int capacity;  
	int size; 
	int beg; 
};
void dequeInit(struct deque* d, int initCapacity) 
{
	d->size = d->beg = 0; 
	d->capacity = initCapacity;
	assert(initCapacity > 0);
	d->data = malloc(initCapacity * sizeof(TYPE)); 
	assert(d->data != 0);
}
int dequeSize(struct deque* d)
{
	return d->size;
}
void dequeAddFront(struct deque* d, TYPE newValue) 
{
	assert(d != 0);
	if (d->size >= d->capacity) 
		_dequeSetCapacity(d, 2 * d->capacity); 
	d->beg--;
	if (d->beg < 0) 
	{
		d->beg = d->capacity - 1;
	} 
	d->data[d->beg] = newValue;
	d->size++; 
}
void dequeAddBack(struct deque* d, TYPE newValue)
{
	assert(d != 0); 
	if (d->size >= d->capacity) 
		_dequeSetCapacity(d, 2 * d->capacity);
	int index = d->beg + d->size;
	if (index >= d->capacity) 
	{
		index -= d->capacity; 
	}
	d->data[index] = newValue; d->size++;
}
TYPE dequeFront(struct deque* d)
{
	assert(d != 0); 
	assert(d->size > 0);
	return d->data[d->beg];
}
TYPE dequeBack(struct deque* d) 
{
	assert(d != 0);
	assert(d->size > 0);
	int index = d->beg + (d->size - 1);
	if (index >= d->capacity) 
	{
		index -= d->capacity;
	}
	return d->data[index]; 
}
void dequeRemoveFront(struct deque* d) 
{
	assert(d != 0); 
	assert(d->size > 0);
	d->beg++; 
	if (d->beg >= d->capacity)
	{
		d->beg = 0;
	}
	d->size--; 
}
void dequeRemoveBack(struct deque* d)
{
	assert(d != 0);
	assert(d->size > 0);
	d->size--; 
}

void removeDynArr(struct DynArr* da, TYPE test)
{
	int i;
	for (i = 0; i < da->size; i++)
	{
		if (EQ(test, da->data[i]))
		{ 
			/* found it */ 
			removeAtDynArr(da, i);
			return; 
		}
	} 
}

int containsDynArr(struct DynArr* da, TYPE e)
{
	assert(!isEmptyDynArr(da));
	for (int i = 0; i < da->size; i++) 
	{
		if (EQ(e, da->data[i])) 
		{
			return 1;
		}
	}
	return 0;
}
void linkedListAdd(struct linkedList* lst, TYPE e) 
{
	_addBefore(lst, lst->frontSentinel->next, e);
}
int linkedListContains(struct linkedList* lst, TYPE e)
{
	assert(lst != 0); 
	assert(!linkedListIsEmpty(lst)); 
	int containsVal = 0;
	struct dLink* incLink = lst->frontSentinel->next;
	while (incLink != lst->backSentinel && containsVal == 0) 
	{
		if (incLink->value == e) 
		{
			containsVal = 1; 
		}
		incLink = incLink->next;
	}
	return containsVal;
}
void linkedListRemove(struct linkedList* lst, TYPE e) 
{
	assert(lst != 0); 
	assert(!linkedListIsEmpty(lst));
	struct dLink* incLink = lst->frontSentinel->next;
	while (incLink != lst->backSentinel) 
	{
		if (incLink->value == e) 
		{
			_removeLink(lst, incLink);
			return;
		}
		incLink = incLink->next; 
	}
}

struct DynArrIterator
{ 
	struct DynArr* da; 
	int currentIndex; 
};

void dynArrIteratorInit(struct DynArr* da, struct DynArrIterator* itr)
{
	assert(itr != 0);
	assert(da != 0);
	itr->da = da; itr->currentIndex = -1;
}

int dynArrIteratorHasNext(struct DynArrIterator* itr)
{
	int hasNext = 0;
	if (itr->currentIndex < itr->da->size - 1)
	{
		hasNext = 1;
	}
	return hasNext;
}

TYPE dynArrIteratorNext(struct DynArrIterator* itr) 
{
	assert(itr != 0); 
	return itr->da->data[++itr->currentIndex];
}

void dynArrIteratorRemove(struct DynArrIterator* itr)
{
	assert(itr != 0);
	removeAtDynArr(itr->da, itr->currentIndex);
	itr->currentIndex--;
}

struct linkedListIterator
{
	struct linkedList* lst;
	struct dLink* currentLink;
};

void linkedListIteratorInit(struct linkedList* lst, struct linkedListIterator* itr)
{
	itr->lst = lst; 
	itr->currentLink = itr->lst->frontSentinel;
}
void _removeLink(struct linkedList* lst, struct dLink* lnk);

int linkedListIteratorHasNext(struct linkedListIterator* itr)
{
	assert(itr != 0); 
	int hasNext = 0; 
	if (itr->currentLink->next != itr->lst->backSentinel)
	{
		hasNext = 1;
	} 
	return hasNext;
}
TYPE linkedListIteratorNext(struct linkedListIterator* itr) 
{
	itr->currentLink = itr->currentLink->next;
	return itr->currentLink->value;
}
void linkedListIteratorRemove(struct linkedListIterator* itr) 
{
	struct dLink* temp = itr->currentLink;
	itr->currentLink = itr->currentLink->prev; 
	_removeLink(itr->lst, temp);
}
int binarySearch(TYPE* data, int size, TYPE testValue)
{
	int low = 0;
	int high = size;
	int mid;  
	while (low < high) 
	{ 
		mid = (low + high) / 2;
		if(LT(data[mid], testValue))
			low = mid + 1;
		else
			high = mid; 
	}
	return low; 
}

void dynArrAddAt(struct DynArr* da, int index, TYPE newElement)
{  
	assert(index >= 0 && index <= da->size);   
	if (da->size >= da->capacity) 
		_setCapacityDynArr(da, 2 * da->capacity);
	for (int i = (da->size - 1); i >= index; i--)
	{
		da->data[i + 1] = da->data[i]; 
	}
	da->data[index] = newElement;
	da->size++;
}
void orderedArrAdd(struct DynArr* da, TYPE newElement) 
{
	int index = binarySearch(da->data, da->size, newElement);
	dynArrAddAt(da, index, newElement); 
}

int dynArrBinarySearch(struct DynArr* da, TYPE testValue) 
{
	return binarySearch(da->data, da->size, testValue);
}
void orderedArrAdd(struct DynArr* da, TYPE newElement) 
{
	int index = binarySearch(da->data, da->size, newElement);
	dynArrAddAt(da, index, newElement);		/* takes care of resize if necessary*/ 
}


int orderedArrContains(struct DynArr* da, TYPE testElement) 
{
	assert(da != 0);
	assert(da->size != 0); 
	int contains = 0;  
	int index = dynArrBinarySearch(da, testElement); 
	if (index <= da->size - 1 && da->data[index] == testElement)
	{ 
		contains = 1; 
	}
	return contains;
}
void orderedArrRemove(struct DynArr* da, TYPE testElement) {
	assert(da != 0);  
	assert(da->size != 0); 
	int index = dynArrBinarySearch(da, testElement);
	if (index <= da->size - 1 && da->data[index] == testElement) 
	{
		removeAtDynArr(da, index);
	}
}


//WORKSHEET 29
struct Node 
{ 
	TYPE value;
	struct Node* left;  
	struct Node* right; 
};

struct BSTree 
{
	struct Node* root; 
	int size; 
};

void initBST(struct BSTree* tree) 
{
	tree->size = 0; 
	tree->root = 0;
}
void addBST(struct BSTree* tree, TYPE newValue) 
{
	tree->root = _nodeAddBST(tree->root, newValue);
	tree->size++;
}
int sizeBST(struct BSTree* tree) 
{
	return tree->size;
}

struct Node* _nodeAddBST(struct  Node* current, TYPE newValue) 
{
	assert(newValue != NULL);
	/* base case: the current node is NULL (the supplied tree is empty), so make a new node, 
	set the fields, and return a pointer to that node */ 
	if (current == 0) 
	{
		struct Node* newNode = malloc(sizeof(struct Node));  
		assert(newNode != 0);  
		newNode->left = newNode->right = 0;  
		newNode->value = newValue;   
		return newNode;
	}
	/*  if current is an actual node, check if the new node is supposed to 
	be left of the current node or right of it (less than current's value or not) */ 
	if (newValue < current->value)  
		current->left = _nodeAddBST(current->left, newValue);
	/* when newValue goes to the left subtree, set the current node's left child
	to be that same subtree, but with the value added in the right location */
	else    
		current->right = _nodeAddBST(current->right, newValue); 
	/* when newValue goes to the right subtree, set the current node's right child
	to be that same subtree, but with the value added in the right location
	now that the proper child of the current node has been changed to have the 
	added value, return that current node this is required because the function's job 
	is to return a pointer to the argument node, but with the added value included 
	somewhere below (or at) that node */ 
	return current;
}


int containsBST(struct BSTree* tree, TYPE d) 
{
	assert(tree != NULL);
	assert(d != NULL);

	struct Node* searchNode = tree->root;
	while (searchNode != NULL) 
	{
		if (searchNode->value == d) 
			return 1; //Return true if found
		else if (d < searchNode->value)
			searchNode = searchNode->left; 
		else 
			searchNode = searchNode->right;
	}  
	return 0; //Return false if not found 
} 
void removeBST(struct BSTree* tree, TYPE d) 
{
	if (containsBST(tree, d))
	{
		tree->root = _nodeRemoveBST(tree->root, d);
			tree->size--; 
	}
}

TYPE _leftMostChild(struct Node* current)
{
	assert(current != NULL);

	while (current->left != NULL)
	{
		current = current->left; 
	}
	return current->value;
}
struct Node* _removeLeftmostChild(struct Node* current)
{

	// returns a node pointer to the starting sub-tree but with its left most child removed 
	assert(current != NULL);
	/*base case: the supplied tree has no left child, so we know that the supplied tree *is* 
	the most left child, which means we can just remove it */
	if (current->left == NULL) 
	{
		struct node* temp = current->right;
		free(current); 
		return temp; 
	} 
	/* if there is a left child, set the left child pointer to point to the left child 
	sub-tree, but with its left most child removed */ 
	else 
	{ 
		current->left = _removeLeftmostChild(current->left);
	}
	return current;
}

struct Node* _nodeRemoveBST(struct Node* current, TYPE d) 
{
	assert(current != NULL); 
	assert(d != NULL);
	/* base case: the supplied node *is* the node we want to remove. There are two
	cases to handle: there is no right child, and there is a right child */
	
	if (current->value == d)
	{
		if (current->right == NULL)
		{ 
			/* if there isn't a right child for this node, we can simply free the data for
			    the current node and return the left child (it needs to move into the current
				node's spot) */ 
			struct Node* tempNode = current->left;
			free(current); 
			return tempNode;
		} 
		else 
		{
			current->value = _leftMostChild(current->right); 
			current->right = _removeLeftmostChild(current->right);
		}
	}
	// Else if value is less than current value 
	else if (d < current->value)
	{
		current->left = _nodeRemoveBST(current->left, d); 
	} 
	// Else value is greater than current value
	else
	{
		current->right = _nodeRemoveBST(current->right, d);
	}
	return current; 
}
	
//WORKSHEET 30 TYPE needs to be defined as a DynArr*
struct BSTIterator 
{
	struct DynArr* stk;
	struct BSTree* tree; 
};
void BSTIteratorInit(struct BSTree* tree, struct BSTIterator* itr)
{
	itr->tree = tree;
	struct DynArr* newDynArr;
	itr->stk = newDynArr;  /* Dyn arr imp of a stack */ 
}
int BSTIteratorHasNext(struct BSTIterator* itr) {
	struct Node* n;
	if (isEmptyDynArr(itr->stk))
	{
		_slideLeft(itr->tree->root, itr);
	}
	else
	{
		n = topDynArr(itr->stk);
		popDynArr(itr->stk);
		_slideLeft(n->right, itr);
	}
	if (!isEmptyDynArr(itr->stk))
	{
		return 1;
	}
	return 0;
}

TYPE BSTIteratorNext(struct BSTIterator* itr) {
	return topDynArr(itr->stk);
}

void _slideLeft(struct Node* cur, struct BSTIterator* itr)
{
	while(cur != NULL) 
	{
		pushDynArr(itr->stk, cur); 
		cur = cur->left; 
	} 
}

//WORKSHEET 31
//Added struct AVLTree definition, containsAVLTree, AVLTreeInit
struct AVLTree
{
	struct AVLNode* root;
	int size;
};

struct AVLNode 
{
	TYPE value;
	struct AVLNode* left;
	struct AVLNode* right;
	int height;
};

void AVLTreeInit(struct AVLTree* tree)
{
	tree->root = 0;
	tree->size = 0;
}

int _h(struct AVLNode* current)
{
	if (current == 0)
		return -1;  
	return current->height;
}

void _setHeight(struct AVLNode* current) 
{
	int lch = _h(current->left);
	int rch = _h(current->right);
	if (lch < rch) 
		current->height = 1 + rch;
	else 
		current->height = 1 + lch; 
}

struct AVLNode* _AVLNodeAdd(struct AVLNode* current, TYPE newValue) 
{
	struct AVLNode* newnode;
	if (current == 0) 
	{
		newnode = (struct AVLNode*) malloc(sizeof(struct AVLNode));
		assert(newnode != 0);  
		newnode->value = newValue; 
		newnode->left = newnode->right = 0;
		return newnode;  //why don�t we balance here ?? 
	} 
	else if (LT(newValue, current->value))   
		current->left = _AVLNodeAdd(current->left, newValue); 
	else 
		current->right = _AVLNodeAdd(current->right, newValue); 
	return _balance(current);    /* <-   NEW  the call on balance */ 
}

int _bf(struct AVLNode* current) { return _h(current->right) - _h(current->left); }

struct AVLNode* _balance(struct AVLNode* current) 
{
	int cbf = _bf(current);       
	if (cbf < -1) 
	{
		if (_bf(current->left) > 0) // double rotation
			current->left = _rotateLeft(current->left);
		return _rotateRight(current); // single rotation 
	} else if (cbf > 1)
	{
		if (_bf(current->right) < 0) 
			current->right = _rotateRight(current->right); 
		return _rotateLeft(current); 
	}
	_setHeight(current); 
	return current;    
}

struct AVLNode* _rotateLeft(struct AVLNode* current)
{ 
	struct AVLNode* newtop = current->right;
	current->right = newtop->left;
	newtop->left = current;
	_setHeight(current); 
	_setHeight(newtop);  
	return newtop; 
}


struct AVLNode* _rotateRight(struct AVLNode* current) 
{ 
	struct AVLNode* newtop = current->left; 
	current->left = newtop->right;  
	newtop->right = current; 
	_setHeight(current);
	_setHeight(newtop); 
	return newtop; 
}
void removeAVLTree(struct AVLTree* tree, TYPE val) 
{
	if (containsAVLTree(tree, val)) 
	{ 
		tree->root = _removeNode(tree->root, val);  
		tree->size--;
	}
}

TYPE _leftMost(struct AVLNode* cur) 
{
	assert(cur != NULL);
	while (cur->left != NULL) 
	{
		cur = cur->left;
	}     
	return cur->value;
}

struct AVLNode* _removeLeftmost(struct AVLNode* cur) 
{
	assert(cur != NULL); 
	struct AVLNode* temp;
	if (cur->left == NULL)
	{
		temp = cur->right;  
		free(cur);
		return temp; 
	}
	else
	{ 
		cur->left = _removeLeftmost(cur->left);
		return _balance(cur);
	}
}

struct AVLNode* _removeNode(struct AVLNode* cur, TYPE val) 
{
	assert(cur != NULL);
	assert(val != NULL);
	struct AVLNode* temp;
	if (cur->value == val)
	{
		if (cur->right == NULL)
		{
			temp = cur->left;
			free(cur);
			return temp;
		}
		else
		{
			cur->value = _leftMost(cur->right);
			cur->right = _removeLeftmost(cur->right);
		}
	}
	else if (val < cur->value) 
	{
		cur->left = _removeNode(cur->left, val);
	}
	else 
	{
		cur->right = _removeNode(cur->right, val);
	}
	return _balance(cur);
}

int containsAVLTree(struct AVLTree* tree, TYPE d)
{
	assert(tree != NULL);
	assert(d != NULL);

	struct AVLNode* searchNode = tree->root; 
	while (searchNode != NULL)
	{
		if (searchNode->value == d)
			return 1; //Return true if found
		else if (d < searchNode->value)
			searchNode = searchNode->left;
		else
			searchNode = searchNode->right;
	}
	return 0; //Return false if not found 
}


//WORKSHEET 32 Iterative
//Added AVLIterator, AVLIteratorHasNext

struct AVLIterator
{
	struct AVLNode* stk;
	struct AVLTree* tree;
};


void treeSort(TYPE* data, int n)
{ 
	/* sort values in array data */
	struct AVLTree* tree;  
	struct AVLIterator* itr;
	int count = 0;
	AVLTreeInit(tree);  
	for (int i = 0; i < n; i++)
	{
		_AVLNodeAdd(tree->root, data[i]);
	}
	/* assuming you have an iterator */
	AVLIteratorInit(&tree, &itr);   
	while (AVLIteratorHasNext(&itr)) 
	{
		data[count] = AVLIteratorNext(&itr);
		count = count + 1;
	}
}


//WORKSHEET 32 Recursive
void treeSort(TYPE* data, int n) 
{
	/* sort values in array data */    
	struct AVLTree*  tree;
	int count = 0;
	AVLTreeInit(tree);
	for (int i = 0; i < n; i++)
		_AVLNodeAdd(tree->root, data[i]);
	/* Assuming no iterator */ 
	_treeSortHelper(tree->root, data, &count);
}

void _treeSortHelper(struct AVLNode* cur, TYPE* data, int* count) 
{ 
	if (cur != 0) 
	{
		_treeSortHelper(cur->left, data, count); 
		data[*count] = cur->value;
		*count = *count + 1;
		_treeSortHelper(cur->right, data, count);
	}
}


//WORKSHEET 33
void HeapRemoveFirst(struct	DynArr* heap)
{
	int	last = sizeDynArr(heap) - 1;
	assert(sizeDynArr(heap) > 0);
	/*	make sure we have at least one element*/	
	/*	Copy the last element to the first position*/	
	putDynArr(heap, 0, getDynArr(heap, last));
	removeAtDynArr(heap, last);		/*	Remove last element.*/
	_adjustHeap(heap, last, 0);		/*	Rebuild	heap*/ }

void _adjustHeap(struct	DynArr* heap, int max, int	pos)
{
	int	leftChild = 2 * pos + 1;
	int	rightChild = 2 * pos + 2;

}
void swap(struct	DynArr* v, int	i, int	j)
{
		/*	swap elements i j*/
	TYPE	temp = getDynArr(v, i);
	putDynArr(v, i, getDynArr(v, j));
	putDynArr(v, j, temp); 
}

int	indexSmallest(struct DynArr* v, int	i, int j) 
{
	/*	return index of smallest element	*/	
	if (LT(getDynArr(v, i), getDynArr(v, j)))
		return	i;	
		return	j;
}
TYPE heapGetFirst(struct	DynArr* heap) 
{ 
	assert(sizeDynArr(heap) > 0);
	return getDynArr(heap, 0);
}
void HeapRemoveFirst(struct	DynArr* heap)
{
	int	last = sizeDynArr(heap) - 1;
	assert(sizeDynArr(heap) > 0);	
	/* make sure we have at least one element */
	/* Copy the last element to the first position	*/		
	putDynArr(heap, 0, getDynArrr(heap, last));	
	removeAtDynArr(heap, last);						
	/* Remove last element.*/				
	_adjustHeap(heap, last, 0);/* Rebuild heap */ 
}

void _adjustHeap(struct DynArr* heap, int max, int pos)
{
	int leftChild = 2 * pos + 1;
	int rightChild = 2 * pos + 2;
	if (rightChild < max) 
	{
		/* we have two children */
		/* get index of smallest child */ 
		int smallest = indexSmallest(heap, leftChild, rightChild);
		if (heap->data[pos] > heap->data[smallest]) 
		{ 
			/* swap with smallest child */
			swap(heap, pos, smallest);
			_adjustHeap(heap, max, smallest);
		}
	}
	else if (leftChild < max)
	{
		/* we have one child */ 
		if (heap->data[pos] > heap->data[leftChild])
		{ 
			/* swap with smallest child */ 
			swap(heap, pos, leftChild);
			_adjustHeap(heap, max, leftChild); 
		}
	} /* else no children, done */
}
void heapAdd(struct DynArr* heap, TYPE newValue) 
{
	addDynArr(heap, newValue); /* adds to end - now need to adjust position */
	int parent; int pos = sizeDynArr(heap) - 1;
	while (pos != 0) 
	{
		parent = (pos - 1) / 2; 
		if (heap->data[pos] < heap->data[parent])
		{ swap(heap, parent, pos);
		pos = parent;
		}
		else
		{
			return;
		}
	}
}


//WORKSHEET 36
#ifndef DYARRAYDICTH 
#define DYARRAYDICTH 
#endif
/*  dynamic array dictionary interface file */
#ifndef KEYTYPE
#define KEYTYPE char * 
#endif 
#ifndef VALUETYPE
#define VALUETYPE double 
#endif 

struct association
{
	KEYTYPE key;
	VALUETYPE value;
};

//#define TYPE struct association* 
//#include "dynamicArray.h" 
/* dictionary */ 
void dynArrDictionaryGet (struct DynArr *da, KEYTYPE key, VALUETYPE valptr); 
void dynArrDictionaryPut (struct DynArr * da, KEYTYPE key, VALUETYPE val); 
int dynArrDictionaryContainsKey (struct DynArr * da, KEYTYPE key);
void dynArrDictionaryRemoveKey(struct DynArr* da, KEYTYPE key); 
//#endif
//#include "dyArrayDictionary.h"
//#include "dyArrayDictionary.c" 
/*finds and places the value associated with key in valptr */
void dynArrDictionaryGet(struct DynArr* da, KEYTYPE key, VALUETYPE* valptr) 
{
	for (int i = 0; i < da->size; i++)
	{
		if (strcmp(da->data[i], key) == 0)
		{
			valptr = da->data[i];
		}
	}
}

void dynArrDictionaryPut(struct DynArr* da, KEYTYPE key, VALUETYPE val)
{
	struct association* ap;
	if (dynArrDictionaryContainsKey(da, key))
	{
		dynArrDictionaryRemoveKey(da, key);
		ap = malloc(sizeof(struct association));
		assert(ap != 0);
		ap->key = key;
		ap->value = val;
		dyArrayAdd(da, ap);
	}
}
int dyArrayDictionaryContainsKey(struct DynArr* da, KEYTYPE key) 
{
	for (int i = 0; i < da->size; i++) 
	{
		//Assuming dynArr has struct association called 'data'
		if (strcmp(key, da->data[i]) == 0)
		{
			return 1;
		}
	} 
	return 0;
}

//WORKSHEET 37
struct openHashTable 
{ 
	TYPE** table;
	int tableSize;
	int count;
};

void initOpenHashTable(struct openHashTable* ht, int size) 
{
	assert(size > 0);
	ht->table = malloc(size * sizeof(TYPE*));  
	assert(ht->table != 0);  
	for (int i = 0; i < size; i++)
	{
		ht->table[i] = 0; 	/* initialize empty */
	}
	ht->tableSize = size;
	ht->count = 0; 
}

int openHashTableSize(struct openHashTable* ht) 
{
	return ht->count; 
}


void openHashTableAdd(struct openHashTable* ht, TYPE* newValue)
{
	int index;
	ht->count++;  /* Make sure we have space and under the load factor threshold*/
	if ((ht->count / (double)ht->tableSize) > 0.75)
	{
		_resizeOpenHashTable(ht);
	}
	index = HASH(newValue) % ht->tableSize;
	if (index < 0)
	{
		index += ht->tableSize;
	}
	while(index >= 0)
	{
		if (index == ht->tableSize)
		{
			index = 0;
		}
		else if (ht->table[index] == 0)
		{
			ht->table[index] = newValue;
			index = -1;
		}
		else
		{
			index++;
		}
	}
}

int openHashTableBagContains(struct openHashTable* ht, TYPE  newValue)
{
	int index;
	index = HASH(newValue) % ht->tableSize;
	if (index < 0)
		index += ht->tableSize;
	while (ht->table[index] != 0)
	{
		if (compare(ht->table[index], newValue) == 0)
			return 1;
		index++;
		if (index == ht->tableSize)
			index = 0;
	}
	return 0;
}

void _resizeOpenHashTable(struct openHashTable* ht)
{
	int oldSize = ht->tableSize;
	int newSize = 2 * oldSize;
	TYPE** temp = ht->table;
	initOpenHashTable(ht, newSize);
	for (int i = 0; i < oldSize; i++)
	{
		if (temp[i] != 0)
		{
			openHashTableAdd(ht, temp[i]);
		}
	}
	free(temp);
}

//WORKSHEET 38
struct hlink 
{ 
	TYPE value;
	struct hlink* next;
};
struct hashTable {
	struct hlink** table; 
	int tableSize;
	int count;
};
void initHashTable(struct hashTable* ht, int size) 
{
	assert(size > 0);
	ht->table = malloc(sizeof(struct hlink*) * size);
	assert(ht->table != 0);
	for (int i = 0; i < size; i++) 
	{
		ht->table[i] = 0; } 
	ht->tableSize = size; 
	ht->count = 0;
}
int hashTableSize(struct hashTable* ht) 
{
	return ht->count; 
}
void hashTableAdd(struct hashTable* ht, TYPE newValue) {
	/* Compute hash value to find the correct bucket */ 
	int hashIndex = HASH(newValue) % ht->tableSize;
	if (hashIndex < 0) hashIndex += ht->tableSize;
	struct hlink* newLink = malloc(sizeof(struct hlink)); 
	assert(newLink); 
	newLink->value = newValue; 
	newLink->next = ht->table[hashIndex]; 
	ht->table[hashIndex] = newLink;
	/* add to bucket*/
	ht->count++; 
	if ((ht->count / (double)ht->tableSize) > 8.0)
		_resizeHashTable(ht);
}

int hashTableContains(struct hashTable* ht, TYPE testElement)
{
	assert(ht != 0); 
	assert(ht->table != 0);
	/* Compute hash value to find the correct bucket */ 
	int hashIndex = HASH(testElement) % ht->tableSize;
	/* Set a current link to the beginning of the list that has been hashed */
	struct hlink* current = ht->table[hashIndex];
	while (current != 0) 
	{
		if (strcmp(current->value, testElement) == 0)
			return 1; 
		current = current->next; 
	} 
	return 0;
}
void hashTableRemove(struct hashTable* ht, TYPE testElement) {
	/* Compute hash value to find the correct bucket */
	int hashIndex = HASH(testElement) % ht->tableSize; 
	if (hashIndex < 0) hashIndex += ht->tableSize;
	/* Set a current link to the beginning of the list that has been hashed and previous position */
	struct hlink* current = ht->table[hashIndex]; 
	struct hlink* prev = 0;
	/* While the link is not null */ 
	while (current != 0) 
	{
		/* Determine if the current link is the value being searched for */
		if (strcmp(current->value, testElement) == 0)
		{
			/* if value is found at first entry, set beginning to the next entry */ 
			if (prev == 0) 
			{
				ht->table[hashIndex] = current->next;
			} /* if value is in the middle, link previous and next */
			else
			{
				prev->next = current->next; 
			}
			/* delete link and decrement count, end function */ 
			free(current); 
			ht->count--; return;
		} 
		/* move forward through links */
		prev = current; 
		current = current->next;
	}
}
void resizeTable(struct hashTable* ht)
{
	/* Create new table with twice the size */ 
	struct hashTable* newTable; 
	initHashTable(newTable, ht->tableSize * 2);
	struct hlink* current;
	/* Loop through old table and traverse links. Add value to new table */
	for (int i = 0; i < ht->tableSize; i++) 
	{
		current = ht->table[i]; 
		while (current != 0) 
		{
			hashTableAdd(newTable, current->value);
			current = current->next; 
		}
	} /* Delete old hash table. Set old table value equal to new table. */
	free(ht->table);
	free(ht);
	ht = newTable; 
	newTable = 0;
}

void hashTableAdd(struct hashTable* ht, TYPE newValue)
{
	//compute hash value to find the correct bucket 
	int hashIndex = HASH(newValue) % ht->tableSize; 
	if (hashIndex < 0) hashIndex += ht->tableSize; 
	struct hlink * newLink = malloc(sizeof(struct hlink)); 
	assert(newLink);
	newLink->value = newValue;
	newLink->next = ht->table[hashIndex];
	ht->table[hashIndex] = newLink; 
	/* add to bucket */
	ht->count++; 
	if ((ht->count / (double) ht->tableSize) > 8.0)
		resizeTable(ht); 
}