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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }

private:
    void inorder(TreeNode* root, vector<int>& result) {
        if (root == NULL) {
            return;
        }

        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
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
    vector<int> inorderResult = solution.inorderTraversal(root);

    printTraversal("Inorder", inorderResult);

    // Clean up memory
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
