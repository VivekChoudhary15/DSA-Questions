#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

void RecursionLeft(Node* root, int level, vector<int>& result){
    if (root == NULL){
        return;
    }

    if (result.size() == level){
        result.push_back(root->data);
    }

    RecursionLeft(root->left, level + 1, result);
    RecursionLeft(root->right, level + 1, result);
}

vector<int> leftView(Node *root){
    vector<int> result;
    RecursionLeft(root, 0, result);
    return result;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);

    vector<int> result = leftView(root);

    cout << "Left view of the binary tree is: ";
    for (int i : result){
        cout << i << " ";
    }

    // Clean up the memory
    delete root->left->left->left;
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
