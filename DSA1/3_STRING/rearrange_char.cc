#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

string rearrangeString(string str) {
    unordered_map<char,int> hm;
    for(auto i:str) hm[i]++;
    string res="";
    priority_queue<pair<char,int>> q;
    for(auto [c,i]:hm){
        q.push({i,c});
    }
    pair<int,char> prev={-1,'#'};
    while(!q.empty()){
        auto [i,c]=q.top();
        q.pop();
        res+=c;
        if(prev.first>0)q.push(prev);
        prev={i-1,c};
    }
    if(prev.first>0) return "not possible";
    return res;    
}

int main() {
    string s = "aabbc";
    string rearranged = rearrangeString(s);
    if (!rearranged.empty())
        cout << "Rearranged String: " << rearranged << endl;
    else
        cout << "Not possible to rearrange" << endl;
    return 0;
}
