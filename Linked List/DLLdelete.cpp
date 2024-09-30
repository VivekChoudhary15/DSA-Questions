P.S:-https://www.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=delete-node-in-doubly-linked-list

class Solution{
public:
    // Function to delete a node at given position.
    Node* deleteNode(Node* head, int x) {
        if (head==NULL){
            return NULL;
        }
        
        if (x==1){
            Node* temp=head;
            head=head->next;
            if (head!=NULL){
                head->prev=NULL;
            }
            delete temp;
            return head;
        }
        
        Node* curr=head;
        int counter=1;
        while (counter!=x-1 && curr->next!=NULL){
            curr=curr->next;
            counter++;
        }curr->next=curr->next->next;
        if (curr->next==NULL){
            return head;
        }else{
            curr->next->prev=curr;
            return head;
        }
    }
};
