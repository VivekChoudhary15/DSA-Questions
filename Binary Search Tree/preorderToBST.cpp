#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return buildBST(preorder, index, INT_MIN, INT_MAX);
    }

private:
    TreeNode* buildBST(const vector<int>& preorder, int& index, int minVal, int maxVal) {
        if (index >= preorder.size()) {
            return nullptr;
        }
        int val = preorder[index];
        if (val < minVal || val > maxVal) {
            return nullptr;
        }
        
        TreeNode* node = new TreeNode(val);
        index++;
        node->left = buildBST(preorder, index, minVal, val);
        node->right = buildBST(preorder, index, val, maxVal);
        
        return node;
    }
};

void inOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->val << " ";
    inOrderTraversal(root->right);
}

int main() {
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    Solution solution;
    TreeNode* bst_root = solution.bstFromPreorder(preorder);

    cout << "In-order Traversal of BST: ";
    inOrderTraversal(bst_root);
    cout << endl;

    return 0;
}
