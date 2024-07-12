#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution {
public:
    vector<int> bottomView(Node* root) {
        vector<int> result;

        // Case when Binary Tree is already empty
        if (root == NULL) {
            return result;
        }

        // Two auxillary Data Structures 
        queue<pair<Node*, int>> q;    // Each node address and its vertical index
        map<int, int> mpp;            // Each vertical index with its bottommost node value

        q.push({root, 0});

        while (!q.empty()) {

            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int line = it.second;

            mpp[line] = node->data;

            if (node->left != NULL) {
                q.push({node->left, line - 1});
            }
            if (node->right != NULL) {
                q.push({node->right, line + 1});
            }
            // This is for Breadth First Traversal
        }

        for (auto it : mpp) {
            result.push_back(it.second);
        }

        return result;
    }
};

// Helper function to create a new node
Node* newNode(int data) {
    return new Node(data);
}

int main(){
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    Solution sol;
    vector<int> bottom_view = sol.bottomView(root);

    // Printing the result
    for (int val : bottom_view) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
