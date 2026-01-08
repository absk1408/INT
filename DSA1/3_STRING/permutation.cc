//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
void permutation(string& str,int l,int r){
    if(l==r){
        cout<<str<<endl;
        //return;
    }
    for(int i=l;i<=r;i++){
        swap(str[i],str[l]);  //swap interatively
        permutation(str,l+1,r); //stable l , send l+1 to perumte
        swap(str[i],str[l]); //back to original
    }
} 
int main(){
    string str="ABC";
    int r=str.length();
    permutation(str,0,r-1);
    return 0;
}