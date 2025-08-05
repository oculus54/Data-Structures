#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node *next;

    Node() {
        data = 0;
        next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// LinkedList class
class LinkedList {
    Node *head;
    Node *tail;
    int count;

public:
    LinkedList() {
        head = NULL;
        tail = NULL;
        count =0;
    }

    void insertAtBeg(int data) {
        Node *newNode = new Node(data);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        count++;
    }

    void insertAtEnd(int data) {
        Node *newNode = new Node(data);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }
    
    void insertAtAny(int data,int pos){
        if(pos<0 || pos>count){
            cout<<"out of bound";
            return;
        }
        else {
        if(pos == 0)
            insertAtBeg(data);
        else if(pos==count)
            insertAtEnd(data);
        else {
        Node *newNode = new Node(data);
        Node *temp = head;
        for(int i=0;i<pos-1;i++)
            temp = temp->next;
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    }
    void countfs()
    {
        cout<<count;
    }
    void print() {
        Node *temp = head;
        if (!head) {
            cout << "list empty" << endl;
            return;
        }
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main
int main() {
    LinkedList list;

    for (int i = 1; i <= 5; i++)
        list.insertAtBeg(i);
list.insertAtEnd(1);

list.insertAtAny(56,1);
list.print();

    return 0;
}
