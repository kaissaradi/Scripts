#define TYPE int

struct hlink {
    TYPE value;
    struct hlink *next;
};
 
struct hashTable {
    struct hlink ** table;
    int tablesize;
    int count;
};


void initHashTable (struct hashTable * ht, int size) {
    /* Assert that the size is greater than zero */
    assert (size > 0);
    /* Allocate the table to hold the pointers to the linked list */
    ht->table = malloc(sizeof(struct hlink*) * size);
    /* Assert that the table was created correctly */
    assert(ht->table != 0);
    /* For each element in the table */
    int i;
    for (i = 0; i < size; i++) {
    /* Initialize the table index as empty */
    ht->table[i] = 0;
    }
    /* Set the table size to empty */
    ht->tablesize = size;
    /* Set the count to empty */
    ht->count = 0;
}

int hashTableSize (struct hashTable * ht) { return ht->count; }

void hashTableAdd (struct hashTable *ht, TYPE newValue) {
//compute hash value to find the correct bucket
    int hashIndex = HASH(newValue) % ht->tablesize;
    if (hashIndex < 0) hashIndex += ht->tablesize;
    struct hlink * newLink = (struct hlink *) malloc(sizeof(struct hlink));
    assert(newLink);
    newLink->value = newValue;
    newLink->next = ht->table[hashIndex];
    ht->table[hashIndex] = newLink; /* add to bucket */
    ht->count++;
    if ((ht->count / (double) ht->tablesize) > 8.0) _resizeHashTable(ht);
}

int hashTableContains (struct hashTable * ht, TYPE testElement) {
    /* Assert that the table and value are not null */
    assert(ht != 0);
    assert(testElement 0);
    /* Compute hash value to find the correct bucket */
    int hashIndex = HASH(testElement) % ht->tablesize;
    /* Set a current link to the beginning of the list that has been hashed */
    struct hlink *current = ht->table[hashIndex];
    /* While the link is not null */
    while (current !=0) {
    /* Determine if the current link is the value being searched for */
    if (strcmp(current->value, testElement) == 0) {
    /* return true if found */
    return 1;
    }
    /* Move to the next link */
    current = current->next;
    }
    /* Return false if reached end of list without finding */
    return 0;
}
 
void hashTableRemove (struct hashTable * ht, TYPE testElement) {
    /* Compute hash value to find the correct bucket */
    int hashIndex = HASH(testElement) % ht->tablesize;
    if (hashIndex < 0) hashIndex += ht->tablesize; 

    /* Set a current link to the beginning of the list that has been hashed and previous position */
    struct hlink * current = ht->table[hashIndex];
    struct hlink * prev = 0;

    /* While the link is not null */
    while (current !=0) {
        /* Determine if the current link is the value being searched for */
        if (strcmp(current->value, testElement) == 0) {
            /* if value is found at first entry, set beginning to the next entry */
            if(prev == 0) {
                ht->table[hashIndex] = current->next;
            }

            /* if value is in the middle, link previous and next */
            else {
                prev->next = current->next;
            }

            /* delete link and decrement count, end function */
            free(current);
            ht->count--;
            return;
        }
        /* move forward through links */
        prev = current;
        current = current->next;
    }
}


void resizeTable (struct hashTable *ht) {
    /* Create new table with twice the size */
    struct hashTable *newTable;
    initHashTable(newTable, ht->tablesize * 2);
    struct hlink * current;

    /* Loop through old table and traverse links. Add value to new table */
    for(int i=0; i<ht->tablesize; i++) {
        current = ht->table[i];
        while(current != 0) {
            hashTableAdd(newTable, current->value);
            current = current->next;
        }
    }

    /* Delete old hash table. Set old table value equal to new table. */
    free(ht->table);
    free(ht);
    ht = newTable;
    newTable = 0;
}
 

