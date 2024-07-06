#include <iostream>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;

    ListNode(int value){
        this->next = NULL;
        this->val = value;
    }
};

class Solution{
public:
    void deleteNode(ListNode* node){
        if (node == NULL || node->next == NULL) {
            return;
        }
        ListNode* temp = node->next;
        node->val = temp->val;
        node->next = temp->next;
        delete temp;
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

// Function to create a new ListNode
ListNode* createNode(int value) {
    ListNode* newNode = new ListNode(value);
    return newNode;
}

int main() {
    // Create linked list: 1->2->3->4->5
    ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    cout << "Original List: ";
    printList(head);

    Solution solution;

    // Deleting node with value 3 (assuming we have the pointer to the node)
    ListNode* nodeToDelete = head->next->next; // Node with value 3
    solution.deleteNode(nodeToDelete);

    cout << "List after deleting node with value 3: ";
    printList(head);

    return 0;
}
