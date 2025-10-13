#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }

};

class BST {
    Node* root;
    void insert(Node*&root,int data){
        if(!root)
            root = new Node(data);
        else if(data<root->data)
            insert(root->left,data);
        else 
            insert(root->right,data);
    }
    void LevelOT(Node *re){
        if(!re)
            return;
        cout<<re->data;
        if(!re->left)
            cout<<re->left->data;
        if(!re->right)
            cout<<re->right->data;
        LevelOT()

    }
};
