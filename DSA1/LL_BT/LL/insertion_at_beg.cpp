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
Node* insertion(Node* &head,int x){
    Node* temp=new Node(x);
    temp->next=head;
    return temp;
}
int main(){
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    print(head);
    head=insertion(head,100);
    print(head);
    return 0;
}