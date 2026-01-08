//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#define loop(x,n) for(int i=x;i<n;i++)
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

using namespace std;
int max_bt(Node* root){
    if(root==NULL) return -1;
    int x=max(max_bt(root->left),max_bt(root->right));
    if(x<root->data) return root->data;
    else return x;
}
int main(){
    Node* root=new Node(10);
     root->left=new Node(200);
    root->right=new Node(30);
    root->left->left=new Node(90);
    root->left->right=new Node(90);
    root->right->left=new Node(20);
    int ans=max_bt(root);
    cout<<ans;
    return 0;
}