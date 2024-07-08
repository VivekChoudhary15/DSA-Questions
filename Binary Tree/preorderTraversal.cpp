#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        this->left = NULL;
        this->right = NULL;
        this->val = value;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorder(root, result);
        return result;
    }

private:
    void preorder(TreeNode* root, vector<int>& result) {
        if (root == NULL) {
            return;
        }

        result.push_back(root->val);
        preorder(root->left, result);
        preorder(root->right, result);
    }
};

void printTraversal(const string& traversalType, const vector<int>& result) {
    cout << traversalType << " Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    // Create a sample binary tree
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    vector<int> preorderResult = solution.preorderTraversal(root);

    printTraversal("Preorder", preorderResult);

    // Clean up memory
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
