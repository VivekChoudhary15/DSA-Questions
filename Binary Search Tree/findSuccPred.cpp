#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
        // Base Case
        if (root == NULL) {
            return;
        }

        if (root->val == key) {
            if (root->left != NULL) {
                Node* temp = root->left;
                while (temp->right != NULL) {
                    temp = temp->right;
                }
                pre = temp;
            }

            if (root->right != NULL) {
                Node* temp = root->right;
                while (temp->left != NULL) {
                    temp = temp->left;
                }
                suc = temp;
            }
        } else if (root->val > key) {
            suc = root;
            findPreSuc(root->left, pre, suc, key);
        } else {
            pre = root;
            findPreSuc(root->right, pre, suc, key);
        }
    }
};

int main() {
    // Constructing the following BST
    //         20
    //        /  \
    //      10    30
    //     /  \
    //    5    15
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);

    int key = 10;
    Node* pre = NULL;
    Node* suc = NULL;

    Solution sol;
    sol.findPreSuc(root, pre, suc, key);

    if (pre != NULL) {
        cout << "Predecessor is " << pre->val << endl;
    } else {
        cout << "No Predecessor" << endl;
    }

    if (suc != NULL) {
        cout << "Successor is " << suc->val << endl;
    } else {
        cout << "No Successor" << endl;
    }

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
