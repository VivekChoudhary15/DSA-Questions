#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node(int value) : val(value) , left(NULL), right(NULL), next(NULL){}

};

// Solution using BFS
/*class Solution{
public:
    Node* connect(Node* root){
        if (root==NULL){
            return NULL;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()){
            int size=q.size();
            for (int i=0; i<size; i++){
                Node* node=q.front();
                q.pop();

                if (i<size-1){
                    node->next=q.front();
                }

                if (node->left){
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }
        return root;
    }
};
*/

// Solution using DFS (No auxiliary space reqd)
class Solution{
public:
    Node* connect(Node* root){
        if (root==NULL){
            return;
        }
        
    }
};