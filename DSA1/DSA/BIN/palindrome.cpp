//#include<bits/stdc++.h>
#include<iostream>
#include<deque>
using namespace std;
//
int main(){
    int x=0;
    deque<int>dq;
    if(x==0) dq.push_back(0);
    else{
        while(x>0){
            int r=x%10;
            dq.push_back(r);
            x=x/10;
        }
    }
    while(dq.size()>1){

        if(dq.front()!=dq.back()){
            cout<<"no";
            break;
        }
        dq.pop_back();
        dq.pop_front();
    }
    cout<<"yes";
    return 0;
}