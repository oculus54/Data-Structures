#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

#define length(arr) (sizeof(arr) / sizeof((arr)[0]))

// Full struct definition needed before using its members
typedef struct Stack {
    int arr[10];
    int top;
} Stack;

_Bool overFlow(Stack *stack) {
    if (length(stack->arr) - 1 == stack->top)
        return 1;
    return 0;
}

_Bool underFlow(Stack *stack) {
    if (-1 == stack->top)
        return 1;
    return 0;
}

Stack *create(void) {
    Stack *newStack = malloc(sizeof(Stack));
    newStack->top = -1;
    return newStack;
}

void push(Stack *s, int data) {
    if (overFlow(s))
        printf("Stack Overflow\n");
    else
        s->arr[++(s->top)] = data;
}

void pop(Stack *s) {
    if (underFlow(s))
        printf("Stack Underflow\n");
    else
        s->top--; // You don’t need to access the value
}

void peek(Stack *s) {
    if (underFlow(s)) { // You missed () in the condition
        printf("Stack Underflow\n");
        exit(1);
    }
    printf("%d\n", s->arr[s->top]);
}
