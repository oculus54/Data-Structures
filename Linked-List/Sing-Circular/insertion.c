#include <stdio.h>
#include <stdlib.h>
//what basically this list does that the tail of the list points the head or the first node of the list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;
int NodeCount = 0;
void insertAtLast(int);
void insertAtF(int);
void insertAtAny(int,int);
Node *getNode(int);
void display();

int main()
{
    for(int i =1;i<=5;i++)
        insertAtLast(i);
    insertAtAny(3,90);
    display();
    return 0;
}

void insertAtAny(int pos,int data)
{
    if(pos<0 || pos > NodeCount)
        printf("Out of bound");
    else {
        if(pos == 0)
            insertAtF(data);
        else if(pos == NodeCount)
            insertAtLast(data);
        else {
            Node *temp = head;
            Node *newNode = getNode(data);
            for(int i =1;i<=pos-1;i++)
                temp = temp->next;
            newNode->next = temp->next;
            temp->next = newNode;
            NodeCount++;
        }
    }
}
void insertAtF(int data)
{
    Node *newNode = getNode(data);
    if(!head){
        head = newNode;
        newNode->next = head;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
        tail->next = newNode;

    }
    NodeCount++;
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

void insertAtLast(int data)
{
    Node *newNode = getNode(data);
    if(!head)//if list is empty
    {
        head = newNode;
        newNode->next = head;
        tail = newNode;
    }
    else{
        tail->next = newNode; //end of the list points another element
        tail = newNode; //tailpointer points newnode
        tail->next = head; //the tail next pointer points the first node
    }
    NodeCount++;
}

Node *getNode(int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}
