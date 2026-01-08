#include<iostream>
#include<climits>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        left=nullptr;
        right=nullptr;
    }
};
class BST{
    public:
    Node* root;
    BST(){
        root=nullptr;
    }
    Node* insert_node(Node* root,int data){
        if(root==nullptr) return new Node(data);
        if(root->data>data){
            root->left=insert_node(root->left,data);
        }
        else root->right=insert_node(root->right,data);
        return root;
    }
    void add(int data){
        root=insert_node(root,data);
    }
    bool search_node(Node* root,int data){
        if(root==nullptr) return false;
        if(root->data==data) return true;
        bool b;
        if(root->data>data){
            b=search_node(root->left,data);
        }
        else{
            b=search_node(root->right,data);
        }
        return b;
    }
    bool search(int data){
        return search_node(root,data);
    }
    Node* remove(int data){
        return delete_node(root,data);
    }
    Node* delete_node(Node* root,int data){
        if(root==nullptr) return root;
        if(data>root->data) root->right=delete_node(root->right,data);
        else if(data<root->data) root->left=delete_node(root->left,data);
        else{
            if(!root->left&&!root->right){
                delete root;
                return nullptr;
            }
            else if(!root->right){
                Node* temp=root->left;
                delete root;
                return temp;
            }
            else if(!root->left){
                Node* temp=root->right;
                delete root;
                return temp;
            }
            else{
                int next_val=findnext(root->right);
                root->data=next_val;
                root->right=delete_node(root->right,next_val);
            }
        }
        return root;
    }
    int findnext(Node* root){
        Node* curr=root;
        while(curr->left){
            curr=curr->left;
        }
        return curr->data;
    }
    tuple<int,int> floor_ceil(int data){
        return make_tuple(floor_node(root,data),ceil_node(root,data));
    }
    int floor_node(Node* root,int val){
        Node* curr=root;
        int result=-1;
        while(curr){
            int cv=curr->data;
            if(cv==val){
                result=cv;
                break;
            }
            else if(cv>val){
                curr=curr->left;
            }
            else{
                result=cv;
                curr=curr->right;

            }
        }
        return result;
    }
    int ceil_node(Node* root,int value){
        int result=-1;Node* curr=root;
        while(curr){
            int cv=curr->data;
            if(value==cv){
                result=cv;
                break;
            }
            else if(cv<value){
                curr=curr->right;
            }
            else{
                result=cv;
                curr=curr->left;
            }
        }
        return result;
    }
};
int main(){
     BST b;
    b.add(50);
    b.add(30);
    b.add(20);
    b.add(40);
    b.add(70);
    b.add(60);
    b.add(55);
    b.add(65);
    b.add(80);
    auto[floor,ceil]=b.floor_ceil(56);
    cout<<floor<<" "<<ceil<<endl;

}