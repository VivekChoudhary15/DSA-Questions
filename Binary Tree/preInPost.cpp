#include<iostream>
#include <stack>
#include<vector>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};

vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<vector<int>> result;
    vector<int> pre;
    vector<int> in;
    vector<int> post;

    if (root==NULL){
        return{};
    }

    stack<pair<TreeNode*, int>> st;

    st.push({root, 1});

    while (!st.empty()){
        auto it=st.top();
        st.pop();

        if (it.second==1){
            pre.push_back(it.first->data);
            it.second=2;
            st.push(it);

            if (it.first->left!=NULL){
                st.push({it.first->left,1});
            }
        }else if (it.second==2){
            in.push_back(it.first->data);
            it.second=3;
            st.push(it);

            if (it.first->right!=NULL){
                st.push({it.first->right, 1});
            }
        }else{
            post.push_back(it.first->data);
        }
    }    

    result.push_back(in);
    result.push_back(pre);
    result.push_back(post);

    return result;
}
