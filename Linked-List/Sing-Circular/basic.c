#include <stdio.h>
#include <stdlib.h>
//what basically this list does that the tail of the list points the head or the first node of the list
typedef struct Node {
    int data;
    struct Node *next;
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


void display()
{
    Node *temp = head;
    while(temp->next != head) //while the next node is not head
    {
        printf("%d ",temp->data);
        temp = temp->next;//shifts temp pointer to next node
    }
    printf("%d ",temp->data);//as in the tail pointer the temp will point at head and the loop will break without printing the last element that's why
}

void insertAtBeg(int data)
{
    Node *newNode = getNode(data);
    if(!head)//if list is empty
    {
        head = newNode;
        newNode->next = head;
        tail = newNode;
    }
    else{
        newNode->next = head; //means the next of newNode is head and then set head to newNode
        head = newNode;
        tail->next = newNode;//end of the node points the first node
    }
}

Node *getNode(int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}
