#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} Node;

Node* createNode(int data){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node *root, int x) {
    if (root == NULL) {
        root = createNode(x);
    }
    else if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}

void search(Node *root, int x) {
    if (root == NULL)
        printf("Not Found");
    else if (root->data == x)
        printf("Found");
    else if (x < root->data)
        search(root->left, x);
    else
        search(root->right, x);
}

void inorder(Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    Node *root = NULL;
    int n, x, i;
    printf("Enter No. of elements to insert into BST: ");
    scanf("%d", &n);

    printf("Enter elements to insert into BST: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }
    printf("BST: ");
    inorder(root);
    printf("\nEnter search element: ");
    scanf("%d", &x);
    search(root, x);

    return 0;
}