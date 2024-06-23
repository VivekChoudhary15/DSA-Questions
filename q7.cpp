// Merge two sorted lists into a sorted third list and return the head of the third list

#include <iostream>
using namespace std;


class ListNode{
    public:
    int val;
    ListNode* next;

    ListNode(int data){
        this->next = nullptr;
        this->val = data;
    }
};

class LinkedList{
public:
    ListNode* head;
    ListNode* tail;

    LinkedList(){
        this->head = NULL;
        this->tail = NULL;
    }

    void insertAtTail(int data){
        ListNode* temp = new ListNode(data);
        if (head == NULL){
            head = temp;
            tail = temp;
            return;
        }
        // ListNode* curr = head;
        // while (curr->next!=NULL){
        //     curr = curr->next;
        // }

        // curr->next = temp;
        tail->next = temp;
        tail = temp;
    }
};

class Solution{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        LinkedList l3;
        while (list1!=NULL && list2!=NULL){
            if (list1->val>list2->val){
                l3.insertAtTail(list2->val);
                list2 = list2->next;
            }else{
                l3.insertAtTail(list1->val);
                list1 = list1->next;
            }
        }        
        while (list1!=NULL){
            l3.insertAtTail(list1->val);
            list1=list1->next;
        }
        while (list2!=NULL){
            l3.insertAtTail(list2->val);
            list2=list2->next;
        }
        return l3.head;
    }

};

int main(){
    LinkedList l1;
    LinkedList l2;
    l2.insertAtTail(1);
    l2.insertAtTail(2);
    l2.insertAtTail(4);
    l1.insertAtTail(1);
    l1.insertAtTail(3);
    l1.insertAtTail(4);
    Solution sol;
    ListNode* list3=sol.mergeTwoLists(l1.head, l2.head);
    while (list3!=NULL)
    {
        cout<<list3->val<<" ";
        list3=list3->next;
    }
    return 0;
}