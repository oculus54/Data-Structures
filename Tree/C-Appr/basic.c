#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int);
void insertLeft(Node*,int);
void insertRight(Node*,int);
void inOrderTraversal(Node*);
void insert(Node **,int);
int main()
{
    Node *root = createNode(1);
    insert(&root,2);
    insert(&root,3);
    insert(&root,4);    
    inOrderTraversal(root);
    return 0;

}

void insert(Node **root,int data){
    if(*root == NULL){
        *root = createNode(data);
        return;
    }
    if ((*root)->left == NULL) {
        insert(&((*root)->left), data);
    }
    else if((*root)->right == NULL){
        insert(&((*root)->right), data);
    }
    else {
        insert(&((*root)->left),data);
    }
    

}
Node *createNode(int data){
    Node *newNode = malloc(sizeof(Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void insertLeft(Node* root,int data){
    if(root == NULL){
        printf("Parent is NULL");
        return;
    }
    root->left = createNode(data);
}

void insertRight(Node *root,int data){
    if(root == NULL){
        printf("Parent is NULL");
        return;
    }
    root->right = createNode(data);
}

void inOrderTraversal(Node *root){
    if(root != NULL){
        inOrderTraversal(root->left);
        printf("%d ",root->data);
        inOrderTraversal(root->right);
    }

}
