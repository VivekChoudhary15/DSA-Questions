#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int value) {
        this->next = NULL;
        this->val = value;
    }
};

class LinkedList {
public:
    ListNode* head;

    LinkedList() {
        head = NULL;
    }

    void insertAtHead(int value) {
        ListNode* temp = new ListNode(value);

        if (head == NULL) {
            head = temp;
            return;
        }

        temp->next = head;
        head = temp;
    }

    void printList() {
        ListNode* current = head;
        while (current != NULL) {
            cout << current->val << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

int main() {
    LinkedList list;
    Solution solution;

    // Inserting nodes into the linked list
    list.insertAtHead(5);
    list.insertAtHead(4);
    list.insertAtHead(3);
    list.insertAtHead(2);
    list.insertAtHead(1);

    // Print the linked list
    cout << "Original List: ";
    list.printList();

    // Find and print the middle node
    ListNode* middle = solution.middleNode(list.head);
    if (middle != NULL) {
        cout << "Middle Node Value: " << middle->val << endl;
    } else {
        cout << "The list is empty." << endl;
    }

    return 0;
}
