#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        left=nullptr;
        right=nullptr;
    }
};
class bst{
    Node* root;
    public:
    bst(){ root=nullptr;}
    void add(int val){
        root=addN(root,val);
    }
    Node* addN(Node* root,int val){
        if(root==nullptr){
            Node* temp=new Node(val);
            return temp;
        }
        if(val > root->data){
            root->right=addN(root->right,val);
        }
        if(val<root->data){
            root->left=addN(root->left,val);
        }
        return root;

    }
    bool search(int val){
        return searchN(root,val);
    }
    bool searchN(Node* root,int val){
        if(!root) return false;
        if(root->data==val) return true;
        if(val>root->data){
            return searchN(root->right,val);
        }
        return searchN(root->left,val);

    }
    void dlt(int val){
        root=dltN(root,val);
    }
    Node* succ(Node* head){
        while(head->left){
            head=head->left;
        }
        return head;
    }
    Node* dltN(Node* root,int val){
        if(root==nullptr) return root;
        if(val>root->data){
            root->right=dltN(root->right,val);
        }
        else if(val < root->data){
            root->left=dltN(root->left,val);
        }
        else{
            if(!root->left&&root->right){
                delete root;
                return nullptr;
            }
            else if(!root->left){
                Node* temp=root->right;
                delete root;
                return temp;;
            }
            else if(!root->right){
                Node* temp=root->left;
                delete root;
                return temp;
            }
            else{
                Node* temp=succ(root->right);
                root->data=temp->data;
                root->right=dltN(root->right,temp->data);
            }
        }
        return root;
    }
};

int main(){
    return 0;
}