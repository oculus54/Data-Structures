#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *head = NULL;
Node *tail = NULL;
int nodeCount = 0;

void insertAtBeg(int);
Node *getNode(int);
void display();
void deleteBeg();
void deleteLast();
void deleteAny(int);

int main()
{
     for(int i =1;i<=5;i++)
        insertAtBeg(i);
    deleteAny(2);
    display();
    printf("%d",nodeCount);
    return 0;
}

void deleteAny(int pos)
{
    if(pos<0 || pos >=nodeCount){
        printf("invalid");
    }
    else {
        if(pos ==0){
            deleteBeg();
        }
        else if(pos == nodeCount-1){
            deleteLast();
        }
        else {
            Node *temp = head;
            for(int i =1;i<=pos;i++) //traverse to the element u wanna delete
                temp = temp->next;
            temp->prev->next = temp->next;//set the previous node's next to the temp node's next
            temp->next->prev = temp->prev;//set temp's next node's previous to temp's previous pointer
            free(temp);
            nodeCount--; 
        }
    }
}

void deleteBeg()
{   
    if(head==tail)//if there is only one node
    {
        free(head);
        head = NULL;
        tail = NULL;
    }
    else //if there is more than one node
    {
    head = head->next;
    free(head->prev);
    head->prev = NULL;
    }
    nodeCount--;
}

void deleteLast()
{
    if(head == tail){
        free(tail);
        head = NULL;
        tail = NULL;
    }
    else{
        tail = tail->prev; //sets tail as the last elements previous pointer
        free(tail->next); //free the last element
        tail->next= NULL; //sets tail's next element to null
    }
    nodeCount--;
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
    if(!head)
        printf("List Empty");
    while(temp){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}