#include "stack.h"

int main()
{
    Stack *s1 = create();
    for(int i=1;i<=10;i++)
        push(s1,i);
    pop(s1);
    pop(s1);
    peek(s1);
    
}