//ABHISHEK YADAV/absk1408
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
void remove_par(string &s){
    string res=""; int counter=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            if(counter>0){
                res+='(';
            }
            counter++;
        }
        else{
            counter--;
            if(counter>0){
                res+=')';      
            }
        }
    }
  

}
int main(){
    //
    return 0;
}