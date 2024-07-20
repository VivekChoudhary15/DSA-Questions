#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) {
            return nullptr;
        }
        return convert(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* convert(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        
        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = convert(nums, left, mid - 1);
        node->right = convert(nums, mid + 1, right);
        
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
    vector<int> sorted_nums = {-10, -3, 0, 5, 9};
    Solution solution;
    TreeNode* bst_root = solution.sortedArrayToBST(sorted_nums);

    cout << "In-order Traversal of BST: ";
    inOrderTraversal(bst_root);
    cout << endl;

    return 0;
}
