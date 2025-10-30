#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
        Node(int data){
            this->data = data;
            this->next = nullptr;
        }
};

class LinkedList {
    Node* head = nullptr;
    Node* tail = nullptr;
    int count =0;
    public:
        void insertAtBeg(int data){
            Node* newNode = new Node(data);
            if(!head)
                tail = newNode;
            else 
                newNode->next = head;
            head = newNode;
            count++;
        }
        void insertAtLast(int data){
            Node* newNode = new Node(data);
            if(!head)
                head = newNode;
            else 
                tail->next = newNode;
            tail = newNode;
            count++;
        }
        void insertAtAny(int data, int pos){
            if(pos < 0 && pos > count){
                cout<<"Invalid";
                return;
            }
            else {
                if(pos == 0){
                    insertAtBeg(data);
                }
                else if(pos == count)
                    insertAtLast(data);
                else {
                    Node* temp = head;
                    Node* newNode = new Node(data);
                    for(int i =1;i<=pos-1;i++)
                        temp = temp->next;
                    newNode->next = temp->next;
                    temp->next = newNode;
                }
            }
        }
        void display()
        {
            if(!head){
                cout<<"empty";
                return;
            }
            Node* temp = head;
            while(temp){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }
        void reversal(){
            Node* curr = head,next,prev;
            while(curr!=nullptr){
                
            }
        }
};

int main()
{
    LinkedList l1;
    l1.insertAtBeg(1);
    l1.insertAtBeg(0);
    l1.insertAtBeg(8);
    l1.insertAtAny(5,2);
    l1.insertAtLast(4);
    l1.display();
    return 0;
}