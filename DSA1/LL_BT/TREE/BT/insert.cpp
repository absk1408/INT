#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Proper BST insertion function
Node* insert_n(Node* root, int x) {
    if (root == NULL) 
        return new Node(x);

    if (x < root->data)
        root->left = insert_n(root->left, x);
    else
        root->right = insert_n(root->right, x);

    return root;
}

// Inorder traversal to check the BST
void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    
    // Inserting values into BST
    root = insert_n(root, 10);
    root = insert_n(root, 20);
    root = insert_n(root, 30);
    root = insert_n(root, 40);
    root = insert_n(root, 80);
    root = insert_n(root, 900);

    cout << "Inorder traversal of BST: ";
    inorder(root);  // Should print sorted order
    cout << endl;
    
    return 0;
}
