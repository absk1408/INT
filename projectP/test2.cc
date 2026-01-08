#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int s=0;
    vector<int> vec{2,2,1,1,1,2,2};
    for(int i=1;i<vec.size();i++){
        if(vec[i]!=vec[i-1]){
            s++;
        }
    }
    int count=0;
    for(auto x:vec){
        if(x==vec[s]){
            count++;
        }
    }
    if(count>vec.size()/2){
        cout<<vec[s]<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}