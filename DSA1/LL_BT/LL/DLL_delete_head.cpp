//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#define loop(x,n) for(int i=x;i<n;i++)
//
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int x){
        data=x;
        next=NULL;
        prev=NULL;
    }
};
void print(Node *ll){
    while(ll!=NULL){
        cout<<ll->data<<" ";
        ll=ll->next;
    }
    cout<<endl;
}
Node* del(Node* head){

    if(head==NULL) return NULL;
    if(head->next==NULL) {
        delete head;
        return NULL;
    }
    Node* temp=head;
    head=head->next;
    head->prev=NULL;
    delete temp;
    return head;
    
}
int main(){
    Node *head=new Node(10);
	Node *temp1=new Node(20);
	Node *temp2=new Node(30);
	head->next=temp1;
	temp1->prev=head;
	temp1->next=temp2;
	temp2->prev=temp1;
	head=del(head);
	print(head);
	return 0;
}
//TC O(n)