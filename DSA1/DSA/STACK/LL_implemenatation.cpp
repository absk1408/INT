//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#define loop(x,n) for(int i=x;i<n;i++)
//
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};
struct MyStack{
    Node* head;
    void push(int data){
        if(!head) head=new Node(data);
        else{
            Node* temp=head;
            head= new Node(data);
            head->next=temp;
        }
    }
    int pop(){
        if(!head) return -1;
        Node* temp=head;
        head=head->next;
        int data=temp->data;
        delete temp;
        return data;
    }
    
};

int main(){
    //
    return 0;
}