#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *head = NULL;
Node *tail = NULL;

void insertAtLast(int);
Node *getNode(int);
void display();

int main()
{
    for(int i =1;i<=5;i++)
        insertAtLast(i);
    display();
    return 0;
}

void insertAtLast(int data)
{
    Node *newNode = getNode(data);
    if(!head) //if list is empty
    {
        head =newNode;
    }
    else{
        tail->next = newNode;//insert at last that's why 
        newNode->prev = tail; //sets newNode's previous pointer to tail as tail would now be the previous
    } 
    tail = newNode;//setting tail to newNode for both if and else conditions
}

Node *getNode(int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
}

void display()
{
    Node *temp = head;
    while(temp){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}