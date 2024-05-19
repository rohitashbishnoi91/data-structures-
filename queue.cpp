#include<iostream>
using namespace std;

#define n 100

class queue{
    private:
    int front;
    int rear;
    int cnt;
    public:
    int arr[n];
    queue(){
        front=rear=cnt=0;
    }

    //utility function declaration
    bool push(int x);
    bool pop();
    int top();
    bool is_empty();
    void display();
};

bool queue::push(int x){
  if(cnt==n){
    cout<<"queue is full"<<endl;
    return false;
  }
  else{
    arr[rear%n]=x;
    rear++;
    cnt++;
    cout<<x<<"pushed into the stack\n";
    return true;
  }
}

bool queue::pop(){
    if(cnt==0){
        cout<<"queue is empty"<<endl;
        return false;
    }
        arr[front%n]=-1;
        front++;
        cnt--;
        return true;
    
}

int queue::top(){
    if(cnt==0) return -1;
    return arr[front%n];
}

bool queue::is_empty(){
    return (cnt==0);
}

void queue::display(){
    for(int i=front;i<rear;i++){
        cout<<arr[i%n]<<" ";
    }
    cout<<endl;
}
int main(){
class queue q;
q.push(1);
q.push(2);
q.push(3);
q.display();
cout<<q.pop()<<" top of the queue is popped "<<endl;
q.display();

return 0;
}