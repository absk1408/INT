#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// Definition of Binary Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to check height and balance together
int checkHeight(Node* root) {
    if (root == nullptr)
        return 0;

    int leftHeight = checkHeight(root->left);
    if (leftHeight == -1)
        return -1;

    int rightHeight = checkHeight(root->right);
    if (rightHeight == -1)
        return -1;

    if (abs(leftHeight - rightHeight) > 1)
        return -1;

    return 1 + max(leftHeight, rightHeight);
}

// Function to check if tree is balanced
bool isBalanced(Node* root) {
    return checkHeight(root) != -1;
}

// Driver code
int main() {
    /*
            1
           /
          2
         /
        3
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);

    if (isBalanced(root))
        cout << "Tree is Balanced\n";
    else
        cout << "Tree is NOT Balanced\n";

    return 0;
}
