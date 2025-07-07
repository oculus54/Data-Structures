#include <iostream>
#include <stack>
using namespace std;
void print(stack <int> st){
    while(st.top()){
        cout<<st.top()<<endl;
        st.pop();
    }
}

int main()
{
    stack<int> s1;
    for(int i =1;i<=5;i++)
        s1.push(i);
    print(s1);
    return 0;
}
