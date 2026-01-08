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
Node* pos(Node* head,int data,int pos){
    Node* temp=new Node(data);
    if(pos==1){
        temp->next=head; return temp;
    }
    int jumps=pos-2;  //important
    Node* curr=head;
    while(jumps>0&&curr){
        curr=curr->next;jumps--;
    }
    if(curr==nullptr){
        delete temp;    
        return head;
    }
    Node* temp2=curr->next;
    curr->next=temp;
    temp->next=temp2;
    return head;
}
int main(){
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    print(head);
    head=pos(head,100,2);
    print(head);
    return 0;
}