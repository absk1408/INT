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
Node* sor_insert(Node* head,int val){
    Node* temp=new Node(val);
    if(head==nullptr) return temp;
    if(head->data>val){
        temp->next=head;
        return temp;
    }
    Node* curr=head;
    while(curr->next&& (curr->next->data)<=val){
        curr=curr->next;
    }
    temp->next=curr->next;
    curr->next=temp;
    return head;
}
int main(){
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    print(head);
    head=sor_insert(head,25);
    head=sor_insert(head,5);
    head=sor_insert(head,35);
    print(head);
    return 0;
}