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