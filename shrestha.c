#include<stdio.h>
#include<stdlib.h>
//structure of a node//
struct node
{
int data;
struct node *left;
struct node *right;
};
//function to create the new node//
struct node* createnode(int value)
{
struct node* newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=value;
newnode->left=NULL;
newnode->right=NULL;
return newnode;
}
//function to build a tree
struct node* createtree()
{
    int value;
    struct node *root;
    printf("enter the data (-1 for no node): ");
    scanf("%d",&value);
    if (value==-1)
     return NULL;
     if(root == NULL){
         root=createnode(value);
        return;
     }
if(root->left == NULL){
    printf("enter the left child %d\n: ");
    root->left=createtree();
}
else {
    printf("enter the right child%d: ");
    root->right=createtree();
}
return root;
}
//function for preorder traversal//
void preorder(struct node *root) 
{
if(root==NULL)
return;
printf("%d",root->data );
preorder(root->left);
preorder(root->right);
}
//here is the main function//
int main()
{
    struct node* root=NULL;
    if(root=NULL)
        printf("the tree is empty");

    printf("create binary tree\n:");
    root=createtree();
    printf("\npreorder traversal of the tree\n:");
    preorder(root);
    return 0;
}