#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int);
void insert(Node *, int);
void inOrderTraversal(Node *);

int main() {
    int value;
    Node *root = NULL;

    printf("Enter values (-1 to stop):\n");

    // take input until -1
    while (1) {
        scanf("%d", &value);
        if (value == -1)
            break;

        if (root == NULL)
            root = createNode(value);
        else
            insert(root, value);
    }

    printf("\nInorder Traversal:\n");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(Node *root, int data) {
    if (root == NULL)
        return;

    if (root->left == NULL) {
        root->left = createNode(data);
    } else if (root->right == NULL) {
        root->right = createNode(data);
    } else {
        // keep inserting into the left subtree recursively
        insert(root->left, data);
    }
}

void inOrderTraversal(Node *root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}
