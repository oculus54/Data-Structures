#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;
int nodeCount =0;

void insertatbeg(int);
void insertatlast(int);
void insertatany(int,int);
void display();

int main()
{
    for(int i =1;i<=5;i++){
        insertatbeg(i);
    }
    printf("%d\n",nodeCount);
    insertatany(3,54);
    display();
}

void insertatbeg(int data){
    Node *newNode = malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;
    nodeCount++;
    newNode->next = head;
    head = newNode;
}

void insertatlast(int data){
    Node *newNode = malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;

    if(!head)
        head = newNode;
    else
        tail->next = newNode;
    tail = newNode;
}
void display(){
    if(!head)
        printf("List empty");
    else {
        Node *temp = head;
        while(temp){
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
}

void insertatany(int pos,int num){
    if(pos<0 && pos > nodeCount)
    {
        printf("Invalid index");
        return;
    }
    else {
        if(pos==0){
            insertatbeg(num);
            nodeCount++;
        }
        else if(pos==nodeCount)
        {
            insertatlast(num);
            nodeCount++;
        }
        else {
            Node *newNode = malloc(sizeof(Node));
            newNode->data = num;
            newNode->next = NULL;
            Node *temp = head;
            for(int i =0;i<pos-1;i++)
                temp = temp->next;
            newNode->next = temp->next;
            temp->next = newNode;
            nodeCount++;

        }
    }
}