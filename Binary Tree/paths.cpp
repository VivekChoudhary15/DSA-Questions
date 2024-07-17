#include <iostream>
#include<vector>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int value){
        this->data=value;
        this->left=NULL;
        this->right=NULL;
    }
};


class Solution {

    void UtilityFn(Node* root, vector<int> path, int len, vector<vector<int>> &paths){
        if (root==NULL){
            return;
        }

        if (path.size() <= len) {
            path.push_back(root->data);
        } else {
            path[len] = root->data;
        }
        len++;

        if (root->right==NULL && root->left==NULL){
            paths.push_back(vector<int>(path.begin(), path.begin() + len));
        }else{
            UtilityFn(root->left, path, len, paths);
            UtilityFn(root->right, path, len, paths);
        }
    }

public:
    vector<vector<int>> Paths(Node* root) {
        vector<int> path(20005);
        vector<vector<int>> paths;
        
        UtilityFn(root, path, 0, paths);

        return paths;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;

    vector<vector<int>> paths = sol.Paths(root);

    // Print all the paths
    for (const auto& path : paths) {
        for (int val : path) {
            cout << val << " ";
        }
        cout << endl;
    }

}
