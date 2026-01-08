//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
//void print(){}
template<typename T, typename... Args>
/*void print(T first, Args... rest){
    //before c++17
    cout<<first<<" ";
    print(rest...);

}*/
//after c++17
void print(T first, Args... rest){
    cout<<first<<" ";
    if constexpr(sizeof...(rest)>0){
        print(rest...);
    }
}

int main(){
    const char* c="absk";
    string s="absk1408";
    print(1,2,3,"abhishek",'A',c,s);
}
