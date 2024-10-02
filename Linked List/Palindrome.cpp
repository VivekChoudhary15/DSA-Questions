// P.S:-https://leetcode.com/problems/palindrome-linked-list/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        while (curr!=NULL){
            ListNode* next=curr->next;
            curr->next=prev;
            // curr=next;
            prev=curr;
            curr=next;
        }return prev;
        
    }

public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while (fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* rev=reverse(slow);
        while (rev!=NULL){
            if (head->val!=rev->val){
                return false;
            }head=head->next;
            rev=rev->next;
        }return true;
    }
};
