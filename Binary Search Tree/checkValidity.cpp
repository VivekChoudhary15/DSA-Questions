#include<iostream>
#include<climits>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value){
        this->left=NULL;
        this->right=NULL;
        this->val=value;
    }
};

class Solution {
    long long Prev=INT_MIN;

    void Inorder(TreeNode* root, bool& Is){
        if (root==NULL){
            return;
        }
        Inorder(root->left, Is);

        if (root->val<=Prev){
            Is=false;
        }Prev=root->val;

        Inorder(root->right, Is);
    }

public:
    bool isValidBST(TreeNode* root) {
        bool Is=true;
        Inorder(root, Is); //This function would check whether the inorder traversal is sorted or not
        return Is;
    }
};