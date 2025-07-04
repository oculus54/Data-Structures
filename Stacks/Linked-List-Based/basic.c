#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data; //data
    struct Node *next; //pointer to node for next node
} Node;

Node *head = NULL; 

void push(int);
void pop();
void peek();
Node *getNode(int);

int main()
{
    push(1);
    push(2);
    push(3);
    pop();
    peek();
    return 0;
}

void push(int data)
{
    Node *newNode = getNode(data);
    newNode->next = head;
    head = newNode;
}

void pop()
{
    if(!head)
    {
        printf("list empty");
        return;
    }
    Node *temp = head;
    head = head->next;
    free(temp);
}

void peek()
{
    if(!head){
        printf("Stack Underflow");
        return;
    }
    printf("%d ",head->data);
}


Node *getNode(int data){
    Node *newNode = malloc(sizeof(Node)); //allocate memory in heap 

    newNode->data = data; //dereferences the newNode and on data of newNode it stores the input value
    newNode->next = NULL; //as end of node is null

    return newNode;
}

