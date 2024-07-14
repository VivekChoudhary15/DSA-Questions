#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

// TreeNode class definition
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

// Solution class definition
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int maxi = INT_MIN;
        int mini = INT_MAX;

        if (root == NULL) {
            return {};
        }

        queue<pair<TreeNode*, pair<int, int>>> q;
        map<pair<int, int>, vector<int>> mpp;

        q.push({root, {0, 0}});

        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int vertical = q.front().second.first;
            int linear = q.front().second.second;
            q.pop();

            maxi = max(vertical, maxi);
            mini = min(vertical, mini);

            mpp[{vertical, linear}].push_back(node->val);

            if (node->left != NULL) {
                q.push({node->left, {vertical - 1, linear + 1}});
            }

            if (node->right != NULL) {
                q.push({node->right, {vertical + 1, linear + 1}});
            }
        }

        vector<vector<int>> result(maxi - mini + 1);
        for (auto it : mpp) {
            sort(it.second.begin(), it.second.end());
            for (auto it2 : it.second) {
                result[it.first.first - mini].push_back(it2);
            }
        }

        return result;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<vector<int>> result = sol.verticalTraversal(root);

    cout << "Vertical Traversal:" << endl;
    for (auto& vec : result) {
        for (int num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }

    // Clean up allocated memory
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
