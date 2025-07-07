#include <iostream>
using namespace std;
//object oriented approach

class Node { //this is for creating node inside a linked list object
    public:
        int data;
        Node *next;
    
    Node(){ //default constructor
        data =0;
        next = NULL;
    }

    Node(int data){ //with parameter
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
    Node *head; //pointer to node
    Node *tail;

    public:
        LinkedList() { //default constructor
            head = NULL;
            tail = NULL;
        }
        void insertAtBeg(int data){
            Node *newNode = new Node(data); //new is like malloc
            if(!head){
                head = newNode;
                tail = newNode;
                return;
            }
            newNode->next = this->head;
            this->head = newNode;
            this->tail = newNode;
        }
        void insertAtEnd(int data){
            Node *newNode = new Node(data);
            if(!head){
                head = newNode;
            }
            else {
                tail->next = newNode;
            }
            tail = newNode;
        }
        void print(){
            Node *temp = head;
            if(!head){
                cout<<"list empty"<<endl;
                return;
            }
            while(temp){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }
};

int main()
{
    LinkedList list;
    for(int i=1;i<=5;i++)
        list.insertAtEnd(i);
    list.print();
    return 0;
}