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
void left_v(Node* root){
    queue<Node*> q;
    q.push(root);
    while(q.size()){
        Node* curr=q.front();
        cout<<curr->data<<" ";
        while(q.size()){
            Node* curr=q.front();
            if(curr->left!=NULL) q.push(curr->left);
            if(curr->right!=NULL) q.push(curr->right);

        }
        
    }
}
int main(){
    Node* root=new Node(10);
     root->left=new Node(200);
    root->right=new Node(30);
    //root->left->left=new Node(90);
   //root->left->right=new Node(900);
    root->right->left=new Node(20);
    left_v(root);
    return 0;
}