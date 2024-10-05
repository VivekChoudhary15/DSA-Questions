class Solution
{
    Node* getTail(Node* head){
        while (head->next){
            head=head->next;
        }
        return head;
    }

public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int,int>> result;
        Node* i=head;
        Node* j=getTail(head);
        
        while (i && j && i!=j && i->prev!=j){
            if (i->data+j->data==target){
                result.push_back({i->data,j->data});
                i=i->next;
                j=j->prev;
            }
            else if (i->data+j->data<target){
                i=i->next;
            }else {
                j=j->prev;
            }
        }
        return result;
    }
};
