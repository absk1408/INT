//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<queue>
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
bool c_sum(Node* root,int data){
    if(root==NULL) return true;
    if(root->left==NULL&&root->right==NULL) return true;
    if(root->left!=NULL) data-(root->left->data);
    if(root->right!=NULL){
        if(data!=root->right->data) return false;
    }
    if(root->left!=NULL)c_sum(root->left,root->left->data);
    if(root->right!=NULL)c_sum(root->right,root->right->data);


}
bool c_s(Node* root){
    
}
int main(){
    Node* root=new Node(10);
     root->left=new Node(200);
    root->right=new Node(30);
    //root->left->left=new Node(90);
   //root->left->right=new Node(900);
    root->right->left=new Node(20);
    cout<<c_sum(root,root->data);
    return 0;
}