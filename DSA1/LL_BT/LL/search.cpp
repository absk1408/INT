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
int srch(Node* head,int key,int pos){
    if(head==nullptr) return -1;
    if(head->data==key){
        return pos;
    }
    return srch(head->next,key,++pos);
}
int main(){
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    print(head);
    int k=srch(head,30,1);
    cout<<k<<endl;
    return 0;
}