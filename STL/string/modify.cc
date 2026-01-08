//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
//
int main(){
    string s="abhishek";
    s.insert(5,"xxx");
    cout<<s<<endl;
    s.erase(5,3);
    cout<<s<<endl;
    s.replace(1,4,"x");
    cout<<s<<endl;
    s.replace(1,4,"xxxxxxxxxxxxx");
    cout<<s<<endl;
    //////
    string s1="abhishek";
    s1.insert(3,2,'s');
    //s1.insert(3,3,"abhi"); //error :create a new array then concatenate
    cout<<s1<<endl;
    ////
    string s3="abhishek";
    //s3.insert(4,'x'); //invalid
    s3.insert(4,"x");
    //
    s3.insert(4, string(1, 'y'));
    cout<<s3<<endl;


    return 0;
}