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
int maxw(Node* root){
    if (root == NULL) return 0;

    queue<Node*> q;
    q.push(root);

    int ans = 0;

    while(!q.empty()){
        int levelSize = q.size();
        ans = max(ans, levelSize);

        while(levelSize--){   // 🔑 THIS LOOP IS REQUIRED,  it peels complete level
            Node* curr = q.front();
            q.pop();

            if(curr->left)  q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
    return ans;
}

int main(){
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->left->left=new Node(80);
    root->right->right=new Node(900);
    root->right->left=new Node(20);
    int ans=maxw(root);
    cout<<ans;
    return 0;
}