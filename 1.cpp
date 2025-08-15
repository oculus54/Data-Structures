#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

    Node(){
        data =0;
        next = NULL;
    }
    Node(int data){ //constructor with arg
        this->data = data;
        this->next = NULL;
    }
};


class LinkedList {
    public:
    Node *head = NULL;
    Node *tail = NULL;
    int count;
        LinkedList(){ //constructor
            head = NULL;
            tail = NULL;
            count =0;
        }

        void insertAtBeg(int data){
            Node *newN = new Node(data);

            newN->next = head;
            head = newN;

        }
};

class Solution {
    public: 
        Node* head = NULL;

        void addNum(Node* l1,Node*l2){
            Node* temp1 =l1;
            Node* temp2 = l2;
            Node* dummy = new Node(0);
            Node* curr = dummy;
            while(temp1 && temp2){
                int sum = temp1->data + temp2->data;
                Node* newN = new Node(sum);
                curr->next = newN;

                temp1 = temp1->next;
                temp2 = temp2->next;
                curr = curr->next;
            }
            this->head = dummy->next;
        }
        void display(){
            Node* temp = this->head;

            while(temp){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }
};

int main()
{
    LinkedList l1;
    LinkedList l2;
    l1.insertAtBeg(1);
    l1.insertAtBeg(2);
    l1.insertAtBeg(3);
    l2.insertAtBeg(1);
    l2.insertAtBeg(2);
    l2.insertAtBeg(3);
    Solution sol;
    sol.addNum(l1.head,l2.head);
    sol.display();
    return 0;
}