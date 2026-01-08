//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<memory>
using namespace std;
//
int main(){
    int * ptr= new int(100);
    int *ptr2=ptr;
    *ptr2=900;
    cout<<*ptr<<endl;
////////////////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
    // to save from data inconsitency we use unique pointers
    unique_ptr<int> uptr=make_unique<int>(10);
    //unique_ptr<int> uptr2=uptr; //error
    unique_ptr<int> uptr2=move(uptr); //can transfer the ownership by smart pointer
    //cout<<*uptr<<endl; segmentation fault
    cout<<*uptr2<<endl; 
}