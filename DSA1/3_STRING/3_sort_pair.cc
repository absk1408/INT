//ABHISHEK YADAV/absk1408
#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;
//
int main(){
    vector<pair<string,int>>vec;
    ifstream file("file.txt");
    string line;
    
    while(getline(file,line)){
        stringstream ss(line);
        string res;
        int num;
        if(ss>>res>>num){
            vec.push_back(make_pair(res,num));
        }
    }
    for(auto x:vec){
        cout<<x.first<<" "<<x.second<<endl;
    }
    sort(vec.begin(),vec.end(),[](auto &x, auto&y){
        if(x.second!=y.second)
            return x.second>y.second;
        else{
            return x.first<y.first;
        }
    });
    cout<<endl;
    for(auto x:vec){
        cout<<x.first<<" "<<x.second<<endl;
    }
    return 0;
}