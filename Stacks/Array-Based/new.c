#include <stdio.h>
#define n 5


int stack[n];
int top = -1;

void push(int data)
{
    if(top == n-1)//if the top value is same as the array's last index
    {
        printf("Stack Overflow");
        return;
    }
    stack[++top] = data; 
}

void pop()
{
    if(top == -1){
        printf("Stack Underflow");
        return;
    }
    top--;//just hiding the elements
}

void peek()
{
    if(top == -1){
        printf("Stack Underflow");
        return;
    }
    printf("%d ",stack[top]);//printing the element pushed at last 
}

int main()
{
    push(1);
    push(2);
    push(3);
    peek();
    printf("\n");
    pop();
    peek();
    //working smooth asf
    return 0;
}