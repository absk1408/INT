//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
#define loop(x,n) for(int i=x;i<n;i++)
using namespace std;

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
void spiral(Node* root){
    
    
}
int main(){
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->left->left=new Node(80);
    root->right->right=new Node(900);
    root->right->left=new Node(20);
    spiral(root);
    return 0;
}