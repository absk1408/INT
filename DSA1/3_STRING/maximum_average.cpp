//#include<bits/stdc++.h>
// stoi string to integer 
#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
void studentRecord(vector<vector<string>> v1){
    int max=INT_MIN;
    string res;
    int n=v1.size();
    for(int i=0;i<n;i++){
        int avg=(stoi(v1[i][1])+stoi(v1[i][2])+stoi(v1[i][3]))/3;
        if(avg>max){
            max=avg;
            res=v1[i][0];
        }
    }
    cout<<res<<" "<<max;
}
//
int main(){
    vector<vector<string>>file = { {"Shrikanth", "20", "30" ,"10"}, {"Ram" ,"100", "50", "10"}};
    int N=file.size();
    studentRecord(file);
    return 0;
}