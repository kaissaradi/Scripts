void treeSort (TYPE *data, int n){ 
    AVLtree tree;
    AVLIterator itr;
    int count = 0;
    AVLtreeInit (&tree);
    for(int i = 0; i < n ; i++){
        AVLAddTree(&tree, data[i]);
    }
    AVLIteratorInit(&tree, &itr);
    while(AVLIteratorHasNext(&itr))
    {
        data[count] = AVLIteratorNext(&itr);
        count++;
    }
}

