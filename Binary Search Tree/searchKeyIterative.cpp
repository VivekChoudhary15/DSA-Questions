#include <iostream>
using namespace std;

struct TreeNode {
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
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root != NULL && root->val != val) {
            if (root->val > val) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return root;
    }
};

void insert(TreeNode*& root, int val) {
    if (root == NULL) {
        root = new TreeNode(val);
    } else if (val < root->val) {
        insert(root->left, val);
    } else {
        insert(root->right, val);
    }
}

int main() {
    TreeNode* root = NULL;
    insert(root, 4);
    insert(root, 2);
    insert(root, 7);
    insert(root, 1);
    insert(root, 3);

    Solution solution;
    
    int val = 2;
    TreeNode* result = solution.searchBST(root, val);
    
    if (result != NULL) {
        cout << "Found node with value: " << result->val << endl;
    } else {
        cout << "Value " << val << " not found in the BST." << endl;
    }
    
    val = 5;
    result = solution.searchBST(root, val);
    
    if (result != NULL) {
        cout << "Found node with value: " << result->val << endl;
    } else {
        cout << "Value " << val << " not found in the BST." << endl;
    }

    return 0;
}
