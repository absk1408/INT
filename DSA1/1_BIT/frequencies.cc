//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
void print_freq(int arr[],int n){
    int a=arr[0];
    int frq=1;
    for(int i=1;i<n;i++){
        if(arr[i]==a){
            frq++;
        }
        else{   cout<<a<<" "<<frq<<endl;
        frq=1;
        a=arr[i];
        }
    }
    cout<<a<<" "<<frq;
} 
int main(){
    const int n=8;
    int arr[n]={10,10,10,30,30,40,40,40};
    print_freq(arr,n);
    return 0;
}