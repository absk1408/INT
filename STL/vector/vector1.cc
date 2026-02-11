//ABHISHEK YADAV/absk1408
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//
int main(){
    vector<int> v={10,20,30,40,50};
    v.erase(v.end());
    for(auto it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";

    }

    return 0;
}