//#include<bits/stdc++.h>
#include<iostream>
//
using namespace std;
//
int main(){
    int x=0;
    int count=0;
    if(x==0) cout<<1<<endl;
    else{    while(x>0){
            x=x/10;
            count++;
        }
        cout<<count<<endl;
    }
    return 0;
}