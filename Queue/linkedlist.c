#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;

Node *getNode(int);
void enq(int);
void deq();
void peek();

int main()
{
    enq(1);
    enq(2);
    enq(3);
    deq();
    peek();
    return 0;
}
void peek()
{
    if(!head){
        printf("Queue is empty");
        return;
    }
    printf("The top element is %d",head->data);
}
void deq()
{
    if(!head){
        printf("Queue is empty");
        return;
    }
    Node *temp = head;
    head = temp->next;
    free(temp);
}
Node *getNode(int data){
    Node *newNode = malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}
void enq(int data){
    Node *newNode = getNode(data);
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    
}