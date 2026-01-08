//ABHISHEK YADAV/absk1408
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;
bool isvalidname(string s){
    size_t pos=s.find('^');
    if(pos!=string::npos){
        return true;
    }
    else{
        return false;
    }
}
vector<string> split(const string& s,char delimter){
    vector<string> v;
    string tokens;
    istringstream tokenstream(s);
    while(getline(tokenstream,tokens,delimter)){
        v.push_back(tokens);
    }
    return v;
}
int main(){
    string hl7 = "MSH|^~\\&|HIS|RIH|EKG|EKG|202507301530||ADT^A01|123456|P|2.3\r"
                 "PID|1||123456^^^RIH||DOE^JOHN||19700101|M|||123 Main St^^Metropolis^NY^10001||555-1234";
    vector<string>segments=split(hl7,'\r');
    vector<string>fields;
    for(auto c:segments){
        vector<string> temp=split(c,'|');
        fields.insert(fields.end(),temp.begin(),temp.end());
    }
    for(auto x:fields){
        cout<<x<<" ";
    }
    return 0;
}