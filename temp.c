#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

Node *head = NULL;
Node *tail = NULL;
int nodeCount =0;

void insertAtBeg(int);
void insertAtEnd(int);
void insertAtAny(int,int);
void display();
Node* getNode(int);
void deleteAtBeg();
void deleteAtEnd();
void deleteAtAny(int); //position wise
void delete(int);

int main()
{
	insertAtBeg(1);
	insertAtEnd(5);
	for(int i = 9;i<=15;i++)
		insertAtEnd(i);
        delete(14);
	display();
}

Node *getNode(int data){
	Node *newNode = malloc(sizeof(Node));
	
	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}

void insertAtBeg(int data){
	Node *newn = getNode(data);
	
	if(!head && !tail){
		head = tail = newn;
	return;	
	nodeCount++;
	}
	newn->next = head;
	head = newn;
	nodeCount++;
}

void insertAtEnd(int data){
	Node *newn = getNode(data);
	if(!head && !tail){
		head = tail = newn;	
		nodeCount++;
		return;
	}
	tail->next = newn;
	tail = newn;
}

void insertAtAny(int pos,int data){
	if(pos <0 || pos>nodeCount){
		printf("not possible");
		return;
	}
	else{
		if(pos ==0)
			insertAtBeg(data);
		else if(pos == nodeCount)
			insertAtEnd(data);
		else {
			Node *newn = getNode(data);
			Node *temp = head;
			for(int i =0;i<pos-1;i++)
				temp = temp->next;
			newn->next = temp->next;
			temp->next = newn;
			nodeCount++;
		}
	}
}

void deleteAtBeg(){
	Node *temp = head;
	head = temp->next;
	free(temp);
	nodeCount--;
}

void deleteAtEnd(){
	Node *temp = head;
	while(temp->next->next != NULL){
		temp = temp->next;
	}
	tail = temp;
	tail->next = NULL;
	free(temp->next);
	nodeCount--;
}
void delete(int data){

    if(data == head->data)
        deleteAtBeg();
    else if(data == tail->data)
        deleteAtEnd();
    else{
    Node *temp = head;
    while(temp->next->data!=data)
        temp = temp->next;
    Node *todel =temp->next;
    temp->next = todel->next;
    free(todel);
    }

}
void display()
{
    Node *temp = head;
    while(temp){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}