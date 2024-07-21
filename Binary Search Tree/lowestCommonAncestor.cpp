#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root != NULL) {
            if (p->val < root->val && q->val < root->val) {
                root = root->left;
            } else if (p->val > root->val && q->val > root->val) {
                root = root->right;
            } else {
                return root;
            }
        }
        return NULL;
    }
};

int main() {
    // Constructing the following BST
    //         20
    //        /  \
    //      10    30
    //     /  \
    //    5    15
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(15);

    TreeNode* p = root->left->left; // Node with value 5
    TreeNode* q = root->left->right; // Node with value 15

    Solution sol;
    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);
    if (lca != nullptr) {
        cout << "LCA of " << p->val << " and " << q->val << " is " << lca->val << endl;
    } else {
        cout << "LCA not found" << endl;
    }

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
