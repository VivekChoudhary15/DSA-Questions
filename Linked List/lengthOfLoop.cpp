class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        Node* slow=head;
        Node* fast=head;
        while (fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if (slow==fast){
                slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }int counter=1;
                fast=fast->next;
                while (slow!=fast){
                    fast=fast->next;
                    counter++;
                }return counter;
            }
        }return 0;
    }
};
