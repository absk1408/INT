//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<stack>
#define loop(x,n) for(int i=x;i<n;i++)
//
using namespace std;
int* span(int* arr,int n ){
    int *arr2=new int[n];
    for(int i=0;i<n;i++){
        int len=0;
        for(int j=i;j>=0;j--){
            if(arr[i]>=arr[j]){
                len++;
            }
            else{
                break;
            }
        }
        arr2[i]=len;
    }
    return arr2;
}
int* span2(int* arr,int n){
    stack<int> st;
    int* arr2=new int[n];
    loop(0,n){
        int len;
        while(!st.empty()&&arr[i]>=arr[st.top()]){
            st.pop();
        }
        if(st.empty()){
            len=i+1;
        }
        else{
            len=i-st.top();
        }
        arr2[i]=len;
        st.push(i);
    }
    return arr2;
}
int main(){
    int arr[10]={13,15,12,14,16,8,6,4,10,30};
    int *arr2=span2(arr,10);
    for(int i=0;i<10;i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;
    return 0;
}
