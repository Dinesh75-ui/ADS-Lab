#include <stdio.h>
#include <stdlib.h>

#define T 2

typedef struct BTree {
    int key[2 * T - 1];
    struct BTree *child[2 * T];
    int n;
    int leaf;
} BTree;

/* Create a new node */
BTree *create(int leaf) {
    BTree *p = malloc(sizeof(BTree));

    p->n = 0;
    p->leaf = leaf;

    return p;
}

/* Traverse B-Tree */
void traverse(BTree *root) {
    int i;

    for (i = 0; i < root->n; i++) {

        if (!root->leaf)
            traverse(root->child[i]);

        printf("%d ", root->key[i]);
    }

    if (!root->leaf)
        traverse(root->child[i]);
}

/* Split a full child */
void split(BTree *parent, int pos) {

    BTree *old = parent->child[pos];
    BTree *new = create(old->leaf);

    int i;

    /* Move last T-1 keys to new node */
    new->n = T - 1;

    for (i = 0; i < T - 1; i++)
        new->key[i] = old->key[i + T];

    /* Move children if not leaf */
    if (!old->leaf) {
        for (i = 0; i < T; i++)
            new->child[i] = old->child[i + T];
    }

    // Reduce old node 
    old->n = T - 1;

    /* Shift parent's children */
    for (i = parent->n; i >= pos + 1; i--)
        parent->child[i + 1] = parent->child[i];

    parent->child[pos + 1] = new;

    /* Shift parent's keys */
    for (i = parent->n - 1; i >= pos; i--)
        parent->key[i + 1] = parent->key[i];

    /* Move middle key to parent */
    parent->key[pos] = old->key[T - 1];

    parent->n++;
}

/* Insert into a non-full node */
void insertNonFull(BTree *root, int value) {

    int i = root->n - 1;

    /* If node is a leaf */
    if (root->leaf) {

        while (i >= 0 && value < root->key[i]) {
            root->key[i + 1] = root->key[i];
            i--;
        }

        root->key[i + 1] = value;
        root->n++;
    }

    /* If node is not a leaf */
    else {

        while (i >= 0 && value < root->key[i])
            i--;

        i++;

        /* If child is full */
        if (root->child[i]->n == 2 * T - 1) {

            split(root, i);

            if (value > root->key[i])
                i++;
        }

        insertNonFull(root->child[i], value);
    }
}

/* Insert into B-Tree */
BTree *insert(BTree *root, int value) {

    /* Tree is empty */
    if (root == NULL) {

        root = create(1);

        root->key[0] = value;
        root->n = 1;

        return root;
    }

    /* Root is full */
    if (root->n == 2 * T - 1) {

        BTree *newRoot = create(0);

        newRoot->child[0] = root;

        split(newRoot, 0);

        int i = 0;

        if (value > newRoot->key[0])
            i++;

        insertNonFull(newRoot->child[i], value);

        return newRoot;
    }

    /* Root is not full */
    insertNonFull(root, value);

    return root;
}

/* Search for a key */
int search(BTree *root, int value) {

    int i = 0;

    while (i < root->n && value > root->key[i])
        i++;

    if (i < root->n && value == root->key[i])
        return 1;

    if (root->leaf)
        return 0;

    return search(root->child[i], value);
}

int main() {

    BTree *root = NULL;

    int n, value, searchValue;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("B-Tree: ");
    traverse(root);

    printf("\nEnter key to search: ");
    scanf("%d", &searchValue);

    if (search(root, searchValue))
        printf("Found");
    else
        printf("Not Found");

    return 0;
}