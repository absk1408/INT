#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
class Node{
    public: Node* left; Node* right; int data;
    Node(int value){
        data=value;
        right=nullptr;
        left=nullptr;
    }
};
class LNode{
    public: LNode* next; int data;
    LNode(int value){
        data=value;
        next=nullptr;
       
    }
};
class BST{public:
    Node* root;
    map<int,int> mp;
    LNode* head=new LNode(10);
    LNode* curr=head;
    BST(){
        root=nullptr;
    }
     Node* insertN(Node* root,int value){
        if(root==nullptr){
            Node* temp=new Node(value);
            return temp;
        }
        if(value>root->data){
            root->right=insertN(root->right,value);
        }
        else{
            root->left=insertN(root->left,value);
        }
        return root;
    }
    void add(int value){
        root=insertN(root,value);
    }
    void printInOrder(){
        inOrder(root);
        cout << endl;
    }
    void inOrder(Node* node) {
        if (node == nullptr) return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
    bool search(int value){
        Node* head=searchN(root,value);
        return (head!=nullptr)?true:false;
    }
    Node* searchN(Node* root,int value){
        if(root==nullptr) return root;
        if(root->data==value) return root;
        Node* temp=nullptr;
        if(value>root->data){
            temp=searchN(root->right,value);
        }
        else{
            temp=searchN(root->left,value);
        }
        return temp;
    }
    int findnext(Node* root) {
        if (root == nullptr || root->right == nullptr) return -1;
        Node* temp = findnextn(root->right);
        return (temp != nullptr) ? temp->data : -1;
    }
    Node* findnextn(Node* head) {
        if (head == nullptr) return head;
        while (head->left != nullptr) {
            head = head->left;
        }
        return head;
    }
    Node* deleted(Node* root,int value){
        if(root==nullptr) return root;
        if(value>root->data) root->right=deleted(root->right,value);
        else if(value<root->data) root->left=deleted(root->left,value);
        else{
            if(root->left==nullptr&&root->right==nullptr){
                delete root;
                return nullptr;
            }
            else if(root->left==nullptr){
                Node* temp=root->right;
                delete root;
                return temp;

            }
             else if(root->right==nullptr){
                Node* temp=root->left;
                delete root;
                return temp;
            }
            else{
                int temp=findnext(root);
                root->data=temp;
                root->right=deleted(root->right,temp);
            }

        }
        return root;
    }
    void deleteN(int value){
        root=deleted(root,value);
    }
    void vsi(Node* root,int h){
        if(root==nullptr) return;
        mp[h]=mp[h]+root->data;
        vsi(root->left,h-1);
        vsi(root->right,h+1);
    }
    void vvs(){
        vsi(root,0);
        for(auto i:mp){
            cout<<i.second<<" "<<endl;
        }
    }
    void bottomview(){
        if(root==nullptr) return;
        map<int,int> mp;
        queue<pair<Node*  ,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto[node, d]=q.front();
            q.pop();
            mp[d]=node->data;
            if(node->left)q.push({node->left,d-1});
            if(node->right) q.push({node->right,d+1});
        }
        for(auto i: mp){
            cout<<i.second<<" ";
        }
    }
    void bsttoll(Node* root){
        if(!root) return;
        bsttoll(root->left);
        LNode* temp=new LNode(root->data);
        curr->next=temp;
        curr=curr->next;
        bsttoll(root->right);
    }
    LNode* ll(){
        return head->next;
    }
    void traversal(Node* root,vector<int>&v,int val){
        if(root==nullptr) return;
        if(root->data==val) v.push_back(root->data);
        else if(val>root->data) traversal(root->right,v,val);
        else{
            traversal(root->left,v,val);
        }
        v.push_back(root->data);
    }
    int lca(Node* n1,Node* n2){
        vector<int> v1;
        vector<int> v2;
        traversal(root,v1,n1->data);  traversal(root,v2,n2->data);
    }
    int floor(int data){
        return floor_node(root,data);
    }
    int floor_node(Node* root,int val){
        Node* curr=root;
        int result;
        while(curr){
            if(val>curr->data){
                curr=curr->left;
            }
            else if(val<curr->data){
                result=curr->data;
                curr=curr->right;
            }
        }
        return result;
    }
};

int main(){
    BST b;
    b.add(10);
    b.add(5);
    b.add(3);
    b.add(40);
    b.add(50);
    b.add(6);
    b.add(30);
    b.printInOrder();
    //cout<<b.search(100)<<endl;
    b.vvs();
    
}