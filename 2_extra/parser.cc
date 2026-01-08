#include<iostream>
#include<string>
#include<vector>
using namespace std;

static int counter=0;
string s_e(string& str){
    int s=0;int e=0;
    for(int i=0;i<str.length();i++){
        if(str[i]=='<'){
            s=i;
        }
        if(str[i]=='>'){
            e=i;
        }
        break;
    }
    int length=e-s+1;
    string result=str.substr(s,length);
    counter=e+1;
    return result;
}
int main(){
    vector<string>v;
    string str="+05B=123-";
    int tags=4;
    while(counter<str.length()&&tags--){
        string temp=s_e(str);
        v.push_back(temp);
    }
    return 0;
}