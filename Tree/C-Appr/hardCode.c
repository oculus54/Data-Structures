#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int);
void inOrderTraversal(Node*);
void preOrder(Node*);

int main()
{
    Node* root = createNode(1);
    root->left= createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    inOrderTraversal(root);
    preOrder(root);

}

Node *createNode(int data){
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    return newNode;
}

void inOrderTraversal(Node *root){
    if(root != NULL){
    inOrderTraversal(root->left);
    printf("%d ",root->data);
    inOrderTraversal(root->right);
    }
}

void preOrder(Node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node *root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}