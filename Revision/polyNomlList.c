#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int pow;
    struct Node* next;
} Node;

Node *head1 = NULL;
Node *head2 = NULL;

void insert(int data,int pow,Node* head){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->pow = pow;
    newNode->next = head;
    head = newNode;
}

void display(Node * head){
    Node* temp = head;
    while(temp){
        printf("%d %d",temp->data,temp->pow);
        temp = temp->next;
    }
}

Node* addPoly(Node* hea1,Node* hea2){
    Node* temp = NULL;
    while(hea1 && hea2){
        if(hea1->pow > hea2->pow){
            temp->data = hea1->data;
            temp->pow = hea1->pow;
            hea1 = hea1->next;
        }
        else if(hea1->pow < hea2->pow){
            temp->data = hea2->data;
            temp->pow = hea2->pow;
            hea2 = hea2->next;
        }
        else {
            temp->data = hea1->data + hea2->data;
            temp->pow = hea1->pow;
            hea1= hea1->next;
            hea2= hea2->next;
        }
        temp = temp->next;

    }

    while(hea1){
        temp->data = hea1->data;
        temp->pow = hea1->pow;
        temp = temp->next;
        hea1 = hea1->next;
    }
    while(hea2){
        temp->data = hea2->data;
        temp->pow = hea2->pow;
        temp = temp->next;
        hea2 = hea2->next;
    }
    return temp;
}

void middleofList(Node *head){
    int count =0;
    Node* temp = head;
    while(temp){
        count++;
        temp= temp->next;

    }
    int mid = count/2;
    
}

