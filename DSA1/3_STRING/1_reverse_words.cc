#include<iostream>
#include<sstream>
#include<stack>
using namespace std;
string rev_words(const string & s){
    stack<string> st;
    stringstream ss(s);
    string res;string ans="";
    while(getline(ss,res,' ')){
        st.push(res);
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
        if(!st.empty()) ans+=" ";
    }
    return ans;
}

int main(){
    string s="TUF is great for interview preparation";
    cout<<"Before reversing words: "<<endl;
    cout<<s<<endl;
    string res=rev_words(s);
    cout<<"After reversing words: "<<endl;
    cout<<res;
    return 0;
}