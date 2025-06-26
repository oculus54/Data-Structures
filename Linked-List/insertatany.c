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
    for(int i =1;i<=4;i++){
        insertatbeg(i);
    }
    printf("%d\n",nodeCount);
    insertatany(4,54);
      printf("%d\n",nodeCount);
    display();
}

void insertatbeg(int data){
    Node *newNode = malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;
    ++nodeCount;
    newNode->next = head;
    head = newNode;
    if(tail == NULL)//this step is required for the bug of insert at any and if we input the last index
        tail = newNode;//
}


void insertatlast(int data){
    Node *newNode = malloc(sizeof(Node)); //returns a pointer to node by allocating in heap
    newNode->data = data;
    newNode->next = NULL;
    
    if(!head){
         /*as at first the list is empty the if will be true
         and that's why we have to save the head as first node's address*/
        head = newNode;
        //tail = newNode;
        //also as for empty list the first element will also be the first node(newNode) (optional)
    }
    else //if list not empty
        tail->next =newNode; // the previous tail next pointer will point to the newly created node
    tail = newNode; //the tail pointer will point the newly added element means it will be at the last
    ++nodeCount;

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
    if(pos<0 || pos > nodeCount)
    {
        printf("Invalid index");
        return;
    }
    else {
        if(pos==0){
            insertatbeg(num);
            
        }
        else if(pos==nodeCount)
        {
            insertatlast(num);
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