//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<memory>
#include<cstdlib> //for malloc and free.
using namespace std;
//
int main(){
    int* ptr=(int*)malloc(sizeof(int));
    *ptr=100;
    cout<<*ptr<<endl;
    //unique_ptr<int> uptr(ptr);
    unique_ptr<int,void(*)(void*)> uptr(ptr,free); // to properly utilize " FREE"; 
    cout<<*uptr<<endl;
    free(ptr);  //double deletion
    return 0;
}