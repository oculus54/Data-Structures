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
    insertLeft(root,2);
    insertRight(root,3);
    insertLeft(root->left,4);
    insertRight(root->left,5);
    inOrderTraversal(root);
    return 0;

}

void insert(Node **root,int data){
    if(*root == NULL){
        Node *newNode = malloc(sizeof(Node));
        return;
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
