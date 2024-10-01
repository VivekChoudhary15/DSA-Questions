class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        if (head==NULL){
            return head;
        }
        
        DLLNode* curr = head;
        DLLNode* temp=NULL;
        while (curr!=NULL){
            temp = curr->prev;
            curr->prev=curr->next;
            curr->next=temp;
            curr=curr->prev;
        }
        
        if (temp!=NULL){
            head=temp->prev;
        }return head;
        
    }
};
