#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data; //data
    struct Node *next; //pointer to node for next node
} Node;

Node *head = NULL; // pointer to node to save the address of the first node 
Node *tail = NULL; //pointer to node as the tail of node is needed to add element at last

void insertEleL(int); /*to insert element at the last and void type,
 as it will return nothing and integer argument to pass the value*/ 
Node *getNode(int); //function which return a pointer to node to the insertEleb function
void display();

int main()
{
    for(int i=1;i<=5;i++)
        insertEleL(i); //insert elements
    display();
    return 0;
}

void insertEleL(int data){
    Node *newNode = getNode(data); //returns a pointer to node by allocating in heap

    if(!head){
         /*as at first the list is empty the if will be true
         and that's why we have to save the head as first node's address*/
        head = newNode;
        tail = newNode;
        //also as for empty list the first element will also be the first node(newNode) (optional)
    }
    else //if list not empty
        tail->next =newNode; // the previous tail next pointer will point to the newly created node
    tail = newNode; //the tail pointer will point the newly added element means it will be at the last
    

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