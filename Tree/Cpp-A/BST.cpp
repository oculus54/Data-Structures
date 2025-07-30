#include <iostream>
using namespace std;

class Node 
{
    public:
        int data;
        Node *left = nullptr, *right = nullptr;
    Node(int data){
        this->data = data;
    }
};

class BST {
    Node *root = nullptr;

    void insertNode(Node *&root, int data){ //instead of pointer to pointer we use the reference variable then we dont need to dereference that
        if(root == nullptr)
            root = new Node(data); //needed for recursive process
        else if(data < root->data)
            insertNode(root->left,data);
        else 
            insertNode(root->right,data);

    }

    bool searchNode(Node *&root, int data){
        if(root==nullptr)
            return false;
        if(root->data == data)
            return true;
        else if(data<root->data) // roots left data is smaller that root itself and the right value is greater
            return searchNode(root->left,data);
        else
            return searchNode(root->right,data);
    }
    void inOrderTraversal(Node *&root){
        if(root!=nullptr){
        inOrderTraversal(root->left);
        cout<<root->data<<" ";
        inOrderTraversal(root->right);}
    }
    public:
        void insert(int data){
            insertNode(root,data);
        }
        void search(int data){
            if(searchNode(root,data))
                printf("Yes");
            else 
                printf("No");
            
        }
        void inOrder(){
            inOrderTraversal(root);
        }
    
};

int main()
{
    BST b1;
    b1.insert(1);
    b1.insert(2);
    b1.insert(3);
    b1.insert(9);
    b1.search(10);
    b1.inOrder();
    return 0;
}