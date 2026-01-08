//ABHISHEK YADAV/absk1408
//#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
void pushin(string & line,vector<pair<string,int>>& vec){
    string key; int value;
    stringstream ss(line);
    ss >>key >> value;
    vec.push_back(make_pair(key,value));
}
void filewrite(vector<pair<string,int>> &vec){
    ofstream f("file.txt",ios::trunc);
    for(auto& x: vec){
        f<<x.first<<" "<<x.second<<endl;
    }
}
int main(){
    ifstream f("file.txt");
    vector<pair<string,int>>vec;
    string line;
    while(getline(f,line)){
        pushin(line,vec);
    }
    for(auto x:vec){
        cout<<x.first<<" "<<x.second<<endl;
    }
    f.close();
    cout<<"____"<<endl;
    sort(vec.begin(),vec.end(),[](const auto& a, const auto& b){return a.second>b.second;});

    for(auto x:vec){
        cout<<x.first<<" "<<x.second<<endl;
    }
    filewrite(vec);
    return 0;
}