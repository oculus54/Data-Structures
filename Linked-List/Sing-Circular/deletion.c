#include <stdio.h>
#include <stdlib.h>
//what basically this list does that the tail of the list points the head or the first node of the list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;
int Nodecount =0;
void insertAtLast(int);
Node *getNode(int);
void deleteAtLast();
void deleteAtF();
void deleteAtAny(int);
void display();

int main()
{
    for(int i =1;i<=5;i++)
        insertAtLast(i);
    deleteAtAny(3);
    printf("%d \n",Nodecount);
    display();
    return 0;
}

void deleteAtAny(int pos)
{
    if(pos<0 || pos >= Nodecount)
        printf("Out of bound");
    else{
        if(pos == 0){
            deleteAtF();
        }
        else if(pos == Nodecount-1){
            deleteAtLast();
        }
        else{
            Node *temp = head;
            for(int i =1;i<=pos-1;i++){
                temp = temp->next;
            }
            Node *toDelete = temp->next;
            temp->next = toDelete->next;
            free(toDelete);
            Nodecount--;
        }
    }

}
void deleteAtF()
{
    Node *temp = head;
    head = temp->next;
    tail->next = head;
    free(temp);
    Nodecount--;
}
void deleteAtLast()
{
    Node *temp = head;
    while(temp->next->next != head)
    {
        temp = temp->next;    
    }
    free(tail);
    tail = temp;
    tail->next = head;
    Nodecount--;
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
    Nodecount++;
}

Node *getNode(int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}
