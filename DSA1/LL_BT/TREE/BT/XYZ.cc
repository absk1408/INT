#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int key; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NULL;
  }
};

Node *floor(Node *root, int x){
    Node *res=NULL;
    while(root!=NULL){
        if(root->key==x)
            return root;
        else if(root->key>x)
            root=root->left;
        else{
            res=root;
            root=root->right;
        }
    }
    return res;
} 

int main() {
	
	Node *root=new Node(50);
	root->left=new Node(30);
	root->left->left=new Node(70);
	root->right=new Node(20);
	root->right->left=new Node(40);
	root->right->left->left=new Node(55);
	root->right->right=new Node(65);
	int x=17;
	
	cout<<"Floor: "<<(floor(root,17)->key);
}