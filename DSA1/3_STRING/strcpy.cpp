//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
void func(const char* s){
    char* ss=new char[strlen(s)+1];
    strcpy(ss,s);
    for(int i=0;i<strlen(ss);i++){
        cout<<ss[i]<<endl;

    }

}
int main(){
    const char* a="abhishek";
    func(a);
    return 0;
}