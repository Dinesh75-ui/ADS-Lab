#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left, *right;
}node;

node* createNode(int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;  
}

node* Insert(node* root, int data){
    if (root == NULL){
        root = createNode(data);
    }
    else if (data < root->data){
        root->left = Insert(root->left,data);
    }
    else{
        root->right = Insert(root->right, data);
    }
    return root;
}

void Search(node* root, int key){
    if (root == NULL){
        printf("Not found\n");
        return;
    }
    else if (root->data == key){
        printf("Key found\n");
        return;
    }
    else if(key < root->data){
        Search(root->left, key);
    }
    else{
        Search(root->right, key);
    }
}

void inorder(node* root){
        if(root == NULL){
            return;
        }
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
}

int main(){
    node* root = NULL;
    int n,x;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for(int i = 0; i < n; i++){
       scanf("%d",&x);
       root = Insert(root, x); 
    }
    Search(root, 12);
    inorder(root);
}