//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
void powerset(int n,string str){
    int p=pow(n,2);
    for(int i=0;i<p;i++){
        string s="";
        for(int j=n-1;j>0;j--){
            if(i%2!=0){
                s=str[j]+s;
            }
        }
        cout<<s<<endl;
        s="";
    }

}
int main(){
    //
    return 0;
}