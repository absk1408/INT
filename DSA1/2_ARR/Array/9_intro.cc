//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int* func(){
    int* arr=new int[50];  //dyanamic allocation.
    arr[20]=9999999;
    arr[10]=888888;
    return arr;
}
int main(){
    int *arr2;
    arr2=func();
    for(int i=0;i<50;i++){
        cout<<arr2[i]<<" ";
    }

    vector<int>v{1,2,3,4,5};
    v.erase(v.begin()+1,v.begin()+3);
    for(auto i:v){
        cout<<i<<" ";
    }

    return 0;
}