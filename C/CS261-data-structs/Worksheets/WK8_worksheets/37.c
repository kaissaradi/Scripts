#define TYPE

struct openHashTable {
 TYPE ** table;
 int tablesize;
 int count;
};

void initOpenHashTable (struct openHashTable * ht, int size) {
    int i;
    assert (size > 0);
    ht->table = (TYPE **)malloc(size * sizeof(TYPE *));
    assert(ht->table != 0);
    for (i = 0; i < size; i++)
        ht->table[i] = 0; /* initialize empty */
    ht->tablesize = size;
    ht->count = 0;
}

int openHashTableSize (struct openHashTable *ht) { return ht->count; }

void openHashTableAdd (struct openHashTable * ht, TYPE newValue) {
    int idx;
    /* Make sure we have space and under the load factor threshold*/
    if ((ht->count / (double) ht->tablesize) > 0.75)
    _resizeOpenHashTable(ht);
    ht->count++;
    idx = HASH(newValue) % ht->tablesize;

    /* To be safe, use only positive arithmetic. % may behave very differently on diff
    implementations or diff languages . However, you can do the following to deal with a
    negative result from HASH */
    if (idx < 0) idx += ht->tablesize;
}
 
int openHashTableBagContains (struct openHashTable *ht, TYPE newValue) {
    int idx;
    idx = HASH(newValue) % ht->tablesize;
    if (idx < 0) idx += ht->tablesize;


}

void _resizeOpenHashTable (struct openHashTable *ht) {

 }

 int openHashTableBagContains (struct openHashTable *ht, TYPE  newValue) {

    int idx; 

    idx = HASH(newValue) % ht->tablesize;
        if (idx < 0) idx += ht->tablesize;


    //check if value is at index, else loop until NULL is found
    if (*(ht->table[idx]) == newValue){
        return 1;
    } else {
        int i = idx + 1;

        while (ht->table[idx] != NULL){ //loop through array until empty location (NULL) is found

            if (i == ht->tablesize){ //restart at beginning of array if reached end
                i = 0;
            }

            if (*(ht->table[idx]) == newValue){//if value is found, return true
               return 1;
            }
            i++;
        }
    }

    return 0; //otherwise value is not in table and return false
}

void _resizeOpenHashTable (struct openHashTable *ht) {


TYPE ** oldTable = ht->table;

   int i;

   ht->table = (TYPE **) malloc(ht->tablesize * 2 * sizeof(TYPE *));
   assert(ht->table != 0);

   ht->tablesize = ht->tablesize * 2; //assign new size

   for (i = 0; i < ht->tablesize; i++){
        ht->table[i] = 0; /* initialize empty */
   }

   for (i = 0; i < ht->tablesize; i++){
        ht->table[i] = oldTable[i]; /* copy old array values */
   }

   free(oldTable); //free old array from memory

}

 
 
 
