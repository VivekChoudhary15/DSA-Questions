// P.S.: https://www.naukri.com/code360/problems/sort-a-stack_985275?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include<iostream>
#include<stack>
using namespace std;

void insertInSortedOrder(stack<int> &st, int element){
    if (st.empty() || st.top()<=element){
        st.push(element);
        return;
    }

    int topElement=st.top();
    st.pop();

    insertInSortedOrder(st, element);

    st.push(topElement);
}

void sortStack(stack<int> &Stack){
    if (Stack.empty()){
        return;
    }

    int topElement = Stack.top();
    Stack.pop();

    sortStack(Stack);

    insertInSortedOrder(Stack, topElement);
}

// Utility function to print the stack
void printStack(std::stack<int> st) {
    while (!st.empty()) {
        std::cout << st.top() << " ";
        st.pop();
    }
    std::cout << std::endl;
}

int main() {
    std::stack<int> st;
    st.push(30);
    st.push(20);
    st.push(50);
    st.push(10);
    st.push(40);

    std::cout << "Original stack: ";
    printStack(st);

    sortStack(st);

    std::cout << "Sorted stack (descending order): ";
    printStack(st);

    return 0;
}
