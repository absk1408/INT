#include <iostream>
using namespace std;
// Structure of a Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
    Node(int v)
    {
        data = v;
        left = right = nullptr;
    }
};
// Function to print inorder traversal
void printInorder(struct Node* root){ //L Ro R
    if(root->left) printInorder(root->left);  
    cout<<root->data<<" "; //in
    if(root->right) printInorder(root->right); 
    return;
}
void printPreorder(Node* root){ //Ro L R
    cout<<root->data<<" "; //pre
    if(root->left)printPreorder(root->left);
    if(root->right)printPreorder(root->right);
    return;
}
void printPostorder(Node* root){ //L R Ro
    if(root->left) printPostorder(root->left);
    if(root->right) printPostorder(root->right);
    cout<<root->data<<" "; //post
    return;

}
int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    printInorder(root);
    cout<<endl;
    printPreorder(root);
    cout<<endl;
    printPostorder(root);

    return 0;
}