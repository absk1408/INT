//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<stack>

#define loop(x,n) for(int i=x;i<n;i++)
//
using namespace std;
void prev(int* arr,int n){
    stack<int> st;
    loop(0,n){
        while(!st.empty()&&arr[i]>=st.top()) st.pop();
        if(st.empty()) cout<<-1<<" ";
        else cout<<st.top()<<" ";
        st.push(arr[i]);
    }
}
int main(){
    const int n=5;
    int arr[n]={20,30,10,5,15};
    prev(arr,n);
    return 0;
}
