#include <iostream>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;

    ListNode(int value){
        this->val = value;
        this->next = NULL;
    }
};

class LinkedList{
    public:
    ListNode* head;

    LinkedList(){
        this->head = NULL;
    }

    void insertAtTail(int value){
        ListNode* temp = new ListNode(value);
        if (head==NULL){
            head = temp;
            return;
        }
        ListNode* current = head;
        while (current->next!=NULL){
            current = current->next;
        }
        current->next = temp;
    }

};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        LinkedList l3;
        int carry = 0;
        while (l1!=NULL || l2!=NULL || carry!=0){
            int sum = carry;
            if (l1!=NULL){
                sum+=l1->val;
                l1 = l1->next;
            }

            if (l2!=NULL){
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum/10;
            sum = sum%10;

            l3.insertAtTail(sum);
        }
        return (l3.head);
    }
};
