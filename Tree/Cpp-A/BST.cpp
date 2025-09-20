#include <iostream>
#include <queue>
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

    private:
    void insertNode(Node *&root, int data){ //instead of pointer to pointer we use the reference variable then we dont need to dereference that
        if(root == nullptr)
            root = new Node(data); //needed for recursive process
        else if(data < root->data)
            insertNode(root->left,data);
        else 
            insertNode(root->right,data);

    }

    bool searchN    ode(Node *&root, int data){
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

    void levelOrderTraversal(Node *root){
        if(!root)
            return;
        queue<Node *> q;

        q.push(root);
        while(!q.empty()){
            Node *current = q.front();
            q.pop();

            cout<<current->data<<" ";
            if(current->left != nullptr)
                q.push(current->left);
            if(current->right != nullptr)
                q.push(current->right);
        }
    }
        int treeHeight(Node *root){
            if(!root)
                return -1;
            int leftN = treeHeight(root->left);
            int rightN = treeHeight(root->right);

            return max(leftN,rightN) + 1;
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
        void levelOrder()
        {
            levelOrderTraversal(root);
        }
        void height()
        {
            cout<<"Tree height"<<treeHeight(root);
        }
    
};

int main()
{
    BST b1;
    b1.insert(1);
    b1.insert(2);
    b1.insert(3);
    b1.insert(9);
    b1.insert(5);
    b1.insert(7);
    b1.search(10);
    b1.levelOrder();
    b1.height();
    
    return 0;
}