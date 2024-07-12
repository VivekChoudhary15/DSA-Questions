#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> topView(Node* root) {
        vector<int> result;

        if (root == NULL) return result; 

        queue<pair<Node*, int>> q;
        map<int, int> mpp;

        q.push({root, 0});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            Node* node = it.first;
            int line = it.second;

            // We would be only adding data to the map if there doesn't exist any data for that vertical index
            if (mpp.find(line) == mpp.end()) {
                mpp[line] = node->data;
            }

            if (node->left != NULL) {
                q.push({node->left, line - 1});
            }

            if (node->right != NULL) {
                q.push({node->right, line + 1});
            }
        }

        for (auto it : mpp) {
            result.push_back(it.second);
        }
        return result;
    }
};

// Helper function to create a new node
Node* newNode(int data) {
    Node* node = new Node(data);
    node->left = node->right = NULL;
    return node;
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    Solution sol;
    vector<int> top_view = sol.topView(root);

    // Printing the result
    for (int val : top_view) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
