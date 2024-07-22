#include<iostream>
using namespace std;

class MyStack{
private:
    int arr[1000];
    int top;

public:
    MyStack(){
        this->top=-1;
    }

    void push(int x){
        top++;
        arr[top]=x;
    }

    int pop(){ 
        if (top==-1){
            return -1;
        }
        int popped_element=arr[top];
        top--;
        return popped_element;
    }
};

int main() {
    MyStack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.pop() << endl;  // Should print 30
    cout << s.pop() << endl;  // Should print 20
    cout << s.pop() << endl;  // Should print 10
    cout << s.pop() << endl;  // Should print -1 (stack is empty)

    // Test stack overflow
    for (int i = 0; i < 1000; ++i) {
        s.push(i);
    }
    s.push(1000);  // Should print "Stack overflow"

    cout << s.pop() << endl;  // Should print 999

    return 0;
}
