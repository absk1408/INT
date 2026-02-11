//ABHISHEK YADAV/absk1408
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
//
int main(){
    set<pair<int,int>> st;
    st.insert(make_pair(20,100));
    st.insert(make_pair(10,300));
    st.insert(make_pair(130,200));
    st.insert(make_pair(20,900));
    //

    auto it=st.begin();
    auto[x,y]=*it;
    //////////////////////////////////
    cout<<x<<" "<<y<<endl;
    for(auto x:st){
        cout<<x.first<<" ";
    }
    return 0;
}