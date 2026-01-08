#include <iostream>
#include <vector>
#include<algorithm>
using namespace std; 
int main(){
   vector<int> id={210, 120, 123};
   vector<string> st={"apple","banana","cherry"};
   vector<pair<string,int>> vec;
   auto it=id.begin();
   auto it2=st.begin();
   while(it!=id.end()&&it2!=st.end()){
       vec.push_back(make_pair(*it2,*it));
       it2++;it++;
   }
   for(auto it1=vec.begin();it1!=vec.end();it1++ ){
        cout<<(*it1).first<<" "<<it1->second<<endl;
   }
   sort(vec.begin(),vec.end(),[](const auto& a,const pair<string,int>& b){return a.second>b.second; });
    cout<<"-------"<<endl;
    for(auto it1=vec.begin();it1!=vec.end();it1++ ){
            cout<<it1->first<<" "<<it1->second<<endl;
    }
    return 0;
}