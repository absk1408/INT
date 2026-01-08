//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std; 
struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};
void printlist(Node *head){
    Node *curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }cout<<endl;
}
Node* reverse(Node* head){
   Node* prev = nullptr;
    Node* curr = head;

    while(curr != nullptr){
        Node* next = curr->next; // store next node
        curr->next = prev;       // reverse current link
        prev = curr;             // move prev ahead
        curr = next;             // move curr ahead
    }
    return prev; // new head
}
int main() 
{ 
	Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	printlist(head);
	head=reverse(head);
	printlist(head);
	return 0;
}