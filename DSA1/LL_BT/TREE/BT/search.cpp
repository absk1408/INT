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

// Search function for BST
bool search(Node* root, int key) {
    if (root == NULL)
        return false;
    
    if (root->data == key)
        return true;
    
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main() {
    Node* root = NULL;
    
    // Inserting values into BST
    root = insert_n(root, 50);
    root = insert_n(root, 30);
    root = insert_n(root, 70);
    root = insert_n(root, 20);
    root = insert_n(root, 40);
    root = insert_n(root, 60);
    root = insert_n(root, 80);

    // Searching for elements in BST
    int key = 40;
    if (search(root, key))
        cout << key << " is found in the BST.\n";
    else
        cout << key << " is NOT found in the BST.\n";

    key = 25;
    if (search(root, key))
        cout << key << " is found in the BST.\n";
    else
        cout << key << " is NOT found in the BST.\n";

    return 0;
}
