//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
#define loop(x,n) for(int i=x;i<n;i++)
using namespace std;
int mx=0;

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

int dia(Node* root){
    if(root==NULL) return 0;
    int lh=0;
    int rh=0;
    if(root->left!=NULL){
        lh=dia(root->left);
    }
    if(root->right!=NULL){
        rh=dia(root->right);
    }
    int ans=1+lh+rh;
    if(ans>mx) mx=ans;
    return max(lh,rh)+1;
}
int main(){
    Node* root=new Node(10);
    
    root->left=new Node(20);
    root->left->left=new Node(30);
    root->left->left->left=new Node(40);
    root->left->left->left->left=new Node(60);

    root->left->left->right=new Node(50);

    root->left->right=new Node(80);
    root->left->right->right=new Node(90);
    root->left->right->right->right=new Node(18);






    root->right=new Node(60);


    
    //root->left->left->left=new Node(80);
    //root->right->right=new Node(900);
    //root->right->left=new Node(20);
    int ans=dia(root);
    cout<<ans<<endl;
    cout<<mx;      
    return 0;
}