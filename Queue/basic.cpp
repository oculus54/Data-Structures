#include <iostream>
#define size 5
using namespace std;

class queue {
    int arr[size];
    int front= -1,rear =-1;

    public:
        bool isempty(){
            return front == -1 && rear == -1;
        }
        bool isfull(){
            return (rear+1)%size==front;
        }
        void enq(int data)
        {
            if(isfull){
                cout<<"Queue is full";
                return;
            }
            if(isempty())
                front = rear =0;
            else 
                rear = (rear+1)%size;
            arr[rear] = data;
        }
        void deq(){
            if(isempty()){
                cout<<"Queue is empty";
                return;
            }
            if(front==rear) //only one element 
                front = rear = -1;
            else    
                front = (front+1) % size;
        }
        void peek()
        {
            if(isempty()){
                cout<<"Empty";
                return;
            }
            cout<<"front element is"<<arr[front]<<endl;
        }
};