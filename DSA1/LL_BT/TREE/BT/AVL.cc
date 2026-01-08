// C++ program to insert a node in AVL tree 
#include <bits/stdc++.h> 
using namespace std; 

// An AVL tree node 
struct Node { 
    int key; 
    Node *left; 
    Node *right; 
    int height; 

    Node(int k) { 
        key = k; 
        left = nullptr; 
        right = nullptr; 
        height = 1; 
    }
}; 

// A utility function to 
// get the height of the tree 
int height(Node *N) { 
    if (N == nullptr) 
        return 0; 
    return N->height; 
} 

// A utility function to right 
// rotate subtree rooted with y 
Node *rightRotate(Node *y) { 
    Node *x = y->left; 
    Node *T2 = x->right; 

    // Perform rotation 
    x->right = y; 
    y->left = T2; 

    // Update heights 
    y->height = 1 + max(height(y->left), 
                    height(y->right)); 
    x->height = 1 + max(height(x->left), 
                        height(x->right)); 

    // Return new root 
    return x; 
} 

// A utility function to left rotate 
// subtree rooted with x 
Node *leftRotate(Node *x) { 
    Node *y = x->right; 
    Node *T2 = y->left; 

    // Perform rotation 
    y->left = x; 
    x->right = T2; 

    // Update heights 
    x->height = 1 + max(height(x->left), 
                        height(x->right)); 
    y->height = 1 + max(height(y->left), 
                        height(y->right)); 

    // Return new root 
    return y; 
} 

// Get balance factor of node N 
int getBalance(Node *N) { 
    if (N == nullptr) 
        return 0; 
    return height(N->left) - height(N->right); 
} 

// Recursive function to insert a key in 
// the subtree rooted with node 
Node* insert(Node* root, int key) { 
  
    // Perform the normal BST insertion
    if (root == nullptr) 
        return new Node(key); 

    if (key < root->key) 
        root->left = insert(root->left, key); 
    else if (key > root->key) 
        root->right = insert(root->right, key); 
    else // Equal keys are not allowed in BST 
        return root; 

    // Update height of this ancestor node 
    root->height = 1 + max(height(root->left),
                           height(root->right)); 

    // Get the balance factor of this ancestor node 
    int balance = getBalance(root); 

    // If this node becomes unbalanced, 
    // then there are 4 cases 

    // Left Left Case 
    if (balance > 1 && key < root->left->key) 
        return rightRotate(root); 

    // Right Right Case 
    if (balance < -1 && key > root->right->key) 
        return leftRotate(root); 

    // Left Right Case 
    if (balance > 1 && key > root->left->key) { 
        root->left = leftRotate(root->left); 
        return rightRotate(root); 
    } 

    // Right Left Case 
    if (balance < -1 && key < root->right->key) { 
        root->right = rightRotate(root->right); 
        return leftRotate(root); 
    } 

    // Return the (unchanged) node pointer 
    return root; 
} 

// A utility function to print 
// preorder traversal of the tree 
void preOrder(Node *root) { 
    if (root != nullptr) { 
        cout << root->key << " "; 
        preOrder(root->left); 
        preOrder(root->right); 
    } 
} 

// Driver Code 
int main() { 
    Node *root = nullptr; 
    
    // Constructing tree given in the above figure 
    root = insert(root, 10); 
    root = insert(root, 20); 
    root = insert(root, 30); 
    root = insert(root, 40); 
    root = insert(root, 50); 
    root = insert(root, 25); 
    
    /* The constructed AVL Tree would be 
              30 
            /   \ 
          20     40 
         /  \      \ 
       10   25     50 
    */
    
    // Preorder traversal 
    preOrder(root); 
    
    return 0; 
}