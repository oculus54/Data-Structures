#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *head = NULL;
Node *tail = NULL;

void insertAtBeg(int);
Node *getNode(int);
void display();

int main()
{
    for(int i =1;i<=5;i++)
        insertAtBeg(i);
    display();
    return 0;
}

void insertAtBeg(int data)
{
    Node *newNode = getNode(data);
    if(!head) //if list is empty
    {
        tail =newNode;
    }
    else{
        head->prev = newNode;
        newNode->next = head;
    } 
    head = newNode;
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