#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#define length(arr) (sizeof(arr)/sizeof *(arr))


_Bool overFlow(Stack *stack){
    if(length(stack->arr)-1==stack->top)
        return 1;

    return 0;
}
_Bool underFlow(Stack *stack){
    if(-1==stack->top)
        return 1;

    return 0;
}
struct Stack {
    int arr[10];
    int top;
};

// void create(Stack *s1){   //please explain why its not working
//     s1 = malloc(sizeof(Stack));
//     s1->top =-1;   
// }

Stack *create(void){
    Stack *newStack = malloc(sizeof(Stack));
    newStack->top = -1;

    return newStack;
}

void push(Stack *s,int data){
    if(overFlow(s))
        printf("Stack Overflow");
    else
        s->arr[++(s->top)] = data;
}

void pop(Stack *s){
    if(underFlow(s))
        printf("Stack Underflow");
    else 
        s->arr[(s->top)--];
}

void peek(Stack *s){
    if(underFlow){
        printf("Stack underflow");
        exit(1);
    }
    printf("%d ",s->arr[s->top]);
}