//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
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
int main(){
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    print(head);
    return 0;
}