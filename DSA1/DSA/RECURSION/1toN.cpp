//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#define loop(x,n) for(int i=x;i<n;i++)
//
using namespace std;

void rec(int n){
    if(n==0) return;
    rec(n-1);
    cout<<n<<" ";
}
int main(){
    rec(100);
   

}