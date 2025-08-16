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
        Node *head = nullptr;
        Node *tail = nullptr;
        
        void addNum(Node* l1,Node* l2){
            int carry = 0;

            while(l1||l2||carry){
                int val1 = (l1) ? l1->data : 0;
                int val2 = (l2) ? l2->data : 0;
                int sum = val1+val2+carry;

                carry = sum /10;
                Node* newNode = new Node(sum%10);
                if(!head)
                    head = newNode;
                else 
                    tail->next = newNode;
                tail = newNode;
                if(l1)
                    l1 = l1->next;
                if(l2)
                    l2 = l2->next;
            }
        }
        
            void display(){
                Node* temp = head;
                while(temp){
                    printf("%d ",temp->data);
                    temp = temp->next;
                }
            }
            
        

};

int main()
{
    LinkedList l1;
    LinkedList l2;
    l1.insertAtBeg(3);
    l1.insertAtBeg(4);
    l1.insertAtBeg(2);
    l2.insertAtBeg(4);
    l2.insertAtBeg(6);
    l2.insertAtBeg(5);

    Solution s2;
    s2.addNum(l1.head,l2.head);
    s2.display();

}