// P.S.: https://leetcode.com/problems/implement-stack-using-queues/description/

#include<iostream>
#include<queue>
using namespace std;

class MyStack {
    queue<int> q;
    int size;
public:
    MyStack() {
        this->size=0;
    }
    
    void push(int x){
        q.push(x);
        for (int i=0; i<size; i++){
            q.push(q.front());
            q.pop();
        }
        size++;
    }
    
    int pop() {
        if (size==0){
            return -1;
        }
        int popped_element=q.front();
        q.pop();
        size--;
        return popped_element;
    }
    
    int top() {
        if (size==0){
            return -1;
        }
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack stack;
    stack.push(1);
    stack.push(2);
    cout << stack.top() << endl;   // Should print 2
    cout << stack.pop() << endl;   // Should print 2
    cout << stack.top() << endl;   // Should print 1
    cout << stack.pop() << endl;   // Should print 1
    cout << stack.empty() << endl; // Should print 1 (true)

    return 0;
}
