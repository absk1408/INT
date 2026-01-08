//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#define loop(x,n) for(int i=x;i<n;i++)
//
using namespace std;
struct Node{
    int data;
    Node *next;
    Node(int x){
        data=x;
        next=NULL;
    }
};
void print(Node *ll){
    while(ll!=NULL){
        cout<<ll->data<<" ";
        ll=ll->next;
    }
    cout<<endl;
}
Node* del(Node* h){
    if(h==NULL) return NULL;
    else if(h->next==NULL){
        return NULL;
    }
    Node* head=h;
    while(head->next!=nullptr&&head->next->next!=NULL){
        head=head->next;
    }
    Node* temp=head->next;
    head->next=nullptr;
    delete temp;
    return h;
}
int main(){
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    print(head);
    head=del(head);
    print(head);
    return 0;
}
//TC thete N