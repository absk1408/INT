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
class BST{
    public:
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
        if(!root) return nullptr; // return root
        if(value>root->data) root->right=deleted(root->right,value);
        else if(value<root->data) root->left=deleted(root->left,value);
        else{
            if(!root->left&&!root->right){
                delete root;
                return nullptr;
            }
            else if(!root->left){
                Node* temp=root->right;
                delete root;
                return temp;
            }
            else if(!root->right){
                Node* temp=root->left;
                delete root; return temp;
            }
            else{
                Node* next= findnextn(root->right);
                root->data=next->data;
                root->right=deleted(root->right,next->data);
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
    void leftsideview(){
        if(!root) return;
        map<int,int> mp;
        queue<pair<Node* ,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto[node,d]=q.front();
            q.pop();
            if(!mp.count(d)){
                mp[d]=node->data;
            }
            if(node->left)q.push({node->left,d+1});
            if(node->right)q.push({node->right,d+1});
        }
        for (auto i : mp) {
            cout << i.second << " ";
        }
    }
    bool childer_sum(Node* root){
        if(!root->right&&!root->left) return true;
        int val1=0;int val2=0;
        if(root->right)  val1=childer_sum(root->right);
        else if(!root->left) val2=childer_sum(root->right);
        return root->data==(val1+val2);
    }
    int check_bst(Node* root){
        if(!root) return 0;
        int val1=check_bst(root->left);
        if(val1==-1) return -1;
        int val2=check_bst(root->right);
        if(val2==-1) return -1;
        if(abs(val1-val2)>0) return -1;
        else{
            return (val1>val2)?val1+1:val2+1;
        }
        
    }
    int widthofBT(Node* root){
        queue<pair<Node*,int>>q;
        q.push({root,0}); int i=0;int res=0;
        while(!q.empty()){
            int x=q.size();
            res=max(res,x);
            while(!q.empty()&&q.front().second==i){
                auto[node,d]=q.front();
                if(node->right)q.push({node->right,d+1});
                if(node->left)q.push({node->left,d+1});
                q.pop();
            }
            i++;   
        }
        return res;
    }
    void bsttoll(Node* root){
        if(!root) return;
        bsttoll(root->left);
        LNode* temp=new LNode(root->data);
        curr->next=temp;
        curr=curr->next;
        bsttoll(root->right);
    }
    Node* prev1=nullptr;
    Node* toDLL(Node* root){
        if(!root) return root;
        Node* head1=toDLL(root->left);
        if(prev1==nullptr) head1=root;
        else{
            root->left=prev1;
            prev1->right=root;
        }
        prev1=root;
        toDLL(root->right);
        return head1;
    }
    LNode* ll(){
        return head->next;
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