#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data; //data
    struct Node *next; //pointer to node for next node
} Node;

Node *head = NULL; // pointer to node to save the address of the first node 
Node *tail = NULL;
int nodeCount =0;
void insertEleb(int); /*to insert element at the beginning and void type,
 as it will return nothing and integer argument to pass the value*/ 
Node *getNode(int); //function which return a pointer to node to the insertEleb function
void display();
void deletefront();
void deleteEnd();
void deleteAny(int);
void deleteElement(int);
void revTraversal(Node *);
int main()
{
    for(int i=1;i<=5;i++)
        insertEleb(i); //insert elements
    deleteAny(2);
    insertEleb(7);
    display();
    printf("\n");
    revTraversal(head);
    return 0;
}

void revTraversal(Node *temp){
    if(!temp)
        return;
    revTraversal(temp->next);
    printf("%d ",temp->data);
}
void insertEleb(int data){
    Node *newNode = getNode(data); //returns a pointer to node by allocating in heap

    newNode->next = head; //this shifts the first node to the 2nd first node means i
    head = newNode; //now the head will point at the new node that is added
    nodeCount++;

}

Node *getNode(int data){
    Node *newNode = malloc(sizeof(Node)); //allocate memory in heap 

    newNode->data = data; //dereferences the newNode and on data of newNode it stores the input value
    newNode->next = NULL; //as end of node is null

    return newNode;
}

void display()
{
    Node *temp = head;//creates a pointer to node to store the address of head

    while(temp){  //untill it reaches to null means the end of the linked list
        printf("%d ",temp->data); //print the current nodes data

        temp = temp->next;//shift the pointer to next node address
    }
}

void deletefront()
{
    Node *temp = head;
    head = head->next;
    free(temp);
    nodeCount--;
}

void deleteEnd()
{
  Node *temp = head;
    while(temp->next->next != NULL)
        temp = temp->next;
    free(tail);
    tail = temp;
    tail->next = NULL;
    nodeCount--;
}

void deleteAny(int pos){
    if(pos<0 && pos >= nodeCount){
        printf("out of bound");
        return;
    }
    else {
        if(pos == 0){
            deletefront();
        }
        else if(pos == nodeCount-1){
            deleteEnd();
        }
        else {
          Node *temp = head;
          for(int i =1;i<=pos-1;i++)
            temp = temp->next;

        Node *toDelete = temp->next;
        temp->next = toDelete->next;
        free(toDelete);
             
            
        }
    }
}

void deleteElement(int data){

    if(data == head->data)
        deletefront();
    else if(data == tail->data)
        deleteEnd();
    else{
    Node *temp = head;
    while(temp->next->data!=data)
        temp = temp->next;
    Node *todel =temp->next;
    temp->next = todel->next;
    free(todel);
    }

}