#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int ans = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            unsigned long long mmin = q.front().second; 
            unsigned long long first, last;

            for (int i = 0; i < size; i++) {
                unsigned long long curr_idx = q.front().second - mmin; 
                TreeNode* node = q.front().first;
                q.pop();

                if (i == 0) {
                    first = curr_idx;
                }
                if (i == size - 1) {
                    last = curr_idx;
                }

                if (node->left) {
                    q.push({node->left, 2 * curr_idx + 1});
                }
                if (node->right) {
                    q.push({node->right, 2 * curr_idx + 2});
                }
            }

            ans = max(ans, static_cast<int>(last - first + 1));
        }

        return ans;
    }
};

int main() {
    // Create a sample tree:
    //         1
    //       /   \
    //      3     2
    //     / \     \
    //    5   3     9
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    Solution sol;
    int result = sol.widthOfBinaryTree(root);
    cout << "The maximum width of the binary tree is: " << result << endl;

    // Clean up memory
    delete root->right->right;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
