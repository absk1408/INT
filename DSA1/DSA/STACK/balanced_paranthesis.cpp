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
        data=data;
        next=NULL;
    }
};
struct MyStack{
    Node* head;
    int sz;
    MyStack(){
        head=NULL;
        sz=0;
    }
    void push(int data){

    }
};
bool matching(char a,char b){
    return ((a=='('&&b==')')||(a=='['&&b==']')||(a=='{'&&b=='}'));
}
bool isBalanced(string &str){
    //stack;
    
    
}
int main(){
    string s="(({{}}))";

    return 0;
}