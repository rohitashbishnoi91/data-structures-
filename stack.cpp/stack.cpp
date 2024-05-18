#include<iostream>
using namespace std;

#define MAX 100

class stack{
    private:
    int top;
    public:
    int arr[MAX]; //maximum size of the stack
    stack() {top=-1;}

    //utility function declaration
    bool push(int x);
    int pop();
    int peek();
    bool is_empty();
};

//function define
bool stack::push(int x){
    if(top>=(MAX-1)){
     cout<<"stack overflow"<<endl;
     return false;
    }
    else{
        arr[++top]=x;
        cout<<x<<"pushed into the stack\n";
        return true;
    }
}

int stack::pop(){
    if(top<0){
        cout<<"stack underflow";
        return -1;
    }
    else{
        int x=arr[top--];
        return x;
    }
}

int stack::peek(){
    if(top<0){
        cout<<"stack is empty";
        return -1;
    }
    else{
        int x=arr[top];
        return x;
    }
}

bool stack::is_empty(){
    return (top<0);
}


int main(){
    class stack s;
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    cout<<s.pop()<<"popped from the stack \n";

    cout<<"top element is: "<<s.peek()<<endl;

    //print all elements in the stack
    while(!s.is_empty()){
        cout<<s.peek()<<" ";
        s.pop();
    }
    return 0;
}