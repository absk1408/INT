//ABHISHEK YADAV/absk1408
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;
//
int main(){
    fstream file("file.txt");
    string s((istreambuf_iterator<char>(file)),istreambuf_iterator<char>());
    cout<<s<<endl;
    cout<<"-------"<<endl;
    stringstream ss(s); string st;
    while(getline(ss,st,' ')){
        cout<<st<<endl;
    }
    return 0;
}