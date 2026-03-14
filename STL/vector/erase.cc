#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> v = {10,20,30,40,50};
    auto it=v.erase(v.begin()+4); // it will return v.end() // UB // Wrong
    //auto it=v.erase(v.begin()+3);

    cout<<*it<<endl;

}