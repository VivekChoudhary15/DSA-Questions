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
        this->head = NULL;
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

    void insertAtTail(int value) {
        ListNode* temp = new ListNode(value);
        if (head == nullptr) {
            head = temp;
            return;
        }
        ListNode* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while (curr != NULL) {
            ListNode* nextpointer = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextpointer;
        }

        return prev;
    }
};

int main() {
    LinkedList list;
    Solution solution;

    // Inserting nodes into the linked list
    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.insertAtTail(5);

    // Print the original linked list
    cout << "Original List: ";
    list.printList();

    // Reverse the linked list
    ListNode* reversedHead = solution.reverseList(list.head);

    // Print the reversed linked list
    cout << "Reversed List: ";
    ListNode* current = reversedHead;
    while (current != NULL) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;

    return 0;
}
