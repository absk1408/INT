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

// Insert function for BST
Node* insert_n(Node* root, int x) {
    if (root == NULL) 
        return new Node(x);

    if (x < root->data)
        root->left = insert_n(root->left, x);
    else
        root->right = insert_n(root->right, x);

    return root;
}

// Function to find the inorder successor (smallest node in right subtree)
Node* findMin(Node* root) {
    while(root&&root->left==nullptr){
        root=root->left;
    }
    return root;

}

// Function to delete a node from BST
Node* deleten(Node* root, int key) {
    if(root==NULL) return NULL;
    if(root->data>key) root->left= deleten(root->left,key);
    else if(root->data<key) root->right=deleten(root->right,key);
    else {
        if(root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;


        }
        else if(root->left==NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        Node* temp=findMin(root->right);
        root->data=temp->data;root->right;
        root->right=deleten(root->right,temp->data);
    }
}

// Inorder traversal (to verify the BST)
void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    
    // Insert elements into BST
    root = insert_n(root, 50);
    root = insert_n(root, 30);
    root = insert_n(root, 70);
    root = insert_n(root, 20);
    root = insert_n(root, 40);
    root = insert_n(root, 60);
    root = insert_n(root, 80);

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    // Delete node 30 (has two children)
    root = delete_n(root, 30);

    cout << "Inorder after deleting 30: ";
    inorder(root);
    cout << endl;

    return 0;
}
