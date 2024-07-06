#include<iostream>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;

        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        if (fast == NULL) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        return head;
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
    int n = 2;
    head = solution.removeNthFromEnd(head, n);

    cout << "List after removing " << n << "th node from end: ";
    printList(head);

    return 0;
}
