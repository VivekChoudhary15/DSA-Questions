// Recursive Approach
// This doesn't need the use of any auxiliary data structure as in case of BFS Apprach
// Also has the same time complexity i.e. O(N)
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node(): val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int value): val(value), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
    void connectHelper(Node* l, Node* r) {
        if (l == NULL || r == NULL) {
            return;
        }
        l->next = r;
        connectHelper(l->left, l->right);
        connectHelper(r->left, r->right);
        connectHelper(l->right, r->left);
    }

public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return NULL;
        }
        connectHelper(root->left, root->right);
        return root;
    }
};

void printLevels(Node* root) {
    while (root) {
        Node* current = root;
        while (current) {
            cout << current->val << " ";
            current = current->next;
        }
        cout << "#" << endl; // Indicate end of level
        root = root->left;
    }
}

int main() {
    // Create a sample perfect binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    
    Solution solution;

    solution.connect(root);

    printLevels(root);

    // Clean up the allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
