#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *head = NULL;
Node *tail = NULL;
int nodeCount =0;   

void insertAtBeg(int);
void insertAtLast(int);
void insertAny(int,int);
Node *getNode(int);
void display();

int main()
{
    for(int i =1;i<=5;i++)
        insertAtBeg(i);
    insertAny(2,50);
    display();
    return 0;
}
void insertAny(int pos,int data)
{
    if(pos<0 || pos> nodeCount){
        printf("Invalid");
    }
    else{
        if(pos==0){
            insertAtBeg(data);
        }
        else if(pos == nodeCount){
            insertAtLast(data);
        }
        else {
            Node *newNode = getNode(data);
            Node *temp = head;
            for(int i=1;i<=pos-1;i++){
                temp = temp->next;
            }
            //at first set the pointers if newNode to avoid losing any of the addresses
            newNode->next = temp->next; //set newnode's next as temp's next
            newNode->prev = temp;//set newNode's previous as temp
            temp->next->prev = newNode; //set the temp node's next node's previous as newnode to insert that
            temp->next = newNode;//finally set temp's next would be newnode
            nodeCount--;
        }
    }
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
    nodeCount++;
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
    nodeCount++;
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