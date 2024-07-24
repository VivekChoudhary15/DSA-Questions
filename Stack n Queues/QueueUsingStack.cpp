// P.S.: https://leetcode.com/problems/implement-queue-using-stacks/

#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
    stack<int> input, output;
    int size;
public:
    MyQueue() {
        this->size = 0;
    }

    void push(int x) {
        while (!input.empty()) {
            output.push(input.top());
            input.pop();
        }

        input.push(x);

        while (!output.empty()) {
            input.push(output.top());
            output.pop();
        }
        size++;
    }

    int pop() {
        if (size == 0) {
            return -1;
        }
        int frontElement = input.top();
        input.pop();
        size--;
        return frontElement;
    }

    int peek() {
        if (size == 0) {
            return -1;
        }
        return input.top();
    }

    bool empty() {
        return input.empty();
    }
};

int main() {
    MyQueue queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);

    cout << queue.peek() << endl;  // Should print 1
    cout << queue.pop() << endl;   // Should print 1
    cout << queue.peek() << endl;  // Should print 2
    cout << queue.pop() << endl;   // Should print 2
    cout << queue.peek() << endl;  // Should print 3
    cout << queue.pop() << endl;   // Should print 3
    cout << queue.empty() << endl; // Should print 1 (true)

    return 0;
}
