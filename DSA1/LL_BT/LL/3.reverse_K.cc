#include <iostream>
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

Node *reverseK(Node *head,int k){
    Node* new_head=nullptr;
    Node* r_prev=nullptr; 
    bool flag=true;
    Node* curr=head;
    while(curr){
        Node* prev=nullptr; Node* first=curr;
        for(int i=0;i<k&&curr;i++){
            Node* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        if(flag){
            new_head=prev;  // make the new head //only once
            flag=false;
        }
        else{
            r_prev->next=prev; // // add earlier saved last node to new head
        }
        r_prev=first; // always save the first node of k group
                        // because that going to be the last node of K group
    }
    return new_head;
}

int main() 
{ 
	Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	head->next->next->next=new Node(40);
	head->next->next->next->next=new Node(50);
	head->next->next->next->next->next=new Node(60);
	head->next->next->next->next->next->next=new Node(70);
	printlist(head);
	head=reverseK(head,2);
	printlist(head);
	return 0;
} 
