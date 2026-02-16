//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<optional>
using namespace std;
int func(int a,int b){
    try{
        if(b==0){
            throw "bad division";
        }
        if(isalpha(a)){
            throw runtime_error("kya kar raha he");
        }
        return a*b;
        
    }
    catch(const char* msg){
        cout<<msg<<endl;
        return -1;
    }
    catch(const runtime_error &m){
        cout<<m.what()<<endl;
        return -2;
    }
}
int main(){
    cout<<func(4,0);
    cout<<func('a',1);
    

    return 0;
}