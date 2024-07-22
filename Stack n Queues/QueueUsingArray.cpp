#include<iostream>
using namespace std;

class MyQueue{
private:
    int arr[100005];
    int front;
    int rear;

public:
    MyQueue(){
        this->front=0;
        this->rear=0;
    }

    void push(int x){
        arr[rear]=x;
        rear++;
    }

    int pop(){
        if (rear==front){
            return -1;
        }
        int popped_element=arr[front];
        front++;
        return popped_element;

    }
};

int main() {
    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.pop() << endl;  // Should print 10
    cout << q.pop() << endl;  // Should print 20
    cout << q.pop() << endl;  // Should print 30
    cout << q.pop() << endl;  // Should print -1 (queue is empty)

    q.push(40);
    q.push(50);

    cout << q.pop() << endl;  // Should print 40
    cout << q.pop() << endl;  // Should print 50

    return 0;
}
