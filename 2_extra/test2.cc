//Input: digits = [1,2,3]
//Output: [1,2,4]
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void to_int(vector<int>& v,int len){
    int carry=1;
    bool flag=false;
    vector<int> res;
    for(int i=len-1;i>=0;i--){
        int sum=v[i]+carry;
        if(sum>9){
            carry=sum/10;
            res.push_back(sum%10);
        }
        else{
            carry=0;
            res.push_back(sum);
        }
    }
    if(carry>0){
        res.push_back(carry);
    }
    reverse(res.begin(),res.end());
    for(auto x:res){
        cout<<x<<" ";
    }
    
}

int main(){
    vector<int> v={9,9};
    int len=v.size();
    to_int(v,len);
  
    return 0;

}