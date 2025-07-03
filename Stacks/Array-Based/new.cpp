#include <iostream>
#define n 5
using namespace std;

class Stacks {
    private:
        int stack[n];
        int top = -1;
    public:
        void push(int data)
        {
            if(top == n-1){
                cout<<"Stack Overflow"<<endl;
                return;
            }
            this->stack[++top] = data;
        }
        void pop()
        {
            if(top == -1)
            {
                cout<<"Stack UnderFlow"<<endl;
                return;
            }
            top--; //poped
        }
        void peek()
        {   
            if(top == -1){
                cout<<"Stack UnderFlow"<<endl;
            }
            cout<<stack[top]<<endl;
        }
};

int main()
{
    Stacks shr;
    shr.push(1);
    shr.push(2);
    shr.pop();
    shr.peek();
    return 0;
}