#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_set>
#include<vector>
using namespace std;
class efficiently{
    public:
    int ind=0; vector<int> vs; int sum=0;int s=0;int end=0;unordered_set<int> sm;
    void add_list(vector<int> v){
        for(int i=0;i<v.size();i++){
            vs.push_back(v[i]);
            if(vs.size()<3){
                sum+=vs[end];
                end++;
            }
            else if(vs.size()==3){
                sum+=vs[end];
                sm.insert(sum);
                end++;
            }
            else{
                sum-=vs[s];
                s++;
                sum+=vs[end];
                sm.insert(sum);
                end++;
            }
        }
    }
    bool sumthere(int sum){
        return (sm.find(sum)!=sm.end());   
    }
};