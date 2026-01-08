#include<iostream>
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
Node* recRev(Node* head){
    if(head==nullptr||head->next==nullptr) return head;
    Node* temp=recRev(head->next);
    head->next->next=head;
    head->next=nullptr;
    return temp; 
}
int main() 
{ 
	Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	printlist(head);
	head=recRev(head);
	printlist(head);
	return 0;
} 
