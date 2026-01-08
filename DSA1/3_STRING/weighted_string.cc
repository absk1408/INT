//Given a number N, find the lexicographically smallest string such 
//that the sum of its character weights equals N.
//Character Weights: A=1, B=2, ..., Z=26
#include<iostream>
#include<algorithm>
using namespace std;
string lexo_small(int n,int sum){
    if(n>sum) return "";
    string str(n,'a');
    sum-=n;
    if(sum==0) return str;
    for(int i=n-1;i>=0;i--){
        sum+=1;
        if(sum>=26){
            str[i]='z';
            sum-=26;
        }
        else{
            str[i]=char('a'+(sum-1));
            break;
        }
    }
    return str;
}
int main()
{
    int n = 5, k = 42;
 
    string arr = lexo_small(n, k);
 
    cout << arr;
}
