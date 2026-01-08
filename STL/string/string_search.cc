//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
//
int main(){
    string s="abcdefdef";
    size_t pos=s.find("def"); //first occu
    cout<<pos<<endl;


    size_t pos2=s.rfind("def"); //last occur //if not there we got npos: random value
    cout<<pos2<<endl;

    size_t pos3=s.find("lm");
    cout<<pos3<<endl;
    

    
    if(pos3==string::npos) cout<<"not available"<<endl;
   
    
    return 0;
}