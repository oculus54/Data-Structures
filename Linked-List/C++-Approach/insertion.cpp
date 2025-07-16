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

public:
    LinkedList() {
        head = NULL;
        tail = NULL;
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
    list.print();

    return 0;
}
